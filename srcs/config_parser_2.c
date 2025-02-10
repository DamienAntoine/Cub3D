/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:01 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/10 11:38:31 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/* void	cleanup_config(t_data *data, char *line, char **split, int fd)
{
	if (line)
		free(line);
	if (split)
		free_split(split);
	if (fd > 0)
		close(fd);
	get_next_line(-1);
	free_resources(data);
} */

int	validate_rgb_value(char **split, int *rgb, int i)
{
	rgb[i] = ft_atoi(split[i]);
	if (rgb[i] < 0 || rgb[i] > 255)
	{
		free_split(split);
		return (-1);
	}
	return (0);
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	is_valid_color_format(char *str)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			commas++;
			if (commas > 2 || !ft_isdigit(str[i + 1]) || !ft_isdigit(str[i
						- 1]))
				return (0);
		}
		else if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (commas == 2);
}

int	parse_rgb(char *line)
{
	char	**split;
	int		rgb[3];
	int		i;
	int		color;

	if (!is_valid_color_format(line))
		return (-1);
	split = ft_split(line, ',');
	if (!split)
		return (-1);
	i = 0;
	while (split[i] && i < 3)
	{
		if (validate_rgb_value(split, rgb, i) == -1)
			return (-1);
		i++;
	}
	if (i != 3)
	{
		free_split(split);
		return (-1);
	}
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	free_split(split);
	return (color);
}

int	load_texture(t_data *data, t_texture *texture, char *path)
{
	char	*newline;

	texture->path = ft_strdup(path);
	if (!texture->path)
		return (1);
	newline = ft_strchr(texture->path, '\n');
	if (newline)
		*newline = '\0';
	texture->img = mlx_xpm_file_to_image(data->mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Error: Could not load texture from %s\n", texture->path);
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		mlx_destroy_image(data->mlx, texture->img);
		return (1);
	}
	return (0);
}
