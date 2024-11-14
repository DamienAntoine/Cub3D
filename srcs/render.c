#include "../headers/cub.h"

int	render(t_data *data)
{
	if (data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	data->image.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->image.img)
		return (1);
	draw_floor_ceiling(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
	return (0);
}
