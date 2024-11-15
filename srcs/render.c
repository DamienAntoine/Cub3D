#include "../headers/cub.h"

int	key_press(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_Z)
		data->key_w = 1;
	else if (key == KEY_S)
		data->key_s = 1;
	else if (key == KEY_A || key == KEY_Q)
		data->key_a = 1;
	else if (key == KEY_D)
		data->key_d = 1;
	else if (key == ARROW_L)
		data->key_left = 1;
	else if (key == ARROW_R)
		data->key_right = 1;
	else if (key == KEY_ESC)
		close_win(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_Z)
		data->key_w = 0;
	else if (key == KEY_S)
		data->key_s = 0;
	else if (key == KEY_A || key == KEY_Q)
		data->key_a = 0;
	else if (key == KEY_D)
		data->key_d = 0;
	else if (key == ARROW_L)
		data->key_left = 0;
	else if (key == ARROW_R)
		data->key_right = 0;
	return (0);
}

int	close_win(t_data *data)
{
	free_img(data);
	free_resources(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	handle_controls(t_data *data)
{
	if (data->key_w)
		mv_fw(data);
	if (data->key_s)
		mv_bw(data);
	if (data->key_a)
		strafe_left(data);
	if (data->key_d)
		strafe_right(data);
	if (data->key_left)
		rotate_left(data);
	if (data->key_right)
		rotate_right(data);
}

int	render(t_data *data)
{
	handle_controls(data);
	if (data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	data->image.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->image.img)
		return (1);
	draw_floor_ceiling(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (0);
}
