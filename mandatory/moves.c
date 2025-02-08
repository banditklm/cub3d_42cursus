/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:53 by kelmounj          #+#    #+#             */
/*   Updated: 2025/02/08 16:03:12 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int move_right(t_data *data, int i, int j)
// {
//     if (data->map[i][j] == 'W' || data->map[i][j] == 'E' || data->map[i][j] == 'S' || data->map[i][j] == 'N')
//     {
        
//     }
// }

int move_up(t_data *data, int i, int j, double move_speed)
{
    if ((data->map[i][j] == 'W' || data->map[i][j] == 'E' || data->map[i][j] == 'S' || data->map[i][j] == 'N') && data->map[i - 1][j] != 1)
    {
        data->player.x_pos += data->player.x_dir * move_speed;
        data->player.y_pos += data->player.y_dir * move_speed;
    }
    return (1);
}

int move_to(int key_code, t_data *data, int i, int j, double move_speed)
{
    // if (key_code == 2 || key_code == 124)
	// {
	// 	if (move_right(data, i, j))
	// 		return (0);
	// }
	// else if (key_code == 0 || key_code == 123)
	// {
	// 	if (move_left(data, i, j))
	// 		return (0);
	// }
	if (key_code == 13 || key_code == 126)
	{
		if (move_up(data, i, j, move_speed))
			return (0);
	}
	// else if (key_code == 1 || key_code == 125)
	// {
	// 	if (move_down(data, i, j))
	// 		return (0);
	// }
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

int move(int key_code, t_data *data)
{
    int i;
    int j;
    long old_time;
    long current_time;
    double  frame_time;
    double  move_speed;

    current_time = get_tv();
    old_time = 0;
    frame_time = (current_time - old_time) / 1000.0;
    old_time = current_time;
    move_speed = frame_time * 2.0;
    usleep(16000);
    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            move_to(key_code, data, i, j, move_speed);
            j++;
        }
        i++;
    }
    return (0);
}