/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:34 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/11 15:00:21 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	skip_empty_line(char *cur_line, int *map_started, int *map_ended)
{
	if (!cur_line[0] || cur_line[0] == '\n')
	{
		if (*map_started && !*map_ended)
			*map_ended = 1;
		free(cur_line);
		return (1);
	}
	return (0);
}

static char	*process_config_or_error(char *cur_line, char *all_lines,
		t_map_info *map_info)
{
	if (is_config_line(cur_line))
	{
		process_map_configs(cur_line, &map_info->config_count);
		return (all_lines);
	}
	all_lines = error_invalid_config(cur_line, all_lines);
	return (NULL);
}

static char	*handle_config_or_map_line(char *cur_line, char *all_lines,
		t_map_info *map_info)
{
	if (map_info->config_count < 6)
	{
		if (is_config_line(cur_line))
		{
			process_map_configs(cur_line, &map_info->config_count);
			return (all_lines);
		}
		all_lines = NULL;
		get_next_line(-1);
		printf("Error: Invalid configuration line\n");
		return (NULL);
	}
	return (handle_map_line(cur_line, all_lines, map_info));
}

static int	process_map_line(int fd, char **cur_line, t_map_info *map_info,
		char **all_lines)
{
	char	*tmp;

	if (skip_empty_line(*cur_line, &map_info->map_started,
			&map_info->map_ended))
	{
		*cur_line = get_next_line(fd);
		return (1);
	}
	tmp = handle_config_or_map_line(*cur_line, *all_lines, map_info);
	free(*cur_line);
	if (!tmp)
	{
		free(map_info);
		cleanup_gnl(fd);
		free(*all_lines);
		return (0);
	}
	*all_lines = tmp;
	*cur_line = get_next_line(fd);
	return (1);
}

char	*read_map_lines(int fd, char *all_lines)
{
	t_map_info	*map_info;
	char		*cur_line;

	map_info = init_map_info();
	if (!map_info)
	{
		free(all_lines);
		cleanup_gnl(fd);
		return (NULL);
	}
	cur_line = get_next_line(fd);
	while (cur_line)
	{
		if (!process_map_line(fd, &cur_line, map_info, &all_lines))
			return (NULL);
	}
	free(map_info);
	cleanup_gnl(fd);
	return (all_lines);
}

/* static char	*read_map_lines(int fd, char *all_lines)
{
	t_map_info	*map_info;
	char		*cur_line;
	char		*tmp;

	map_info = init_map_info();
	if (!map_info)
	{
		free(all_lines);
		cleanup_gnl(fd);
		return (NULL);
	}
	cur_line = get_next_line(fd);
	while (cur_line)
	{
		if (skip_empty_line(cur_line, &map_info->map_started,
				&map_info->map_ended))
		{
			cur_line = get_next_line(fd);
			continue ;
		}
		tmp = handle_config_or_map_line(cur_line, all_lines, map_info);
		free(cur_line);
		if (!tmp)
		{
			free(map_info);
			cleanup_gnl(fd);
			free(all_lines);
			return (NULL);
		}
		all_lines = tmp;
		cur_line = get_next_line(fd);
	}
	free(map_info);
	cleanup_gnl(fd);
	return (all_lines);
} */
