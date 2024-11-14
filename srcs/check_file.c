#include "../headers/cub.h"

void	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".cub", 4) != 0)
		exit_error("Error: Invalid file extension (must be .cub)");
}
