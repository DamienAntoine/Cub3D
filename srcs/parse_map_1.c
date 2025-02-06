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
int is_valid_map_line(char *line)
{
	int i = 0;
	int has_wall = 0;

	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || ft_strchr("NSEW", line[i])) 
			has_wall = 1; // Found at least one valid map character
		else if (line[i] != ' ' && line[i] != '\n')
			return (0); // If it contains anything else, it's junk
		i++;
	}
	return (has_wall); // Returns 1 only if there's at least one valid map character
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
		return (NULL); // Handle invalid file

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

		// Detect the start of the map (after configs)
		if (config_count >= 6 && !map_started)
			map_started = 1;

		// If map has started, process the lines
		if (map_started)
		{
			// If it's a valid map line (contains '1' or '0' or NSEW), mark it
			if (is_valid_map_line(cur_line))
				last_valid_line_found = 1;
			else if (last_valid_line_found) 
			{
				// If we already found a valid map line and now get junk -> ERROR
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
/* static int	is_config_line(const char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

static int	is_map_line(const char *line)
{
	if (is_config_line(line))
		return (0);
	if (ft_strchr("NSEW01", line[0]))
		return (1);
	return (0);
}

char	*parse_map_read(char *map)
{
	int		fd;
	char	*cur_line;
	char	*all_lines;
	int		config_count;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Error: cannot open file");
	all_lines = handle_file_open(map, fd);
	config_count = 0;
	while ((cur_line = get_next_line(fd)))
	{
		if (!cur_line[0] || cur_line[0] == '\n')
		{
			free(cur_line);
			continue ;
		}
		if (config_count < 6 && is_config_line(cur_line))
			process_map_configs(cur_line, &config_count);
		else if (config_count >= 6 && is_map_line(cur_line))
		{
			// Now treat it as part of the map
			all_lines = process_map_lines(cur_line, all_lines);
		}
		free(cur_line);
	}
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
