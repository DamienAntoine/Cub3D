#include "../headers/cub.h"

void	calculate_ray(t_data *data, int x, double *ray_dir_x,
		double *rary_dir_y)
{
	double	cam_x;

	cam_x = 2 * x / (double)WINDOW_WIDTH - 1;
	*ray_dir_x = data->ray.dir_x + data->ray.plane_x * cam_x;
	*rary_dir_y = data->ray.dir_y + data->ray.plane_y * cam_x;
}

void	init_dda(double ray_dir_x, double rary_dir_y, t_data *data, t_dda *dda)
{
	double	delta_dist_x;
	double	delta_dist_y;

	delta_dist_x = fabs(1 / ray_dir_x);
	delta_dist_y = fabs(1 / rary_dir_y);
	dda->map_x = (int)data->ray.pos_x;
	dda->map_y = (int)data->ray.pos_y;
	dda->delta_dist_x = delta_dist_x;
	dda->delta_dist_y = delta_dist_y;
}

void	calculate_step(t_dda *dda, double ray_dir_x, double rary_dir_y,
		t_data *data)
{
	double	side_dist_x;
	double	side_dist_y;

	if (ray_dir_x < 0)
	{
		dda->step_x = -1;
		side_dist_x = (data->ray.pos_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		side_dist_x = (dda->map_x + 1.0 - data->ray.pos_x) * dda->delta_dist_x;
	}
	if (rary_dir_y < 0)
	{
		dda->step_y = -1;
		side_dist_y = (data->ray.pos_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		side_dist_y = (dda->map_y + 1.0 - data->ray.pos_y) * dda->delta_dist_y;
	}
	dda->side_dist_x = side_dist_x;
	dda->side_dist_y = side_dist_y;
}

void	perform_dda(t_data *data, t_dda *dda)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			side = 1;
		}
		if (dda->map_x < 0 || dda->map_y < 0 || dda->map_x >= MAP_WIDTH
			|| dda->map_y >= MAP_HEIGHT || data->map[dda->map_y] == NULL)
		{
			hit = 1;
			break ;
		}
		if (data->map[dda->map_y][dda->map_x] == '1')
			hit = 1;
	}
	dda->side = side;
}

void	draw_wall(t_data *data, t_dda *dda, int x, double perp_wall_dist)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	y;
	int	color;
	int	*img_data;

	img_data = (int *)mlx_get_data_addr(data->image.img,
			&data->image.bits_p_pxl, &data->image.line_length,
			&data->image.endian);
	line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	if (dda->side == 1)
		color = 0x00800000;
	else
		color = 0x00FF0000;
	y = draw_start;
	while (y < draw_end)
	{
		img_data[y * WINDOW_WIDTH + x] = color;
		y++;
	}
}
