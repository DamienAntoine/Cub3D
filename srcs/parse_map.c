#include "../headers/cub.h"

int	check_walls(char *line)
{
	int		i;

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
	int		i;

	if (check_walls((*data)->map[0]))
	{
		clean_map(&data);
		perror("ERROR: Map not surrounded by walls");
	}
	i = map_height((*data)->map) - 1;
	while (i)
	{
		if ((*data)->map[i][0] != '1' ||
			(*data)->map[i][ft_strlen((*data)->map[i]) - 1] != '1')
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

char	**parse_map(char *map)
{
	char	*cur_line;
	char	*all_lines;
	char	*temp;
	char	**split_lines;
	int		fd;

	cur_line = "";
	all_lines = ft_strdup("");
	if (!all_lines)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR: Couldn't open fd");
		free(all_lines);
		return (NULL);
	}
	while ((cur_line = get_next_line(fd)) != NULL && cur_line[0] != '\n')
	{
		temp = all_lines;
        all_lines = ft_strjoin(all_lines, cur_line);
		free(temp);
        free(cur_line);
    }
	if(cur_line)
		free(cur_line);
	close(fd);
	if (all_lines[0] == '\0')
	{
		perror("ERROR: Selected map is NULL");
		free(all_lines);
		return (NULL);
	}
	split_lines = ft_split(all_lines, '\n');
	free(all_lines);
	return (split_lines);
}
