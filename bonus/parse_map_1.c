/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:34 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/10 23:10:10 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

char	*handle_file_open(char *map, int fd)
{
	if (fd < 0)
		return (NULL);
	return (parse_map_read_prep(map));
}

int is_valid_map_line(char *line)
{
	int i = 0;
	int has_wall = 0;

	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || ft_strchr("NSEW", line[i])) 
			has_wall = 1;
		else if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (has_wall);
}

char	*parse_map_read(char *map)
{
	char	*cur_line;
	char	*all_lines;
	int		fd;
	int		config_count;
	int		map_started;
	int		last_valid_line_found;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all_lines = handle_file_open(map, fd);
	if (!all_lines)
	{
		close(fd);
		return (NULL);
	}
	config_count = 0;
	map_started = 0;
	last_valid_line_found = 0;
	cur_line = get_next_line(fd);
	while (cur_line)
	{
		process_map_configs(cur_line, &config_count);
		if (config_count >= 6 && !map_started)
			map_started = 1;
		if (map_started)
		{
			if (is_valid_map_line(cur_line))
				last_valid_line_found = 1;
			else if (last_valid_line_found) 
			{
				free(cur_line);
				free(all_lines);
				close(fd);
				cleanup_gnl(fd);
				printf("Error: Extra lines found after the map.\n");
				return (NULL);
			}
			all_lines = process_map_lines(cur_line, all_lines);
		}

		free(cur_line);
		cur_line = get_next_line(fd);
	}
	close(fd);
	cleanup_gnl(fd);
	return (all_lines);
}

/* char	*parse_map_read(char *map)
{
	char	*cur_line;
	char	*all_lines;
	int		fd;
	int		config_count;

	fd = open(map, O_RDONLY);
	all_lines = handle_file_open(map, fd);
	config_count = 0;
	cur_line = get_next_line(fd);
	while (cur_line)
	{
		process_map_configs(cur_line, &config_count);
		if (cur_line[0] != '\n' && cur_line[0] != '\0' && config_count >= 6)
			all_lines = process_map_lines(cur_line, all_lines);
		free(cur_line);
		cur_line = get_next_line(fd);
	}
	cleanup_gnl(fd);
	close(fd);
	return (all_lines);
} */

char	**parse_map(char *map)
{
	char	*all_lines;
	char	**split_lines;

	all_lines = parse_map_read(map);
	if (!all_lines)
		return (NULL);
	split_lines = ft_split(all_lines, '\n');
	free(all_lines);
	return (split_lines);
}
