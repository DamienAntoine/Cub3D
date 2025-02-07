/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:34 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/06 22:17:47 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

char	*handle_file_open(char *map, int fd)
{
	if (fd < 0)
		return (NULL);
	return (parse_map_read_prep(map));
}

static int	is_config_line(const char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

static int	is_valid_map_line(char *line)
{
	int	i;
	int	has_wall;

	i = 0;
	has_wall = 0;
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

static char	*return_error(char *cur_line, char *all_lines, int fd)
{
	free(all_lines);
	printf("Error: Extra lines found after the map.\n");
	return (NULL);
}

static char	*handle_map_line(char *cur_line, char *all_lines, int fd,
		int *map_started, int *last_valid_line_found, int *map_ended)
{
	if (*map_ended)
		return (return_error(cur_line, all_lines, fd));
	if (!*map_started)
		*map_started = 1;
	if (is_valid_map_line(cur_line))
	{
		*last_valid_line_found = 1;
		return (process_map_lines(cur_line, all_lines));
	}
	else if (*last_valid_line_found)
		return (return_error(cur_line, all_lines, fd));
	return (all_lines);
}

static char	*read_map_lines(int fd, char *all_lines)
{
	int		config_count = 0, map_started = 0, last_valid_line_found = 0,
				map_ended;
	char	*cur_line;

	config_count = 0, map_started = 0, last_valid_line_found = 0, map_ended = 0;
	while ((cur_line = get_next_line(fd)))
	{
		if (!cur_line[0] || cur_line[0] == '\n')
		{
			if (map_started && !map_ended)
				map_ended = 1;
			free(cur_line);
			continue ;
		}
		if (config_count < 6 && is_config_line(cur_line))
			process_map_configs(cur_line, &config_count);
		else
			all_lines = handle_map_line(cur_line, all_lines, fd, &map_started,
					&last_valid_line_found, &map_ended);
		free(cur_line);
		if (!all_lines)
			return (NULL);
	}
	return (all_lines);
}

char	*parse_map_read(char *map)
{
	int		fd;
	char	*all_lines;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Error: cannot open file");
	all_lines = handle_file_open(map, fd);
	if (!all_lines)
	{
		close(fd);
		return (NULL);
	}
	all_lines = read_map_lines(fd, all_lines);
	close(fd);
	cleanup_gnl(fd);
	return (all_lines);
}

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
