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
					data->ray.dir_x = 0;
					data->ray.dir_y = -1;
					data->ray.plane_x = 0.66;
					// 0.66 is the standard value used in the original wolfenstein 3D (used for field of view)
					data->ray.plane_y = 0;
				}
				else if (data->map[y][x] == 'S')
				{
					data->ray.dir_x = 0;
					data->ray.dir_y = 1;
					data->ray.plane_x = -0.66;
					data->ray.plane_y = 0;
				}
				else if (data->map[y][x] == 'E')
				{
					data->ray.dir_x = 1;
					data->ray.dir_y = 0;
					data->ray.plane_x = 0;
					data->ray.plane_y = 0.66;
				}
				else if (data->map[y][x] == 'W')
				{
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
	int	width;
	int	height;

	y = 0;
	// Get height first
	height = 0;
	while (data->map[height])
		height++;
	width = ft_strlen(data->map[0]);
	while (data->map[y])
	{
		if ((int)ft_strlen(data->map[y]) != width)
		{
			printf("Error: Map must be rectangular\n");
			exit(1);
		}
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '0' && data->map[y][x] != '1'
				&& data->map[y][x] != 'N' && data->map[y][x] != 'S'
				&& data->map[y][x] != 'E' && data->map[y][x] != 'W'
				&& data->map[y][x] != ' ')
			{
				printf("Error: Invalid character in map\n");
				exit(1);
			}
			if (data->map[y][x] == '0' || data->map[y][x] == 'N'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'W')
			{
				if (y == 0 || y == height - 1 || x == 0 || x == width - 1
					|| data->map[y - 1][x] == ' ' || data->map[y + 1][x] == ' '
					|| data->map[y][x - 1] == ' ' || data->map[y][x + 1] == ' ')
				{
					printf("Error: Map must be enclosed by walls\n");
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
	int		found_map;

	found_map = 0;
	all_lines = ft_strdup("");
	if (!all_lines)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		free(all_lines);
		return (NULL);
	}
	// Skip config section
	while ((cur_line = get_next_line(fd)) != NULL)
	{
		if (!found_map && cur_line[0] && ft_strchr("01NSEW", cur_line[0]))
			found_map = 1;
		if (found_map)
		{
			temp = all_lines;
			all_lines = ft_strjoin(all_lines, cur_line);
			free(temp);
		}
		free(cur_line);
	}
	cleanup_gnl(fd);
	close(fd);
	if (all_lines[0] == '\0')
	{
		free(all_lines);
		return (NULL);
	}
	split_lines = ft_split(all_lines, '\n');
	free(all_lines);
	return (split_lines);
}
