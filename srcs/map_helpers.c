#include "../headers/cub.h"

int	check_walls(char *line)
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

void	check_surr_walls(t_data **data)
{
	int	i;
	int	j;
	int	height;
	int	len;

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
	i = 0;
	while(i < height)
	{
		len = ft_strlen((*data)->map[i]);
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
		i++;
	}
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
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
	free_resources(**data);
	exit(1);
}
