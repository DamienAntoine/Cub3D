/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:54:28 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/11 22:50:30 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(data->ray.rotate_speed)
		- data->ray.dir_y * sin(data->ray.rotate_speed);
	data->ray.dir_y = old_dir_x * sin(data->ray.rotate_speed) + data->ray.dir_y
		* cos(data->ray.rotate_speed);
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

	old_dir_x = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rotate_speed)
		- data->ray.dir_y * sin(-data->ray.rotate_speed);
	data->ray.dir_y = old_dir_x * sin(-data->ray.rotate_speed) + data->ray.dir_y
		* cos(-data->ray.rotate_speed);
	old_plane_x = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rotate_speed)
		- data->ray.plane_y * sin(-data->ray.rotate_speed);
	data->ray.plane_y = old_plane_x * sin(-data->ray.rotate_speed)
		+ data->ray.plane_y * cos(-data->ray.rotate_speed);
}
