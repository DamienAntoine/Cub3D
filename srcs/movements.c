#include "../headers/cub.h"

void	mv_bw(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->ray.pos_x - data->ray.dir_x * data->ray.move_speed;
	new_y = data->ray.pos_y - data->ray.dir_y * data->ray.move_speed;
	// check walls before moving
	if (new_x < 0 || new_y < 0 || (int)new_x >= MAP_WIDTH
		|| (int)new_y >= MAP_HEIGHT)
		return ;
	// check X movement
	if (data->map[(int)(data->ray.pos_y)][(int)(new_x)] == '0')
		data->ray.pos_x = new_x;
	// check Y movement
	if (data->map[(int)(new_y)][(int)(data->ray.pos_x)] == '0')
		data->ray.pos_y = new_y;
}

void	mv_fw(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->ray.pos_x + data->ray.dir_x * data->ray.move_speed;
	new_y = data->ray.pos_y + data->ray.dir_y * data->ray.move_speed;
	if (new_x < 0 || new_y < 0 || (int)new_x >= MAP_WIDTH
		|| (int)new_y >= MAP_HEIGHT)
		return ;
	if (data->map[(int)(data->ray.pos_y)][(int)(new_x)] == '0')
		data->ray.pos_x = new_x;
	if (data->map[(int)(new_y)][(int)(data->ray.pos_x)] == '0')
		data->ray.pos_y = new_y;
}

void	strafe_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->ray.pos_x - data->ray.dir_y * data->ray.move_speed;
	new_y = data->ray.pos_y + data->ray.dir_x * data->ray.move_speed;
	if (new_x < 0 || new_y < 0 || (int)new_x >= MAP_WIDTH
		|| (int)new_y >= MAP_HEIGHT)
		return ;
	if (data->map[(int)(data->ray.pos_y)][(int)(new_x)] == '0')
		data->ray.pos_x = new_x;
	if (data->map[(int)(new_y)][(int)(data->ray.pos_x)] == '0')
		data->ray.pos_y = new_y;
}

void	strafe_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->ray.pos_x + data->ray.dir_y * data->ray.move_speed;
	new_y = data->ray.pos_y - data->ray.dir_x * data->ray.move_speed;
	if (new_x < 0 || new_y < 0 || (int)new_x >= MAP_WIDTH
		|| (int)new_y >= MAP_HEIGHT)
		return ;
	if (data->map[(int)(data->ray.pos_y)][(int)(new_x)] == '0')
		data->ray.pos_x = new_x;
	if (data->map[(int)(new_y)][(int)(data->ray.pos_x)] == '0')
		data->ray.pos_y = new_y;
}
