/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:32:13 by sanhwang          #+#    #+#             */
/*   Updated: 2025/02/11 22:49:29 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	check_duplicates(t_config *config)
{
	t_tokens	*tokens;

	tokens = config->data->tokens;
	if ((!ft_strncmp(config->split[0], "NO", 3) && tokens->no)
		|| (!ft_strncmp(config->split[0], "SO", 3) && tokens->so)
		|| (!ft_strncmp(config->split[0], "WE", 3) && tokens->we)
		|| (!ft_strncmp(config->split[0], "EA", 3) && tokens->ea)
		|| (!ft_strncmp(config->split[0], "F", 2) && tokens->f)
		|| (!ft_strncmp(config->split[0], "C", 2) && tokens->c))
	{
		cleanup_config(config->data, config->line, config->split, config->fd);
		exit_error("Error: Duplicate configuration token");
	}
}

/* void	check_duplicates(char *token, t_data *data, char *line,
		char **split, int fd)
{
	t_tokens	*tokens;

	tokens = data->tokens;
	if ((!ft_strncmp(token, "NO", 3) && tokens->no) || (!ft_strncmp(token, "SO",
				3) && tokens->so) || (!ft_strncmp(token, "WE", 3) && tokens->we)
		|| (!ft_strncmp(token, "EA", 3) && tokens->ea) || (!ft_strncmp(token,
				"F", 2) && tokens->f) || (!ft_strncmp(token, "C", 2)
			&& tokens->c))
	{
		cleanup_config(data, line, split, fd);
		exit_error("Error: Duplicate configuration token");
	}
} */
void	save_token_status(t_config *config)
{
	check_duplicates(config);
	if (!ft_strncmp(config->split[0], "NO", 3))
		config->data->tokens->no = 1;
	else if (!ft_strncmp(config->split[0], "SO", 3))
		config->data->tokens->so = 1;
	else if (!ft_strncmp(config->split[0], "WE", 3))
		config->data->tokens->we = 1;
	else if (!ft_strncmp(config->split[0], "EA", 3))
		config->data->tokens->ea = 1;
	else if (!ft_strncmp(config->split[0], "F", 2))
		config->data->tokens->f = 1;
	else if (!ft_strncmp(config->split[0], "C", 2))
		config->data->tokens->c = 1;
}

/* void	save_token_status(char **split, t_data *data, char *line, int fd)
{
	check_duplicates(split[0], data, line, split, fd);
	if (!ft_strncmp(split[0], "NO", 3))
		data->tokens->no = 1;
	else if (!ft_strncmp(split[0], "SO", 3))
		data->tokens->so = 1;
	else if (!ft_strncmp(split[0], "WE", 3))
		data->tokens->we = 1;
	else if (!ft_strncmp(split[0], "EA", 3))
		data->tokens->ea = 1;
	else if (!ft_strncmp(split[0], "F", 2))
		data->tokens->f = 1;
	else if (!ft_strncmp(split[0], "C", 2))
		data->tokens->c = 1;
} */
void	init_config(t_config *config, t_data *data, int fd)
{
	config->data = data;
	config->line = NULL;
	config->split = NULL;
	config->fd = fd;
}

int	process_config_entry(t_config *config, char *line, char **split)
{
	if (!split || !split[0])
		return (0);
	config->line = line;
	config->split = split;
	save_token_status(config);
	return (process_config_line(config));
}

void	parse_config(t_data *data, char *file)
{
	int			config_done;
	char		*line;
	char		**split;
	t_config	config;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_fd_error(data);
	init_config(&config, data, fd);
	config_done = 0;
	line = get_next_line(fd);
	while (!config_done && line)
	{
		split = ft_split(line, ' ');
		config_done = process_config_entry(&config, line, split);
		free(line);
		free_split(split);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}

/* 
void	parse_config(t_data *data, char *file)
{
	int			config_done;
	char		*line;
	char		**split;
	t_config	config;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_fd_error(data);
	init_config(&config, data, fd);
	config_done = 0;
	line = get_next_line(fd);
	while (!config_done && line)
	{
		split = ft_split(line, ' ');
		if (split && split[0])
		{
			config.line = line;
			config.split = split;
			save_token_status(&config);
			config_done = process_config_line(&config);
		}
		free(line);
		free_split(split);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}
 */
/* void	parse_config(t_data *data, char *file)
{
	int			fd;
	char		*line;
	char		**split;
	int			config_done;
	t_config	config;

	config.data = data;
	config.line = NULL;
	config.split = NULL;
	config.fd = -1;
	config_done = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_fd_error(data);
	config.fd = fd;
	line = get_next_line(fd);
	while (!config_done && line)
	{
		split = ft_split(line, ' ');
		if (split && split[0])
		{
			config.line = line;
			config.split = split;
			save_token_status(&config);
			config_done = process_config_line(&config);
		}
		free(line);
		free_split(split);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
} */

/* void	parse_config(t_data *data, char *file)
{
	int		fd;
	char	*line;
	char	**split;
	int		config_done;

	config_done = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_fd_error(data);
	while (!config_done && (line = get_next_line(fd)))
	{
		split = ft_split(line, ' ');
		if (split && split[0])
		{
			save_token_status(split, data, line, fd);
			config_done = process_config_line(data, split, line, fd);
		}
		free(line);
		free_split(split);
	}
	close(fd);
}
 */