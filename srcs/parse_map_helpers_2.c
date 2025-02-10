#include "../headers/cub3d.h"

char	*error_extra_lines(char *cur_line, char *all_lines)
{
	free(cur_line);
	free(all_lines);
	printf("Error: Extra lines found after the map.\n");
	return (NULL);
}

char	*handle_map_line(char *cur_line, char *all_lines, int *map_started,
		int *last_valid_line_found, int *map_ended)
{
	if (*map_ended)
		return (NULL);
	if (!*map_started)
		*map_started = 1;
	if (is_valid_map_line(cur_line))
	{
		*last_valid_line_found = 1;
		return (process_map_lines(cur_line, all_lines));
	}
	else if (*last_valid_line_found)
		return (NULL);
	return (NULL);
}

char	*handle_file_open(char *map, int fd)
{
	if (fd < 0)
		return (NULL);
	return (parse_map_read_prep(map));
}
