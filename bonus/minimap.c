#include "../headers/cub3d_bonus.h"

void    init_minimap(t_data *data)
{
   int y;
   int max_x;

   data->minimap.pos_x = 10;
   data->minimap.pos_y = 10;
   data->minimap.scale = 5;
   data->minimap.border = 1;
   data->minimap.show = 1;
   y = 0;
   max_x = 0;
   while (data->map[y])
   {
       if ((int)ft_strlen(data->map[y]) > max_x)
           max_x = ft_strlen(data->map[y]);
       y++;
   }
    data->minimap.width = data->map_width / 20;
    data->minimap.height = data->map_height / 20;
}

void    draw_square(t_data *data, int x, int y, int size, int color)
{
   int i;
   int j;

   i = 0;
   while (i < size)
   {
       j = 0;
       while (j < size)
       {
           my_mlx_pixel_put(data, x + i, y + j, color);
           j++;
       }
       i++;
   }
}
/* 
void    draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
   int dx;
   int dy;
   int sx;
   int sy;
   int err;
   int e2;

   dx = abs(x1 - x0);
   dy = abs(y1 - y0);
   if (x0 < x1)
       sx = 1;
   else
       sx = -1;
   if (y0 < y1)
       sy = 1;
   else
       sy = -1;
   if (dx > dy)
       err = dx / 2;
   else
       err = -dy / 2;
   while (1)
   {
       my_mlx_pixel_put(data, x0, y0, color);
       if (x0 == x1 && y0 == y1)
           break;
       e2 = err;
       if (e2 > -dx)
       {
           err -= dy;
           x0 += sx;
       }
       if (e2 < dy)
       {
           err += dx;
           y0 += sy;
       }
   }
} */

void    draw_minimap(t_data *data)
{
   int x;
   int y;
   int scale;
   int map_x;
   int map_y;


   if (!data->minimap.show)
       return ;
   x = 0;
   y = 0;
   scale = data->minimap.scale;
   map_x = data->minimap.pos_x;
   map_y = data->minimap.pos_y;
   draw_square(data, map_x - data->minimap.border,
       map_y - data->minimap.border,
       data->minimap.width + 2 * data->minimap.border,
       0x440004);
   while (data->map[y])
   {
       x = 0;
       while (data->map[y][x])
       {
           if (data->map[y][x] == '1')
               draw_square(data, map_x + x * scale,
                   map_y + y * scale, scale, 0xFFFFFF);
           x++;
       }
       y++;
   }
draw_square(data, map_x + (int)(data->ray.pos_x * scale),
    map_y + (int)(data->ray.pos_y * scale), 5, 0xFF3300);

}