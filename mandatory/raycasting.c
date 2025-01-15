#include "cub3d.h"

void    raycast(t_data *data)
{
    double   camera_x;
    // double   ray_x;
    // double   ray_y;
    int      i;

    data->player.plane_x = -data->player.dir_y * tan(data->fov / 2);
    data->player.plane_y = data->player.dir_x * tan(data->fov / 2);
    while (i < data->screen_width)
    {
        camera_x = 2 * i / double(data->screen_width) - 1;
        data->ray.rayd_x = data->player.dir_x + data->player.plane_x * camera_x;
        data->ray.rayd_y = data->player.dir_y + data->player.plane_y * camera_x;
        init_dist();
    }
}

void    init_dist(t_data *data)
{
    int     map_x;
    int     map_y;
    // double  delta_x;
    // double  delta_y;
    // double  side_x;
    // double  side_y;

    map_x = (int)data->player.x_pos;
    map_y = (int)data->player.y_pos;
    if (data->ray.rayd_x == 0)
        data->ray.delta_x = inf;
    else
        data->ray.delta_x = fabs(1 / ray_x);
    if (data->ray.rayd_y == 0)
        data->ray.delta_y = inf;
    else
        data->ray.delta_y = fabs(1 / ray_y);

}

void    raytrace(t_data *data, double x_pos, double y_pos, double raydir_x, double raydir_y)
{
    int     step_x;
    int     step_y;
    
}


//  double  ray_angle;
//     double  segment;
//     double  start_angle;
//     double  raydir_x;
//     double  raydir_y;
//     int     i;
//     int     screen_width;

//     segment = data->player.fov / data->map_width;
//     start_angle = atan2(data->player.y_dir, data->player.x_dir) - (data->player.fov / 2)
//     screen_width = data->screen_width;
//     while (i < screen_width)
//     {
//         ray_angle = start_angle + i * segment;
//         raydir_x = cos(ray_angle);
//         raydir_y = sin(ray_angle);
//         raytrace();
//         i++;
//     }