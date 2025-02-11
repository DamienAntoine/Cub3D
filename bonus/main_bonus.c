/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:18 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/11 22:34:11 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static int	initialize_textures(t_data *data)
{
	data->north.img = NULL;
	data->north.path = NULL;
	data->south.img = NULL;
	data->south.path = NULL;
	data->east.img = NULL;
	data->east.path = NULL;
	data->west.img = NULL;
	data->west.path = NULL;
	return (0);
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_error("MLX initialization failed");
	data->win = NULL;
	data->map = NULL;
	data->image.img = NULL;
	data->image.addr = NULL;
	data->ray.move_speed = 0.025;
	data->ray.rotate_speed = 0.05;
	initialize_textures(data);
}

void	init_map_size(t_data *data)
{
	int	line_len;

	data->map_height = 0;
	data->map_width = 0;
	while (data->map[data->map_height])
	{
		line_len = ft_strlen(data->map[data->map_height]);
		if (line_len > data->map_width)
			data->map_width = line_len;
		data->map_height++;
	}
}

void	print_usage(void)
{
	printf("Usage: ./cub3D <path_to_map.cub>\n");
	printf("Example: ./cub3D maps/map.cub\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_usage();
		exit_error("Error: Wrong number of arguments");
	}
	check_file(argv[1]);
	init_data(&data);
	parse_config(&data, argv[1]);
	data.map = parse_map(argv[1]);
	if (!data.map)
		free_and_exit(&data, "Error: Map parsing failed");
	init_map_size(&data);
	check_map(&data);
	init_minimap(&data);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!data.win)
		free_and_exit(&data, "Window creation failed");
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 17, (1L << 0), close_win, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
