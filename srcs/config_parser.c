#include "../headers/cub.h"

static void	cleanup_config(t_data *data, char *line, char **split, int fd)
{
	if (line)
		free(line);
	if (split)
		free_split(split);
	if (fd > 0)
		close(fd);
	free_resources(data);
}

static int	parse_rgb(char *line)
{
	char	**split;
	int		rgb[3];
	int		i;
	int		color;

	split = ft_split(line, ',');
	if (!split)
		return (-1);
	i = 0;
	while (split[i] && i < 3)
	{
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free_split(split);
			return (-1);
		}
		i++;
	}
	if (i != 3)
	{
		free_split(split);
		return (-1);
	}
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	free_split(split);
	return (color);
}

int	load_texture(t_data *data, t_texture *texture, char *path)
{
	char	*newline;

	texture->path = ft_strdup(path);
	if (!texture->path)
		return (1);
	newline = ft_strchr(texture->path, '\n');
	if (newline)
		*newline = '\0';
	texture->img = mlx_xpm_file_to_image(data->mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Error: Could not load texture from %s\n", texture->path);
		free(texture->path);
		return (1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		mlx_destroy_image(data->mlx, texture->img);
		free(texture->path);
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
		if (split[0] && split[1])
		{
			if (!ft_strncmp(split[0], "NO", 3))
			{
				if (load_texture(data, &data->north, split[1]))
				{
					cleanup_config(data, line, split, fd);
					exit_error("Failed to load north texture");
				}
			}
			else if (!ft_strncmp(split[0], "SO", 3))
			{
				if (load_texture(data, &data->south, split[1]))
				{
					cleanup_config(data, line, split, fd);
					exit_error("Failed to load south texture");
				}
			}
			else if (!ft_strncmp(split[0], "WE", 3))
			{
				if (load_texture(data, &data->west, split[1]))
				{
					cleanup_config(data, line, split, fd);
					exit_error("Failed to load west texture");
				}
			}
			else if (!ft_strncmp(split[0], "EA", 3))
			{
				if (load_texture(data, &data->east, split[1]))
				{
					cleanup_config(data, line, split, fd);
					exit_error("Failed to load east texture");
				}
			}
			else if (!ft_strncmp(split[0], "F", 2))
			{
				data->floor_color = parse_rgb(split[1]);
				if (data->floor_color == -1)
				{
					cleanup_config(data, line, split, fd);
					exit_error("Invalid floor color");
				}
			}
			else if (!ft_strncmp(split[0], "C", 2))
			{
				data->ceiling_color = parse_rgb(split[1]);
				if (data->ceiling_color == -1)
				{
					cleanup_config(data, line, split, fd);
					exit_error("Invalid ceiling color");
				}
			}
			else if (ft_strchr("01NSEW", split[0][0]))
				config_done = 1; // Found map section
		}
		free(line);
		free_split(split);
	}
	close(fd);
}
