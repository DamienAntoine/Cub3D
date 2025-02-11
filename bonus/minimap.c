/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:06:10 by sanhwang          #+#    #+#             */
/*   Updated: 2025/02/11 22:34:04 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	init_minimap(t_data *data)
{
	int	y;
	int	max_x;

	data->minimap.pos_x = 10;
	data->minimap.pos_y = 10;
	data->minimap.scale = 5;
	data->minimap.border = 1;
	data->minimap.show = 1;
	data->minimap.color = 0xFF00FF;
	data->minimap.plyr_color = 0xFFFF84;
	data->minimap.width = data->map_width / 20;
	data->minimap.height = data->map_height / 20;
	y = 0;
	max_x = 0;
	while (data->map[y])
	{
		if ((int)ft_strlen(data->map[y]) > max_x)
			max_x = ft_strlen(data->map[y]);
		y++;
	}
	data->minimap.width = data->map_width / 20;
	data->minimap.height = data->map_height / 20;
}

void	draw_square(t_data *data, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, data->minimap.color);
			j++;
		}
		i++;
	}
}

static void	draw_map_walls(t_data *data, int map_x, int map_y, int scale)
{
	int	x;
	int	y;

	y = 0;
	data->minimap.color = 0xFFFFFF;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_square(data, map_x + x * scale, map_y + y * scale, scale);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int	scale;
	int	map_x;
	int	map_y;

	if (!data->minimap.show)
		return ;
	scale = data->minimap.scale;
	map_x = data->minimap.pos_x;
	map_y = data->minimap.pos_y;
	data->minimap.color = 0x440004;
	draw_square(data, map_x - data->minimap.border, map_y
		- data->minimap.border, data->minimap.width + 2 * data->minimap.border);
	draw_map_walls(data, map_x, map_y, scale);
	data->minimap.color = data->minimap.plyr_color;
	draw_square(data, map_x + (int)(data->ray.pos_x * scale), map_y
		+ (int)(data->ray.pos_y * scale), 5);
}
