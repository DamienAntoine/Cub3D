#include "../headers/cub.h"

void	free_img(t_data *data)
{
	if (data->image.img)
	{
		mlx_destroy_image(data->mlx, data->image.img);
		data->image.img = NULL;
	}
}

void	free_map(t_data *data)
{
	int	i;

	if (data->map)
	{
		i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void	free_win(t_data *data)
{
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
}

void	free_mlx(t_data *data)
{
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	free_resources(t_data *data)
{
	free_img(data);
	free_map(data);
	free_win(data);
	free_textures(data);
	free_mlx(data);
}
