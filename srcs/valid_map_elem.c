/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:54:54 by dantoine          #+#    #+#             */
/*   Updated: 2025/01/26 03:57:57 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	get_map_dimensions(t_data *data, int *height, int *max_width)
{
	int	line_len;

	*height = 0;
	*max_width = 0;
	while (data->map[*height])
	{
		line_len = ft_strlen(data->map[*height]);
		if (line_len > *max_width)
			*max_width = line_len;
		(*height)++;
	}
}

static void	check_walls_around(t_data *data, int y, int x)
{
	if (y == 0 || x >= ft_strlen(data->map[y - 1]) || data->map[y - 1][x] == ' '
		|| !data->map[y - 1][x])
	{
		printf("Error: Map must be enclosed by walls (top)\n");
		exit(1);
	}
	if (!data->map[y + 1] || x >= ft_strlen(data->map[y + 1]) \
		|| data->map[y + 1][x] == ' ' || !data->map[y + 1][x])
	{
		printf("Error: Map must be enclosed by walls (bottom)\n");
		exit(1);
	}
	if (x == 0 || data->map[y][x - 1] == ' ')
	{
		printf("Error: Map must be enclosed by walls (left)\n");
		exit(1);
	}
	if (!data->map[y][x + 1] || data->map[y][x + 1] == ' ')
	{
		printf("Error: Map must be enclosed by walls (right)\n");
		exit(1);
	}
}

static void	check_invalid_char(t_data *data, int y, int x)
{
	if (data->map[y][x] != '0' && data->map[y][x] != '1'
		&& data->map[y][x] != 'N' && data->map[y][x] != 'S'
		&& data->map[y][x] != 'E' && data->map[y][x] != 'W'
		&& data->map[y][x] != ' ')
	{
		printf("Error: Invalid character in map\n");
		exit(1);
	}
	if (data->map[y][x] == '0' || ft_strchr("NSEW", data->map[y][x]))
		check_walls_around(data, y, x);
}

void	validate_map_elements(t_data *data)
{
	int	y;
	int	x;
	int	height;
	int	max_width;

	get_map_dimensions(data, &height, &max_width);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == ' ')
			{
				x++;
				continue ;
			}
			check_invalid_char(data, y, x);
			x++;
		}
		y++;
	}
}
