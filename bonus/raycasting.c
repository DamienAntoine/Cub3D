/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:54:21 by dantoine          #+#    #+#             */
/*   Updated: 2025/01/26 22:51:11 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

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
