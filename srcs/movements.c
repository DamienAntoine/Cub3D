#include "../headers/cub.h"

void	mv_fw(t_data *data)
{
	// check X collisions
	if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX + data->ray.dirX
			* data->ray.move_speed)] == '0')
		data->ray.posX += data->ray.dirX * data->ray.move_speed; // move
	if (data->map[(int)(data->ray.posY + data->ray.dirY
			* data->ray.move_speed)][(int)(data->ray.posX)] == '0')
		data->ray.posY += data->ray.dirY * data->ray.move_speed;
}

void	mv_bw(t_data *data)
{
	// check X collisions
	if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX - data->ray.dirX
			* data->ray.move_speed)] == '0')
		data->ray.posX -= data->ray.dirX * data->ray.move_speed; // move
	if (data->map[(int)(data->ray.posY - data->ray.dirY
			* data->ray.move_speed)][(int)(data->ray.posX)] == '0')
		data->ray.posY -= data->ray.dirY * data->ray.move_speed;
}

void	strafe_left(t_data *data)
{
	// Move perpendicular to direction vector (90° counter-clockwise)
	if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX - data->ray.dirY
			* data->ray.move_speed)] == '0')
	{
		data->ray.posX -= data->ray.dirY * data->ray.move_speed;
	}
	if (data->map[(int)(data->ray.posY + data->ray.dirX
			* data->ray.move_speed)][(int)(data->ray.posX)] == '0')
	{
		data->ray.posY += data->ray.dirX * data->ray.move_speed;
	}
}

void	strafe_right(t_data *data)
{
	// Move perpendicular to direction vector (90° clockwise)
	if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX + data->ray.dirY
			* data->ray.move_speed)] == '0')
	{
		data->ray.posX += data->ray.dirY * data->ray.move_speed;
	}
	if (data->map[(int)(data->ray.posY - data->ray.dirX
			* data->ray.move_speed)][(int)(data->ray.posX)] == '0')
	{
		data->ray.posY -= data->ray.dirX * data->ray.move_speed;
	}
}

void	rotate_left(t_data *data)
{
	double	oldDirX;
	double	oldPlaneX;

	// rotate direction
	oldDirX = data->ray.dirX;
	data->ray.dirX = data->ray.dirX * cos(data->ray.rotate_speed)
		- data->ray.dirY * sin(data->ray.rotate_speed);
	data->ray.dirY = oldDirX * sin(data->ray.rotate_speed) + data->ray.dirY
		* cos(data->ray.rotate_speed);
	// rotate cam
	oldPlaneX = data->ray.planeX;
	data->ray.planeX = data->ray.planeX * cos(data->ray.rotate_speed)
		- data->ray.planeY * sin(data->ray.rotate_speed);
	data->ray.planeY = oldPlaneX * sin(data->ray.rotate_speed)
		+ data->ray.planeY * cos(data->ray.rotate_speed);
}

void	rotate_right(t_data *data)
{
	double	oldDirX;
	double	oldPlaneX;

	// rotate direction
	oldDirX = data->ray.dirX;
	data->ray.dirX = data->ray.dirX * cos(-data->ray.rotate_speed)
		- data->ray.dirY * sin(-data->ray.rotate_speed);
	data->ray.dirY = oldDirX * sin(-data->ray.rotate_speed) + data->ray.dirY
		* cos(-data->ray.rotate_speed);
	// rotate cam
	oldPlaneX = data->ray.planeX;
	data->ray.planeX = data->ray.planeX * cos(-data->ray.rotate_speed)
		- data->ray.planeY * sin(-data->ray.rotate_speed);
	data->ray.planeY = oldPlaneX * sin(-data->ray.rotate_speed)
		+ data->ray.planeY * cos(-data->ray.rotate_speed);
}
