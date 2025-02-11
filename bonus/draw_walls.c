/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:06 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/11 22:49:41 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static void	init_wall_draw(int *line_height, int *draw_start, int *draw_end,
		double perp_wall_dist)
{
	*line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);
	*draw_start = -(*line_height) / 2 + WINDOW_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = (*line_height) / 2 + WINDOW_HEIGHT / 2;
	if (*draw_end >= WINDOW_HEIGHT)
		*draw_end = WINDOW_HEIGHT - 1;
}

static void	get_wall_texture(t_wall_calc *calc, t_dda *dda, t_data *data)
{
	if (dda->side == 0)
	{
		if (dda->step_x > 0)
			*calc->texture = &data->west;
		else
			*calc->texture = &data->east;
	}
	else
	{
		if (dda->step_y > 0)
			*calc->texture = &data->north;
		else
			*calc->texture = &data->south;
	}
	if (dda->side == 0)
		*calc->wall_x = data->ray.pos_y + calc->perp_wall_dist * dda->ray_dir_y;
	else
		*calc->wall_x = data->ray.pos_x + calc->perp_wall_dist * dda->ray_dir_x;
	*calc->wall_x -= floor(*calc->wall_x);
}

static int	get_tex_x(double wall_x, t_texture *texture, t_dda *dda)
{
	int	tex_x;

	tex_x = (int)(wall_x * texture->width);
	if (dda->side == 0 && dda->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static void	draw_wall_line(t_data *data, t_texture *texture, int tex_x,
		t_wall_data *wall)
{
	int		y;
	int		tex_y;
	double	tex_pos;
	int		color;
	double	step;

	step = 1.0 * texture->height / wall->line_height;
	tex_pos = (wall->draw_start - WINDOW_HEIGHT / 2 + wall->line_height / 2)
		* step;
	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = *(int *)(texture->addr + (tex_y * texture->line_length + tex_x
					* (texture->bits_per_pixel / 8)));
		my_mlx_pixel_put(data, wall->x, y, color);
		y++;
	}
}

void	draw_wall(t_data *data, t_dda *dda, int x, double perp_wall_dist)
{
	t_texture	*texture;
	double		wall_x;
	t_wall_data	wall;
	t_wall_calc	calc;
	int			tex_x;

	wall.x = x;
	init_wall_draw(&wall.line_height, &wall.draw_start, &wall.draw_end,
		perp_wall_dist);
	calc.texture = &texture;
	calc.wall_x = &wall_x;
	calc.perp_wall_dist = perp_wall_dist;
	get_wall_texture(&calc, dda, data);
	tex_x = get_tex_x(wall_x, texture, dda);
	draw_wall_line(data, texture, tex_x, &wall);
}
