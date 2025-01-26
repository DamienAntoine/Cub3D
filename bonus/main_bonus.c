int	main(int argc, char **argv)
{
	t_data data;

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
	init_map_size(&data);
	check_map(&data);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cub3D Bonus");
	if (!data.win)
		exit_error("Window creation failed");

	// Additional hooks for bonus features
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 17, (1L << 0), close_win, &data);
	mlx_hook(data.win, 6, 1L << 6, handle_mouse, &data); // Mouse movement
	mlx_loop_hook(data.mlx, render_bonus, &data);       
		// Bonus render function
	mlx_loop(data.mlx);
	return (0);
}