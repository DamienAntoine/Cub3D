/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:12 by dantoine          #+#    #+#             */
/*   Updated: 2025/01/26 22:50:59 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	free_and_exit(t_data *data, char *msg)
{
	free_img(data);
	free_map(data);
	free_win(data);
	free_textures(data);
	free_mlx(data);
	if (data->tokens)
	{
		free(data->tokens);
		data->tokens = NULL;
	}
	printf("%s\n", msg);
	exit(1);
}

void	free_and_close(char *line, int fd)
{
	free(line);
	close(fd);
}

void	cleanup_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_textures(t_data *data)
{
	if (data->north.img)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->east.img)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.img)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->north.path)
		free(data->north.path);
	if (data->south.path)
		free(data->south.path);
	if (data->east.path)
		free(data->east.path);
	if (data->west.path)
		free(data->west.path);
}
