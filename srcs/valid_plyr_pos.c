#include "../headers/cub.h"

/* static void set_player_position(t_data *data, int x, int y)
{
   data->ray.pos_x = x + 0.5;
   data->ray.pos_y = y + 0.5;
} */

static void set_north_south_direction(t_data *data, char dir)
{
   data->ray.dir_x = 0;
   if (dir == 'N') {
       data->ray.dir_y = -1;
       data->ray.plane_x = 0.66;
   } else {
       data->ray.dir_y = 1;
       data->ray.plane_x = -0.66;
   }
   data->ray.plane_y = 0;
}

static void set_east_west_direction(t_data *data, char dir)
{
   data->ray.plane_y = 0;
   if (dir == 'E') {
       data->ray.dir_x = 1;
       data->ray.plane_y = 0.66;
   } else {
       data->ray.dir_x = -1;
       data->ray.plane_y = -0.66;
   }
   data->ray.dir_y = 0;
   data->ray.plane_x = 0;
}

static void set_player_direction(t_data *data, int x, int y, char dir)
{
   //set_player_position(data, x, y);
    data->ray.pos_x = x + 0.5;
   data->ray.pos_y = y + 0.5;
   if (dir == 'N' || dir == 'S') {
       set_north_south_direction(data, dir);
   } else if (dir == 'E' || dir == 'W') {
       set_east_west_direction(data, dir);
   }
}
/* 
static void set_player_direction(t_data *data, int x, int y, char dir)
{
   data->ray.pos_x = x + 0.5;
   data->ray.pos_y = y + 0.5;
   
   if (dir == 'N')
   {
       data->ray.dir_x = 0;
       data->ray.dir_y = -1;
       data->ray.plane_x = 0.66;
       data->ray.plane_y = 0;
   }
   else if (dir == 'S')
   {
       data->ray.dir_x = 0;
       data->ray.dir_y = 1;
       data->ray.plane_x = -0.66;
       data->ray.plane_y = 0;
   }
   else if (dir == 'E')
   {
       data->ray.dir_x = 1;
       data->ray.dir_y = 0;
       data->ray.plane_x = 0;
       data->ray.plane_y = 0.66;
   }
   else if (dir == 'W')
   {
       data->ray.dir_x = -1;
       data->ray.dir_y = 0;
       data->ray.plane_x = 0;
       data->ray.plane_y = -0.66;
   }
} */

void    validate_player_position(t_data *data)
{
   int player_count;
   int y;
   int x;

   player_count = 0;
   y = -1;
   while (data->map[++y])
   {
       x = 0;
       while (data->map[y][x])
       {
           if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
               || data->map[y][x] == 'E' || data->map[y][x] == 'W')
           {
               player_count++;
               set_player_direction(data, x, y, data->map[y][x]);
           }
           x++;
       }
   }
   if (player_count != 1)
   {
       printf("Error: Map must contain exactly one player position (N,S,E,W)\n");
       exit(1);
   }
}

/* void	validate_player_position(t_data *data)
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
} */
