#include "../headers/cub.h"

static int	check_config_textures(t_data *data, char **split, char *line,
		int fd)
{
	if (!ft_strncmp(split[0], "NO", 3))
	{
		if (load_texture(data, &data->north, split[1]))
		{
			cleanup_config(data, line, split, fd);
			exit_error("Failed to load north texture");
		}
		return (1);
	}
	else if (!ft_strncmp(split[0], "SO", 3))
	{
		if (load_texture(data, &data->south, split[1]))
		{
			cleanup_config(data, line, split, fd);
			exit_error("Failed to load south texture");
		}
		return (1);
	}
	return (0);
}

static int	check_config_walls(t_data *data, char **split, char *line, int fd)
{
	if (!ft_strncmp(split[0], "WE", 3))
	{
		if (load_texture(data, &data->west, split[1]))
		{
			cleanup_config(data, line, split, fd);
			exit_error("Failed to load west texture");
		}
		return (1);
	}
	else if (!ft_strncmp(split[0], "EA", 3))
	{
		if (load_texture(data, &data->east, split[1]))
		{
			cleanup_config(data, line, split, fd);
			exit_error("Failed to load east texture");
		}
		return (1);
	}
	return (0);
}

static int	check_config_colors(t_data *data, char **split, char *line, int fd)
{
	if (!ft_strncmp(split[0], "F", 2))
	{
		data->floor_color = parse_rgb(split[1]);
		if (data->floor_color == -1)
		{
			cleanup_config(data, line, split, fd);
			exit_error("Invalid floor color");
		}
		return (1);
	}
	else if (!ft_strncmp(split[0], "C", 2))
	{
		data->ceiling_color = parse_rgb(split[1]);
		if (data->ceiling_color == -1)
		{
			cleanup_config(data, line, split, fd);
			exit_error("Invalid ceiling color");
		}
		return (1);
	}
	return (0);
}

static int	process_config_line(t_data *data, char **split, char *line, int fd)
{
	if (!split)
		return (0);
	if (split[0] && split[1])
	{
		if (check_config_textures(data, split, line, fd))
			;
		else if (check_config_walls(data, split, line, fd))
			;
		else if (check_config_colors(data, split, line, fd))
			;
		else if (ft_strchr("01NSEW", split[0][0]))
			return (1);
	}
	return (0);
}

void	parse_config(t_data *data, char *file)
{
	int		fd;
	char	*line;
	char	**split;
	int		config_done;

	config_done = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		cleanup_config(data, NULL, NULL, -1);
		exit_error("Error: Cannot open config file");
	}
	while ((line = get_next_line(fd)) && !config_done)
	{
		split = ft_split(line, ' ');
		if (!split)
		{
			free(line);
			continue ;
		}
		config_done = process_config_line(data, split, line, fd);
		free(line);
		free_split(split);
	}
	close(fd);
}
