/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:52:58 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/11 22:49:32 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

int	check_config_textures(t_config *config)
{
	if (!ft_strncmp(config->split[0], "NO", 3))
	{
		if (load_texture(config->data, &config->data->north, config->split[1]))
		{
			cleanup_config(config->data, config->line, config->split,
				config->fd);
			exit_error("Failed to load north texture");
		}
		return (1);
	}
	else if (!ft_strncmp(config->split[0], "SO", 3))
	{
		if (load_texture(config->data, &config->data->south, config->split[1]))
		{
			cleanup_config(config->data, config->line, config->split,
				config->fd);
			exit_error("Failed to load south texture");
		}
		return (1);
	}
	return (0);
}

/* int	check_config_textures(t_data *data, char **split, char *line,
		int fd)
{
	if (!ft_strncmp(split[0], "NO", 3))
	{
		if (load_texture(data, &data->north, split[1]))
		{
			cleanup_config(data, line, split, fd);
			exit_error("Failed to load north texture");
		}
		return (1);
	}
	else if (!ft_strncmp(split[0], "SO", 3))
	{
		if (load_texture(data, &data->south, split[1]))
		{
			cleanup_config(data, line, split, fd);
			exit_error("Failed to load south texture");
		}
		return (1);
	}
	return (0);
} */
int	check_config_walls(t_config *config)
{
	if (!ft_strncmp(config->split[0], "WE", 3))
	{
		if (load_texture(config->data, &config->data->west, config->split[1]))
		{
			cleanup_config(config->data, config->line, config->split,
				config->fd);
			exit_error("Failed to load west texture");
		}
		return (1);
	}
	else if (!ft_strncmp(config->split[0], "EA", 3))
	{
		if (load_texture(config->data, &config->data->east, config->split[1]))
		{
			cleanup_config(config->data, config->line, config->split,
				config->fd);
			exit_error("Failed to load east texture");
		}
		return (1);
	}
	return (0);
}

/* int	check_config_walls(t_data *data, char **split, char *line, int fd)
{
	if (!ft_strncmp(split[0], "WE", 3))
	{
		if (load_texture(data, &data->west, split[1]))
		{
			cleanup_config(data, line, split, fd);
			exit_error("Failed to load west texture");
		}
		return (1);
	}
	else if (!ft_strncmp(split[0], "EA", 3))
	{
		if (load_texture(data, &data->east, split[1]))
		{
			cleanup_config(data, line, split, fd);
			exit_error("Failed to load east texture");
		}
		return (1);
	}
	return (0);
} */
int	check_config_colors(t_config *config)
{
	if (!ft_strncmp(config->split[0], "F", 2))
	{
		config->data->floor_color = parse_rgb(config->split[1]);
		if (config->data->floor_color == -1)
		{
			cleanup_config(config->data, config->line, config->split,
				config->fd);
			exit_error("Invalid floor color");
		}
		return (1);
	}
	else if (!ft_strncmp(config->split[0], "C", 2))
	{
		config->data->ceiling_color = parse_rgb(config->split[1]);
		if (config->data->ceiling_color == -1)
		{
			cleanup_config(config->data, config->line, config->split,
				config->fd);
			exit_error("Invalid ceiling color");
		}
		return (1);
	}
	return (0);
}

/* int	check_config_colors(t_data *data, char **split, char *line, int fd)
{
	if (!ft_strncmp(split[0], "F", 2))
	{
		data->floor_color = parse_rgb(split[1]);
		if (data->floor_color == -1)
		{
			cleanup_config(data, line, split, fd);
			exit_error("Invalid floor color");
		}
		return (1);
	}
	else if (!ft_strncmp(split[0], "C", 2))
	{
		data->ceiling_color = parse_rgb(split[1]);
		if (data->ceiling_color == -1)
		{
			cleanup_config(data, line, split, fd);
			exit_error("Invalid ceiling color");
		}
		return (1);
	}
	return (0);
} */
int	process_config_line(t_config *config)
{
	if (!config->split || !config->split[0])
		return (0);
	if (check_config_textures(config))
		return (0);
	if (check_config_walls(config))
		return (0);
	if (check_config_colors(config))
		return (0);
	if (ft_strchr("01NSEW", config->split[0][0]))
		return (1);
	return (0);
}

/* int	process_config_line(t_data *data, char **split, char *line, int fd)
{
	if (!split || !split[0])
		return (0);
	if (check_config_textures(data, split, line, fd))
		return (0);
	if (check_config_walls(data, split, line, fd))
		return (0);
	if (check_config_colors(data, split, line, fd))
		return (0);
	if (ft_strchr("01NSEW", split[0][0]))
		return (1);
	return (0);
} */
