/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:32:13 by sanhwang          #+#    #+#             */
/*   Updated: 2025/02/10 23:46:02 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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

	/*     // Free dynamically allocated memory in config struct
    if (config.line)
        free(config.line);
    if (config.split)
    {
        for (int i = 0; config.split[i]; i++)
            free(config.split[i]);  // Free each string in split
        free(config.split);         // Free the split array
    }
    if (config.data)  
        free(config.data);     
		*/
}
