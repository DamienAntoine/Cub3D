#include "../headers/cub.h"

void	cast_rays(t_data *data)
{
	int		x;
	double	ray_dir_x;
	double	rary_dir_y;
	double	perp_wall_dist;
	t_dda	dda;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		//printf("Player position: (%f,%f)\n", data->ray.pos_x, data->ray.pos_y);
		//printf("Player direction: (%f,%f)\n", data->ray.dir_x, data->ray.dir_y);
		calculate_ray(data, x, &ray_dir_x, &rary_dir_y);
		init_dda(ray_dir_x, rary_dir_y, data, &dda);
		calculate_step(&dda, ray_dir_x, rary_dir_y, data);
		perform_dda(data, &dda);
		if (dda.side == 0)
			perp_wall_dist = (dda.side_dist_x - dda.delta_dist_x);
		else
			perp_wall_dist = (dda.side_dist_y - dda.delta_dist_y);
		draw_wall(data, &dda, x, perp_wall_dist);
		x++;
	}
}
