#include "../headers/cub.h"

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	mid_height;
	int	*img_data;

	img_data = (int *)mlx_get_data_addr(data->image.img,
			&data->image.bits_p_pxl, &data->image.line_length,
			&data->image.endian);
	mid_height = WINDOW_HEIGHT / 2;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < mid_height)
				img_data[y * WINDOW_WIDTH + x] = data->ceiling_color;
			else
				img_data[y * WINDOW_WIDTH + x] = data->floor_color;
			x++;
		}
		y++;
	}
}
