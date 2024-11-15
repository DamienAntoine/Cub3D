#include "../headers/cub.h"

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	// rotate direction
	old_dir_x = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(data->ray.rotate_speed)
		- data->ray.dir_y * sin(data->ray.rotate_speed);
	data->ray.dir_y = old_dir_x * sin(data->ray.rotate_speed) + data->ray.dir_y
		* cos(data->ray.rotate_speed);
	// rotate cam
	old_plane_x = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(data->ray.rotate_speed)
		- data->ray.plane_y * sin(data->ray.rotate_speed);
	data->ray.plane_y = old_plane_x * sin(data->ray.rotate_speed)
		+ data->ray.plane_y * cos(data->ray.rotate_speed);
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	// rotate direction
	old_dir_x = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rotate_speed)
		- data->ray.dir_y * sin(-data->ray.rotate_speed);
	data->ray.dir_y = old_dir_x * sin(-data->ray.rotate_speed) + data->ray.dir_y
		* cos(-data->ray.rotate_speed);
	// rotate cam
	old_plane_x = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rotate_speed)
		- data->ray.plane_y * sin(-data->ray.rotate_speed);
	data->ray.plane_y = old_plane_x * sin(-data->ray.rotate_speed)
		+ data->ray.plane_y * cos(-data->ray.rotate_speed);
}
