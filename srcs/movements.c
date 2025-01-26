/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:31 by dantoine          #+#    #+#             */
/*   Updated: 2025/01/26 03:57:46 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	mv_fw(t_data *data)
{
	double	new_x;
	double	new_y;
	int		map_width;
	int		map_height;

	new_x = data->ray.pos_x + data->ray.dir_x * data->ray.move_speed;
	new_y = data->ray.pos_y + data->ray.dir_y * data->ray.move_speed;
	map_width = ft_strlen(data->map[0]);
	map_height = 0;
	while (data->map[map_height])
		map_height++;
	if (new_x < 0 || new_y < 0 || (int)new_x >= map_width
		|| (int)new_y >= map_height)
		return ;
	if (data->map[(int)(data->ray.pos_y)][(int)(new_x)] == '0'
		|| ft_strchr("NSEW", data->map[(int)(data->ray.pos_y)][(int)(new_x)]))
		data->ray.pos_x = new_x;
	if (data->map[(int)(new_y)][(int)(data->ray.pos_x)] == '0'
		|| ft_strchr("NSEW", data->map[(int)(new_y)][(int)(data->ray.pos_x)]))
		data->ray.pos_y = new_y;
}

void	mv_bw(t_data *data)
{
	double	new_x;
	double	new_y;
	int		map_width;
	int		map_height;

	new_x = data->ray.pos_x - data->ray.dir_x * data->ray.move_speed;
	new_y = data->ray.pos_y - data->ray.dir_y * data->ray.move_speed;
	map_width = ft_strlen(data->map[0]);
	map_height = 0;
	while (data->map[map_height])
		map_height++;
	if (new_x < 0 || new_y < 0 || (int)new_x >= map_width
		|| (int)new_y >= map_height)
		return ;
	if (data->map[(int)(data->ray.pos_y)][(int)(new_x)] == '0'
		|| ft_strchr("NSEW", data->map[(int)(data->ray.pos_y)][(int)(new_x)]))
		data->ray.pos_x = new_x;
	if (data->map[(int)(new_y)][(int)(data->ray.pos_x)] == '0'
		|| ft_strchr("NSEW", data->map[(int)(new_y)][(int)(data->ray.pos_x)]))
		data->ray.pos_y = new_y;
}

void	strafe_right(t_data *data)
{
	double	new_x;
	double	new_y;
	int		map_width;
	int		map_height;

	new_x = data->ray.pos_x - data->ray.dir_y * data->ray.move_speed;
	new_y = data->ray.pos_y + data->ray.dir_x * data->ray.move_speed;
	map_width = ft_strlen(data->map[0]);
	map_height = 0;
	while (data->map[map_height])
		map_height++;
	if (new_x < 0 || new_y < 0 || (int)new_x >= map_width
		|| (int)new_y >= map_height)
		return ;
	if (data->map[(int)(data->ray.pos_y)][(int)(new_x)] == '0'
		|| ft_strchr("NSEW", data->map[(int)(data->ray.pos_y)][(int)(new_x)]))
		data->ray.pos_x = new_x;
	if (data->map[(int)(new_y)][(int)(data->ray.pos_x)] == '0'
		|| ft_strchr("NSEW", data->map[(int)(new_y)][(int)(data->ray.pos_x)]))
		data->ray.pos_y = new_y;
}

void	strafe_left(t_data *data)
{
	double	new_x;
	double	new_y;
	int		map_width;
	int		map_height;

	new_x = data->ray.pos_x + data->ray.dir_y * data->ray.move_speed;
	new_y = data->ray.pos_y - data->ray.dir_x * data->ray.move_speed;
	map_width = ft_strlen(data->map[0]);
	map_height = 0;
	while (data->map[map_height])
		map_height++;
	if (new_x < 0 || new_y < 0 || (int)new_x >= map_width
		|| (int)new_y >= map_height)
		return ;
	if (data->map[(int)(data->ray.pos_y)][(int)(new_x)] == '0'
		|| ft_strchr("NSEW", data->map[(int)(data->ray.pos_y)][(int)(new_x)]))
		data->ray.pos_x = new_x;
	if (data->map[(int)(new_y)][(int)(data->ray.pos_x)] == '0'
		|| ft_strchr("NSEW", data->map[(int)(new_y)][(int)(data->ray.pos_x)]))
		data->ray.pos_y = new_y;
}
