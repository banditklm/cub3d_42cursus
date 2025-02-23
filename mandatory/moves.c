/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:53 by kelmounj          #+#    #+#             */
/*   Updated: 2025/02/23 10:33:51 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int move_up(t_data *data, double move_speed)
{
    double x_next;
    double y_next;

    x_next = (data->player.x_pos + data->player.x_dir * move_speed);
    y_next = (data->player.y_pos + data->player.y_dir * move_speed);
    if ((int)x_next >= 0 && (int)x_next < data->map_width && (int)y_next >= 0 &&
        (int)y_next < data->map_lenght && data->map[(int)(y_next + 0.1)][(int)(x_next + 0.1)] != '1' &&
        data->map[(int)(y_next - 0.1)][(int)(x_next - 0.1)] != '1')
    {
        data->player.x_pos += data->player.x_dir * move_speed;
        data->player.y_pos += data->player.y_dir * move_speed;
    }
    return (1);
}

int move_down(t_data *data, double move_speed)
{
    int x_next;
    int y_next;
    
    x_next = (data->player.x_pos - data->player.x_dir * move_speed);
    y_next = (data->player.y_pos - data->player.y_dir * move_speed);
    if ((int)x_next >= 0 && (int)x_next < data->map_width && (int)y_next >= 0 &&
        (int)y_next < data->map_lenght && data->map[(int)(y_next + 0.1)][(int)(x_next + 0.1)] != '1')
    {
        data->player.x_pos -= data->player.x_dir * move_speed;
        data->player.y_pos -= data->player.y_dir * move_speed;
    }
    return (1);
}

int move_right(t_data *data, double move_speed)
{
    double x_next = data->player.x_pos + data->player.plane_x * move_speed;
    double y_next = data->player.y_pos + data->player.plane_y * move_speed;

    if (data->map[(int)data->player.y_pos][(int)x_next] != '1')
        data->player.x_pos = x_next;
    if (data->map[(int)y_next][(int)data->player.x_pos] != '1')
        data->player.y_pos = y_next;

    return (1);
}


int move_left(t_data *data, double move_speed)
{
    double x_next = data->player.x_pos - data->player.plane_x * move_speed;
    double y_next = data->player.y_pos - data->player.plane_y * move_speed;

    if (data->map[(int)data->player.y_pos][(int)x_next] != '1')
        data->player.x_pos = x_next;
    if (data->map[(int)y_next][(int)data->player.x_pos] != '1')
        data->player.y_pos = y_next;

    return (1);
}

int rot_left(t_data *data, double rot_speed)
{
    double  old_dirx;
    double  old_planex;
    
    old_dirx = data->player.x_dir;
    old_planex = data->player.plane_x;

    data->player.x_dir = data->player.x_dir * cos(-rot_speed) - data->player.y_dir * sin(-rot_speed);
    data->player.y_dir = old_dirx * sin(-rot_speed) + data->player.y_dir * cos(-rot_speed);
    data->player.plane_x = data->player.plane_x * cos(-rot_speed) - data->player.plane_y * sin(-rot_speed);
    data->player.plane_y = old_planex * sin(-rot_speed) + data->player.plane_y * cos(-rot_speed);
    return (1);
}

int rot_right(t_data *data, double rot_speed)
{
    double  old_dirx;
    double  old_planex;
    
    old_dirx = data->player.x_dir;
    old_planex = data->player.plane_x;

    data->player.x_dir = data->player.x_dir * cos(rot_speed) - data->player.y_dir * sin(rot_speed);
    data->player.y_dir = old_dirx * sin(rot_speed) + data->player.y_dir * cos(rot_speed);
    data->player.plane_x = data->player.plane_x * cos(rot_speed) - data->player.plane_y * sin(rot_speed);
    data->player.plane_y = old_planex * sin(rot_speed) + data->player.plane_y * cos(rot_speed);
    return (1);
}

int move_to(int key_code, t_data *data, double move_speed, double rot_speed)
{
    if (key_code == 124)
	{
		rot_right(data, rot_speed);
	}
	if (key_code == 123)
	{
		rot_left(data, rot_speed);
	}
    if (key_code == 2)
    {
        move_right(data, move_speed);
    }
    if (key_code == 0)
    {
        move_left(data, move_speed);
    }
	if (key_code == 13)
	{
		move_up(data, move_speed);
	}
	if (key_code == 1)
	{
		move_down(data, move_speed);
	}
    mlx_close_window(data->mlx_data);
    render_frame(data);
    render_minimap(data);
	return (1);
}

size_t	get_tv(void)
{
	struct timeval	tv;
	size_t			res;

	if (gettimeofday(&tv, NULL) == -1)
		write(2, "Error in time\n", 14);
	res = tv.tv_usec / 1000 + tv.tv_sec * 1000;
	return (res);
}

// int mouse_move(int x, int y, t_data *data)
// {
//     (void)y;
//    static int     last_x = -1;
//     double  old_dirx;
//     double  old_planex;
//     double  rot_speed;
    
//     // printf("mouse mouvement x: %d\ty: %d\n", x, y);
//     if (last_x == -1)
//     {
//         last_x = x;
//         return (0);
//     }
//     rot_speed = (x - last_x) * 0.001;
//     old_dirx = data->player.x_dir;
//     old_planex = data->player.plane_x;

//     data->player.x_dir = data->player.x_dir * cos(-rot_speed) - data->player.y_dir * sin(-rot_speed);
//     data->player.y_dir = old_dirx * sin(-rot_speed) + data->player.y_dir * cos(-rot_speed);
//     data->player.plane_x = data->player.plane_x * cos(-rot_speed) - data->player.plane_y * sin(-rot_speed);
//     data->player.plane_y = old_planex * sin(-rot_speed) + data->player.plane_y * cos(-rot_speed);
//     last_x = x;
//     return (0);
// }

int move(int key_code, t_data *data)
{
    // static long old_time = 0;
    // long current_time;
    // double  frame_time;
    double  move_speed;
    double  rot_speed;

    // current_time = get_tv();
    // if (old_time == 0)
    //     old_time = current_time;
    // frame_time = (current_time - old_time) / 1000.0;
    // old_time = current_time;
    move_speed = 0.2;
    rot_speed = 0.05;
    move_to(key_code, data, move_speed, rot_speed);
    return (0);
}
