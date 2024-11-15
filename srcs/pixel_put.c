#include "../headers/cub.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    if (!data || !data->image.addr || x < 0 || y < 0 ||
        x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT)
        return;

    char *dst = data->image.addr + (y * data->image.line_length +
                x * (data->image.bits_p_pxl / 8));
    *(unsigned int *)dst = color;
}
