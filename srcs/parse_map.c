#include "../headers/cub.h"

static void	cleanup_gnl(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
		free(line);
}

void	validate_player_position(t_data *data)
{
	int	player_count;
	int	y;
	int	x;

	player_count = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				player_count++;
				data->ray.pos_x = x + 0.5;
				data->ray.pos_y = y + 0.5;
				if (data->map[y][x] == 'N')
				{
					data->ray.pos_x = x + 0.5;
					data->ray.pos_y = y + 0.5;
					data->ray.dir_x = 0;
					data->ray.dir_y = -1;
					data->ray.plane_x = 0.66;
					data->ray.plane_y = 0;
				}
				else if (data->map[y][x] == 'S')
				{
					data->ray.pos_x = x + 0.5;
					data->ray.pos_y = y + 0.5;
					data->ray.dir_x = 0;
					data->ray.dir_y = 1;
					data->ray.plane_x = -0.66;
					data->ray.plane_y = 0;
				}
				else if (data->map[y][x] == 'E')
				{
					data->ray.pos_x = x + 0.5;
					data->ray.pos_y = y + 0.5;
					data->ray.dir_x = 1;
					data->ray.dir_y = 0;
					data->ray.plane_x = 0;
					data->ray.plane_y = 0.66;
				}
				else if (data->map[y][x] == 'W')
				{
					data->ray.pos_x = x + 0.5;
					data->ray.pos_y = y + 0.5;
					data->ray.dir_x = -1;
					data->ray.dir_y = 0;
					data->ray.plane_x = 0;
					data->ray.plane_y = -0.66;
				}
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		printf("Error: Map must contain exactly one player position (N,S,E,W)\n");
		exit(1);
	}
}

void	validate_map_elements(t_data *data)
{
	int	y;
	int	x;
	int	height;
	int	max_width;
	int	line_len;

	// map dimensions
	y = 0;
	height = 0;
	max_width = 0;
	while (data->map[height])
	{
		line_len = ft_strlen(data->map[height]);
		if (line_len > max_width)
			max_width = line_len;
		height++;
	}
	// map characters and walls
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			// skip spaces
			if (data->map[y][x] == ' ')
			{
				x++;
				continue ;
			}
			// character pos
			if (data->map[y][x] != '0' && data->map[y][x] != '1'
				&& data->map[y][x] != 'N' && data->map[y][x] != 'S'
				&& data->map[y][x] != 'E' && data->map[y][x] != 'W'
				&& data->map[y][x] != ' ')
			{
				printf("Error: Invalid character in map\n");
				exit(1);
			}
			if (data->map[y][x] == '0' || ft_strchr("NSEW", data->map[y][x]))
			{
				// check above
				if (y == 0 || x >= ft_strlen(data->map[y - 1]) || data->map[y
					- 1][x] == ' ' || !data->map[y - 1][x])
				{
					printf("Error: Map must be enclosed by walls (top)\n");
					exit(1);
				}
				// below
				if (!data->map[y + 1] || x >= ft_strlen(data->map[y + 1])
					|| data->map[y + 1][x] == ' ' || !data->map[y + 1][x])
				{
					printf("Error: Map must be enclosed by walls (bottom)\n");
					exit(1);
				}
				// left
				if (x == 0 || data->map[y][x - 1] == ' ')
				{
					printf("Error: Map must be enclosed by walls (left)\n");
					exit(1);
				}
				// right
				if (!data->map[y][x + 1] || data->map[y][x + 1] == ' ')
				{
					printf("Error: Map must be enclosed by walls (right)\n");
					exit(1);
				}
			}
			x++;
		}
		y++;
	}
}

char	**parse_map(char *map)
{
	char	*cur_line;
	char	*all_lines;
	char	*temp;
	char	**split_lines;
	int		fd;
	int		config_count;
	int		map_started;
	char	*trim;

	all_lines = ft_strdup("");
	if (!all_lines)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		free(all_lines);
		return (NULL);
	}
	config_count = 0;
	map_started = 0;
	while ((cur_line = get_next_line(fd)))
	{
		if (ft_strncmp(cur_line, "NO ", 3) == 0 || ft_strncmp(cur_line, "SO ",
				3) == 0 || ft_strncmp(cur_line, "WE ", 3) == 0
			|| ft_strncmp(cur_line, "EA ", 3) == 0 || ft_strncmp(cur_line, "F ",
				2) == 0 || ft_strncmp(cur_line, "C ", 2) == 0)
			config_count++;
		if (cur_line[0] == '\n' || cur_line[0] == '\0')
		{
			free(cur_line);
			continue ;
		}
		if (config_count >= 6)
		{
			trim = cur_line;
			while (*trim == ' ' || *trim == '\t')
				trim++;
			if (*trim == '1' || *trim == '0' || ft_strchr("NSEW", *trim))
			{
				map_started = 1;
				temp = all_lines;
				all_lines = ft_strjoin(all_lines, cur_line);
				free(temp);
				temp = all_lines;
				all_lines = ft_strjoin(all_lines, "\n");
				free(temp);
			}
		}
		free(cur_line);
	}
	cleanup_gnl(fd);
	close(fd);
	if (!map_started || all_lines[0] == '\0')
	{
		free(all_lines);
		return (NULL);
	}
	split_lines = ft_split(all_lines, '\n');
	free(all_lines);
	return (split_lines);
}
