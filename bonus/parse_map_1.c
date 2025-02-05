/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:34 by dantoine          #+#    #+#             */
/*   Updated: 2025/01/27 18:19:13 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

char	*handle_file_open(char *map, int fd)
{
	if (fd < 0)
		return (NULL);
	return (parse_map_read_prep(map));
}

char	*parse_map_read(char *map)
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
