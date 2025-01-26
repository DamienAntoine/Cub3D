/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_plyr_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:54:58 by dantoine          #+#    #+#             */
/*   Updated: 2025/01/26 03:57:56 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	set_north_south_direction(t_data *data, char dir)
{
	data->ray.dir_x = 0;
	if (dir == 'N')
	{
		data->ray.dir_y = -1;
		data->ray.plane_x = 0.66;
	}
	else
	{
		data->ray.dir_y = 1;
		data->ray.plane_x = -0.66;
	}
	data->ray.plane_y = 0;
}

static void	set_east_west_direction(t_data *data, char dir)
{
	data->ray.plane_y = 0;
	if (dir == 'E')
	{
		data->ray.dir_x = 1;
		data->ray.plane_y = 0.66;
	}
	else
	{
		data->ray.dir_x = -1;
		data->ray.plane_y = -0.66;
	}
	data->ray.dir_y = 0;
	data->ray.plane_x = 0;
}

static void	set_player_direction(t_data *data, int x, int y, char dir)
{
	data->ray.pos_x = x + 0.5;
	data->ray.pos_y = y + 0.5;
	if (dir == 'N' || dir == 'S')
		set_north_south_direction(data, dir);
	else if (dir == 'E' || dir == 'W')
		set_east_west_direction(data, dir);
}

void	validate_player_position(t_data *data)
{
	int	player_count;
	int	y;
	int	x;

	player_count = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				player_count++;
				set_player_direction(data, x, y, data->map[y][x]);
			}
		}
	}
	if (player_count != 1)
	{
		printf("Error: Map must contain exactly one player position \
        (N,S,E,W)\n");
		exit(1);
	}
}
