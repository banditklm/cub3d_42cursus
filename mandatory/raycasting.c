#include "cub3d.h"

void    raycast(t_data *data)
{
    double  ray_angle;
    double  segment;
    double  start_angle;
    double  raydir_x;
    double  raydir_y;
    int     i;
    int     screen_width;

    segment = data->player.fov / data->map_width;
    start_angle = atan2(data->player.y_dir, data->player.x_dir) - (data->player.fov / 2)
    screen_width = data->screen_width;
    while (i < screen_width)
    {
        ray_angle = start_angle + i * segment;
        raydir_x = cos(ray_angle);
        raydir_y = sin(ray_angle);
        trace_ray();
        i++;
    }
}


