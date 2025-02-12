/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:32:00 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/12 01:14:54 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	is_config_line(const char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

int	is_valid_map_line(char *line)
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

char	*return_error(char *all_lines)
{
	free(all_lines);
	printf("Error: Extra lines found after the map.\n");
	return (NULL);
}

/* char	*error_invalid_config(char *cur_line, char *all_lines)
{
	if (all_lines)
		free(all_lines);
	get_next_line(-1);
	printf("Error: Invalid or unknown config line.\n");
	return (NULL);
} */

char	*error_invalid_map_line(char *cur_line, char *all_lines)
{
	free(cur_line);
	free(all_lines);
	get_next_line(-1);
	printf("Error: Invalid or unknown map line.\n");
	return (NULL);
}
