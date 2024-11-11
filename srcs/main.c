#include "../headers/cub.h"

static void	init_data(t_data *data)
{
	data->win_w = ft_strlen(data->map[0]);
	data->win_h = map_height(data->map);
	data->mlx = mlx_init();
	data->image.img = mlx_new_image(data->mlx, data->win_w * 50,
									data->win_h * 50);
	if (data->image.img)
		data->image.addr = mlx_get_data_addr(data->image.img,
				&data->image.bits_p_pxl, &data->image.line_length,
				&data->image.endian);
	data->win = NULL;

	data->ray.posX = 22.0;
	data->ray.posY = 12.0;
	data->ray.dirX = -1.0;
	data->ray.dirY = 0.0;
	data->ray.planeX = 0.0;
	data->ray.planeY = 0.66;
	data->ray.move_speed = 0.1;
	data->ray.rotate_speed = 0.1;
}

void	free_resources(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	if (data->image.img)
	{
		mlx_destroy_image(data->mlx, data->image.img);
		data->image.img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

int	controls(int key, t_data *data)
{
	if (key == ARROW_R)
		rotate_right(data);
	else if (key == ARROW_L)
		rotate_left(data);
	else if (key == KEY_W)
		mv_fw(data);
	else if (key == KEY_S)
		mv_bw(data);
	else if (key == KEY_A)
		strafe_l(data);
	else if (key == KEY_D)
		strafe_r(data);
	else if (key == KEY_ESC)
		close_win(data);
	return (0);
}

int	close_win(t_data *data)
{
	free_images(data);
	free_resources(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_images(t_data *data)
{
	if (data->image.img)
	{
		mlx_destroy_image(data->mlx, data->image.img);
		data->image.img = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		perror("Error: Not enough arguments");
		return (1);
	}
	check_file(argv[1]);
	data.map = parse_map(argv[1]);
	if (data.map != NULL)
	{
		check_map(&data);
		init_data(&data);
		data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
				"SO_LONG");
		if (!data.win)
		{
			free_resources(&data);
			return (1);
		}
		//
		mlx_hook(data.win, 2, (1L << 0), controls, &data);
		mlx_hook(data.win, 17, (1L << 0), close_win, &data);
		mlx_string_put(data.mlx, data.win, 5, 10, 0xffffff, "Move: 0");
		mlx_loop(data.mlx);
	}
	free_resources(&data);
	return (0);
}
