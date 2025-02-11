/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:21:17 by sanhwang          #+#    #+#             */
/*   Updated: 2025/02/11 22:37:32 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

#include "cub3d.h"

#ifdef BONUS
typedef struct s_minimap
{
	int			pos_x;
	int			pos_y;
	int			scale;
	int			border;
	int			show;
	int			width;
	int			height;
	int			color;
	int			plyr_color;
}				t_minimap;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	char		**map;
	int			map_width;
	int			map_height;
	int			floor_color;
	int			ceiling_color;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_ray		ray;
	t_img		image;
	t_minimap	minimap;
	t_tokens	*tokens;
}				t_data;

// minimap.c
void			init_minimap(t_data *data);
void			draw_minimap(t_data *data);
void			draw_square(t_data *data, int x, int y, int size);
#endif

#endif