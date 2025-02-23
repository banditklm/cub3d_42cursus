/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:32:41 by kelmounj          #+#    #+#             */
/*   Updated: 2025/02/21 11:23:27 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    raycast(t_data *data)
{
    double   camera_x;
    int      i;

    i = 0;
    while (i < data->screen_width)
    {
        camera_x = 2 * i / (double)data->screen_width - 1;
        data->ray.rayd_x = data->player.x_dir + data->player.plane_x * camera_x;
        data->ray.rayd_y = data->player.y_dir  + data->player.plane_y * camera_x;
        init_dist(data, i);
        i++;
    }
}

void put_pixel_to_image(t_data *data, int x, int y, int color)
{
    if (x >= 0 && x < data->screen_width && y >= 0 && y < data->screen_height)
    {
        int offset = (y * data->img.size_line) + (x * (data->img.bits_per_pixel / 8));
        *(unsigned int *)(data->img.buffer + offset) = color;
    }
}

void draw_ceiling(t_data *data,int start_line, int x, int color)
{
    int y;

    y = 0;
    while (y < start_line)
    {
        int offset = (y * data->img.size_line) + (x * (data->img.bits_per_pixel / 8));
        *(unsigned int *)(data->img.buffer + offset) = color;
        y++;
    }
}
void draw_floor(t_data *data,int end_line, int x, int color)
{
    int y;

    y = end_line + 1;
    while (y < data->screen_height)
    {
        int offset = (y * data->img.size_line) + (x * (data->img.bits_per_pixel / 8));
        if (offset >= (data->img.size_line * data->screen_height))
            return;
        *(unsigned int *)(data->img.buffer + offset) = color;
        y++;
    }
}

void draw_line(t_data *data, double perpWallDist, int x)
{
    int line_h;
    int start_line;
    int end_line;
    int color;
    int i;

    line_h = (int)(data->screen_height / perpWallDist);
    start_line = -line_h / 2 + data->screen_height / 2;
    if (start_line < 0)
        start_line = 0;
    end_line = line_h / 2 + data->screen_height / 2;
    if (end_line >= data->screen_height)
        end_line = data->screen_height - 1;
    draw_ceiling(data, start_line, x, 0x000000);
    draw_floor(data, end_line, x, 0x228B22);
    color = 0xC5A5AD;
    i = start_line;
    while (i <= end_line)
    {
       put_pixel_to_image(data, x, i, color);
       i++;
    }
}

void    raytrace(t_data *data, int map_x, int map_y, int x)
{
    bool    hit_wall;
    double  perpWallDist;
    int     side_wall;

    hit_wall = 0;
    side_wall = -1;
    perpWallDist = 0.0;
    while (hit_wall == 0)
    {
        if (data->ray.side_x < data->ray.side_y)
        {
            data->ray.side_x += data->ray.delta_x;
            map_x += data->ray.step_x;
            side_wall = 0;
        }
        else
        {
            data->ray.side_y += data->ray.delta_y;
            map_y += data->ray.step_y;
            side_wall = 1;
        }
        if (map_x < 0 || map_x >= data->map_width || map_y < 0 || map_y >= data->map_lenght)
        {
            hit_wall = 1;
            return;
        }
        if (data->map[map_y][map_x] == '1')
            hit_wall = 1;
    }
    if (side_wall == 0)
        perpWallDist = data->ray.side_x - data->ray.delta_x;
    else
        perpWallDist = (data->ray.side_y) - (data->ray.delta_y);
    draw_line(data,perpWallDist, x);
}

void    init_dist(t_data *data, int x)
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
    raytrace(data, map_x, map_y, x);
}


