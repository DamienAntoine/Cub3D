/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:11:34 by sanhwang          #+#    #+#             */
/*   Updated: 2025/01/27 18:31:35 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	process_map_configs(char *cur_line, int *config_count)
{
	if (!cur_line[0] || cur_line[0] == '\n')
		return (0);
	if ((!ft_strncmp(cur_line, "NO ", 3) || !ft_strncmp(cur_line, "SO ", 3)
			|| !ft_strncmp(cur_line, "WE ", 3) || !ft_strncmp(cur_line, "EA ",
				3)) && ft_strnstr(cur_line, ".xpm", ft_strlen(cur_line)))
	{
		(*config_count)++;
		return (1);
	}
	if ((!ft_strncmp(cur_line, "F ", 2) || !ft_strncmp(cur_line, "C ", 2))
		&& ft_strchr(cur_line, ','))
	{
		(*config_count)++;
		return (1);
	}
	return (0);
}

char	*process_map_lines(char *cur_line, char *all_lines)
{
	char	*trim;
	char	*temp;

	trim = cur_line;
	while (*trim == ' ' || *trim == '\t')
		trim++;
	if (*trim == '1' || *trim == '0' || ft_strchr("NSEW", *trim))
	{
		temp = all_lines;
		all_lines = ft_strjoin(all_lines, cur_line);
		free(temp);
		temp = all_lines;
		all_lines = ft_strjoin(all_lines, "\n");
		free(temp);
	}
	return (all_lines);
}

char	*parse_map_read_prep(char *map)
{
	char	*cur_line;
	char	*all_lines;
	int		fd;
	int		config_count;

	all_lines = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd < 0 || !all_lines)
		return (NULL);
	config_count = 0;
	cur_line = get_next_line(fd);
	while (cur_line)
	{
		process_map_configs(cur_line, &config_count);
		free(cur_line);
		if (config_count >= 6)
			break ;
		cur_line = get_next_line(fd);
	}
	cleanup_gnl(fd);
	close(fd);
	return (all_lines);
}
