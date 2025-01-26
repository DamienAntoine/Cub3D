#include "../headers/cub.h"

void	check_map(t_data *data)
{
	validate_player_position(data);
	validate_map_elements(data);
	check_surr_walls(&data);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
