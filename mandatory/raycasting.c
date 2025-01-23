/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:32:41 by kelmounj          #+#    #+#             */
/*   Updated: 2025/01/23 10:49:41 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    raycast(t_data *data)
{
    double   camera_x;
    int      i;

    data->player.plane_x = -data->player.y_dir * tan(data->fov / 2);
    data->player.plane_y = data->player.x_dir * tan(data->fov / 2);
    while (i < data->screen_width)
    {
        camera_x = 2 * i / data->screen_width - 1; // may cast to double
        data->ray.rayd_x = data->player.x_dir + data->player.plane_x * camera_x;
        data->ray.rayd_y = data->player.y_dir  + data->player.plane_y * camera_x;
        // init_dist();
    }
}

void    init_dist(t_data *data)
{
    int     map_x;
    int     map_y;

    map_x = (int)data->player.x_pos;
    map_y = (int)data->player.y_pos;
    if (data->ray.rayd_x == 0)
        data->ray.delta_x = inf;
    else
        data->ray.delta_x = fabs(1 / data->ray.rayd_x);
    if (data->ray.rayd_y == 0)
        data->ray.delta_y = inf;
    else
        data->ray.delta_y = fabs(1 / data->ray.rayd_y);
    if (data->ray.rayd_x < 0)
    {
        data->ray.step_x = -1;
        data->ray.side_x = (data->player.x_pos - map_x) * data->ray.delta_x;
    }
    else
    {
        data->ray.step_x = 1;
        data->ray.side_x = (map_x + 1 - data->player.x_pos) * data->ray.delta_x;
    }
    if (data->ray.rayd_y < 0)
    {
        data->ray.step_y = -1;
        data->ray.side_y = (data->player.y_pos - map_y) * data->ray.delta_y;
    }
    else
    {
        data->ray.step_y = 1;
        data->ray.side_y = (map_y + 1 - data->player.y_pos) * data->ray.delta_y;
    }
    raytrace(data, map_x, map_y);
}

void    raytrace(t_data *data, int map_x, int map_y)
{
    bool    hit_wall;

    hit_wall = 0;
    while (hit_wall == 0)
    {
        if (data->ray.side_x < data->ray.side_y)
        {
            data->ray.side_x += data->ray.delta_x;
            map_x += data->ray.step_x;
            data->ray.side_wall = 0;
        }
        else
        {
            data->ray.side_y += data->ray.delta_y;
            map_y += data->ray.step_y;
            data->ray.side_wall = 1;
        }
        if (data->map[map_x][map_y] > 0)
            hit_wall = 1;
    }
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