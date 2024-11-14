#include "../headers/cub.h"

void	check_map(t_data *data)
{
	validate_player_position(data);
	validate_map_elements(data);
	check_surr_walls(&data);
}
