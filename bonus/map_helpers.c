/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:53:27 by dantoine          #+#    #+#             */
/*   Updated: 2025/02/11 22:49:57 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

static int	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static void	check_horizontal_walls(t_data **data)
{
	int	height;

	height = map_height((*data)->map);
	if (check_walls((*data)->map[0]))
	{
		clean_map(&data);
		perror("ERROR: Map not surrounded by walls (top)");
	}
	if (check_walls((*data)->map[height - 1]))
	{
		clean_map(&data);
		perror("ERROR: Map not surrounded by walls (bottom)");
	}
}

static void	check_vertical_line(t_data **data, int i, int len)
{
	int	j;

	j = 0;
	while ((*data)->map[i][j] == ' ')
		j++;
	if ((*data)->map[i][j] != '1')
	{
		clean_map(&data);
		perror("ERROR: Map not surrounded by walls (left)");
	}
	j = len - 1;
	while (j >= 0 && (*data)->map[i][j] == ' ')
		j--;
	if (j >= 0 && (*data)->map[i][j] != '1')
	{
		clean_map(&data);
		perror("ERROR: Map not surrounded by walls (right)");
	}
}

void	check_surr_walls(t_data **data)
{
	int	i;
	int	height;
	int	len;

	height = map_height((*data)->map);
	check_horizontal_walls(data);
	i = 0;
	while (i < height)
	{
		len = ft_strlen((*data)->map[i]);
		check_vertical_line(data, i, len);
		i++;
	}
}

void	clean_map(t_data ***data)
{
	int	i;

	if (!data || !*data || !**data)
		return ;
	if ((**data)->map)
	{
		i = 0;
		while ((**data)->map[i])
		{
			free((**data)->map[i]);
			(**data)->map[i] = NULL;
			i++;
		}
		free((**data)->map);
		(**data)->map = NULL;
	}
	get_next_line(-1);
	free_resources(**data);
	exit(1);
}
