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
        raytrace();
        i++;
    }
}

void    raytrace(t_data *data, double x_pos, double y_pos, double raydir_x, double raydir_y)
{
    double  delta_x;
    double  delta_y;
    double  side_x;
    double  side_y;
    int     step_x;
    int     step_y;

    // delta_x = 1 / raydir_x;
    // delta_y = 1 / raydir_y;
    // if (raydir_x > 0)
    //     step_x = 1;
    // else if (raydir_x < 0)
    //     step_x = -1;
    // if (raydir_y > 0)
    //     step_y = 1;
    // else if (raydir_y < 0)
    //     step_y = -1;
    while(data->map[i][j])
    {
        //DDA_Algo
        i++;
        j++;
    }

}
