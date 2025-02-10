/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:34 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/10 23:18:49 by sanhwang         ###   ########.fr       */
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
		if (all_lines)
			free(all_lines);
		get_next_line(-1);
		printf("Error: Invalid configuration line\n");
		return (NULL);
	}
	return (handle_map_line(cur_line, all_lines, map_info));
}

/*
static char	*handle_config_or_map_line(char *cur_line, char *all_lines,
		t_map_info *map_info)
{
	char		*tmp;
	char		*tmp;
	t_map_info	*map_info;
	char		*cur_line;
	char		*tmp;

	if (map_info->config_count < 6)
	{
		if (is_config_line(cur_line))
			process_map_configs(cur_line, &map_info->config_count);
		else
		{
			all_lines = error_invalid_config(cur_line, all_lines);
			return (NULL);
		}
	}
	else
	{
		tmp = handle_map_line(cur_line, all_lines, &map_info->map_started,
				&map_info->last_valid_line_found, &map_info->map_ended);
		if (!tmp)
		{
			if (map_info->map_ended)
				printf("Error: Extra lines found after the map.\n");
			else
				printf("Error: Invalid or unknown map line.\n");
			return (NULL);
		}
		all_lines = tmp;
	}
	return (all_lines);
} */
/*
static char	*handle_config_or_map_line(char *cur_line, char *all_lines,
		int *config_count, int *map_started, int *last_valid_line_found,
		int *map_ended)
{
	if (*config_count < 6)
	{
		if (is_config_line(cur_line))
			process_map_configs(cur_line, config_count);
		else
		{
			all_lines = error_invalid_config(cur_line, all_lines);
			return (NULL);
		}
	}
	else
	{
		tmp = handle_map_line(cur_line, all_lines, map_started,
				last_valid_line_found, map_ended);
		if (!tmp)
		{
			if (*map_ended)
				printf("Error: Extra lines found after the map.\n");
			else
				printf("Error: Invalid or unknown map line.\n");
			return (NULL);
		}
		all_lines = tmp;
	}
	return (all_lines);
} */
static char	*read_map_lines(int fd, char *all_lines)
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
	while ((cur_line = get_next_line(fd)))
	{
		if (skip_empty_line(cur_line, &map_info->map_started,
				&map_info->map_ended))
			continue ;
		tmp = handle_config_or_map_line(cur_line, all_lines, map_info);
		free(cur_line);
		if (!tmp)
		{
			free(map_info);
			free(all_lines);
			cleanup_gnl(fd);
			return (NULL);
		}
		all_lines = tmp;
	}
	free(map_info);
	cleanup_gnl(fd);
	return (all_lines);
}

/* static char	*read_map_lines(int fd, char *all_lines)
{
	int		config_count;
	int		map_started;
	int		last_valid_line_found;
	int		map_ended;
	char	*cur_line;
	char	*tmp;

	config_count = 0;
	map_started = 0;
	last_valid_line_found = 0;
	map_ended = 0;
	while ((cur_line = get_next_line(fd)))
	{
		if (skip_empty_line(cur_line, &map_started, &map_ended))
			continue ;
		tmp = handle_config_or_map_line(cur_line, all_lines, &config_count,
				&map_started, &last_valid_line_found, &map_ended);
		free(cur_line);
		if (!tmp)
			return (NULL);
		all_lines = tmp;
	}
	return (all_lines);
} */

char	*parse_map_read(char *map)
{
	int		fd;
	char	*all_lines;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		get_next_line(-1);
		exit_error("Error: cannot open file");
	}
	all_lines = handle_file_open(map, fd);
	if (!all_lines)
	{
		get_next_line(-1);
		cleanup_gnl(fd);
		close(fd);
		return (NULL);
	}
	all_lines = read_map_lines(fd, all_lines);
	if (!all_lines)
	{
		get_next_line(-1);
		return (NULL);
	}
	cleanup_gnl(fd);
	close(fd);
	return (all_lines);
}
