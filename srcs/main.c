#include "../headers/cub.h"

static int initialize_textures(t_data *data)
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
	data->ray.pos_x = 22.0;
	data->ray.pos_y = 12.0;
	data->ray.dir_x = -1.0;
	data->ray.dir_y = 0.0;
	data->ray.plane_x = 0.0;
	data->ray.plane_y = 0.66;
	data->ray.move_speed = 0.1;
	data->ray.rotate_speed = 0.1;
	initialize_textures(data);
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
		strafe_left(data);
	else if (key == KEY_D)
		strafe_right(data);
	else if (key == KEY_ESC)
		close_win(data);
	return (0);
}

int	close_win(t_data *data)
{
	free_img(data);
	free_resources(data);
	exit(EXIT_SUCCESS);
	return (0);
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
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!data.win)
		exit_error("Window creation failed");
	mlx_hook(data.win, 2, (1L << 0), controls, &data);
	mlx_hook(data.win, 17, (1L << 0), close_win, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
