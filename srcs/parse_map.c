#include "../headers/cub.h"

static int	process_map_configs(char *cur_line, int *config_count)
{
	if (ft_strncmp(cur_line, "NO ", 3) == 0 || ft_strncmp(cur_line, "SO ",
			3) == 0 || ft_strncmp(cur_line, "WE ", 3) == 0
		|| ft_strncmp(cur_line, "EA ", 3) == 0 || ft_strncmp(cur_line, "F ",
			2) == 0 || ft_strncmp(cur_line, "C ", 2) == 0)
	{
		(*config_count)++;
		return (1);
	}
	return (0);
}

static char	*process_map_lines(char *cur_line, char *all_lines)
{
	char	*trim;
	char	*temp;

	trim = cur_line;
	while (*trim == ' ' || *trim == '\t')
		trim++;
	if (*trim == '1' || *trim == '0' || ft_strchr("NSEW", *trim))
	{
		temp = all_lines;
		all_lines = ft_strjoin(all_lines, cur_line);
		free(temp);
		temp = all_lines;
		all_lines = ft_strjoin(all_lines, "\n");
		free(temp);
	}
	return (all_lines);
}

char	*parse_map_read_prep(char *map)
{
	char	*cur_line;
	char	*all_lines;
	int		fd;
	int		config_count;

	all_lines = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (fd < 0 || !all_lines)
		return (NULL);
	config_count = 0;
	while ((cur_line = get_next_line(fd)))
	{
		process_map_configs(cur_line, &config_count);
		if (config_count >= 6)
			break ;
		free(cur_line);
	}
	cleanup_gnl(fd);
	close(fd);
	return (all_lines);
}

char	*parse_map_read(char *map)
{
	char	*cur_line;
	char	*all_lines;
	int		fd;
	int		config_count;

	all_lines = parse_map_read_prep(map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	config_count = 0;
	while ((cur_line = get_next_line(fd)))
	{
		process_map_configs(cur_line, &config_count);
		if (cur_line[0] == '\n' || cur_line[0] == '\0')
		{
			free(cur_line);
			continue ;
		}
		if (config_count >= 6)
			all_lines = process_map_lines(cur_line, all_lines);
		free(cur_line);
	}
	cleanup_gnl(fd);
	close(fd);
	return (all_lines);
}

/* char *parse_map_read(char *map)
{
   char *cur_line;
   char *all_lines;
   int fd;
   int config_count;
   int map_started;
   char *cur_line;
   char *all_lines;
   char *temp;
   int fd;
   int config_count;
   int map_started;
   char *trim;
   char	*cur_line;
   char	*all_lines;
   char	*temp;
   int		fd;
   int		config_count;
   int		map_started;
   char	*trim;

   all_lines = ft_strdup("");
   fd = open(map, O_RDONLY);
   if (fd < 0 || !all_lines)
		return (NULL);
   config_count = 0;
   map_started = 0;
   while ((cur_line = get_next_line(fd)))
   {
		process_map_configs(cur_line, &config_count);
		if (cur_line[0] == '\n' || cur_line[0] == '\0')
		{
			free(cur_line);
			continue ;
		}
		if (config_count >= 6)
		{
			all_lines = process_map_lines(cur_line, all_lines);
		}
		free(cur_line);
   }
   cleanup_gnl(fd);
   close(fd);
   return (all_lines);
} */
/* char *parse_map_read(char *map)
{
   all_lines = ft_strdup("");
   fd = open(map, O_RDONLY);
   if (fd < 0 || !all_lines)
		return (NULL);
   config_count = 0;
   map_started = 0;
   while ((cur_line = get_next_line(fd)))
   {
		process_map_configs(cur_line, &config_count);
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
   return (all_lines);
} */
/*
char	*parse_map_read(char *map)
{
   all_lines = ft_strdup("");
   fd = open(map, O_RDONLY);
   if (fd < 0 || !all_lines)
	return (NULL);
   config_count = 0;
   map_started = 0;
   while ((cur_line = get_next_line(fd)))
   {
	if (ft_strncmp(cur_line, "NO ", 3) == 0 || ft_strncmp(cur_line, "SO ",
			3) == 0
		|| ft_strncmp(cur_line, "WE ", 3) == 0 || ft_strncmp(cur_line, "EA ",
				3) == 0
		|| ft_strncmp(cur_line, "F ", 2) == 0 || ft_strncmp(cur_line, "C ",
				2) == 0)
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
   return (all_lines);
}
 */
char	**parse_map(char *map)
{
	char	*all_lines;
	char	**split_lines;

	all_lines = parse_map_read(map);
	if (!all_lines)
		return (NULL);
	split_lines = ft_split(all_lines, '\n');
	free(all_lines);
	return (split_lines);
}

/* char	**parse_map(char *map)
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
} */
