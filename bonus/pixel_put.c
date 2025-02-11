/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:54:13 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/11 22:50:20 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data || !data->image.addr || x < 0 || y < 0 || x >= WINDOW_WIDTH
		|| y >= WINDOW_HEIGHT)
		return ;
	dst = data->image.addr + (y * data->image.line_length + x
			* (data->image.bits_p_pxl / 8));
	*(unsigned int *)dst = color;
}
