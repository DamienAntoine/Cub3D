#include "../headers/cub.h"

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
	init_data(&data);
	check_file(argv[1]);
	parse_config(&data, argv[1]);
	data.map = parse_map(argv[1]);
	if (!data.map)
		exit_error("Error: Map parsing failed");
	check_map(&data);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!data.win)
		exit_error("Window creation failed");
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 17, (1L << 0), close_win, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
