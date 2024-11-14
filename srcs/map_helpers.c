#include "../headers/cub.h"

int	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_surr_walls(t_data **data)
{
	int	i;

	if (check_walls((*data)->map[0]))
	{
		clean_map(&data);
		perror("ERROR: Map not surrounded by walls");
	}
	i = map_height((*data)->map) - 1;
	while (i)
	{
		if ((*data)->map[i][0] != '1'
			|| (*data)->map[i][ft_strlen((*data)->map[i]) - 1] != '1')
		{
			clean_map(&data);
			perror("ERROR: Map not surrounded by walls");
		}
		i--;
	}
	if (check_walls((*data)->map[map_height((*data)->map) - 1]))
	{
		clean_map(&data);
		perror("ERROR: Map not surrounded by walls");
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
