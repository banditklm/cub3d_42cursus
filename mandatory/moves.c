/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:53 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/08 22:39:40 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	move_up(t_data *data, double move_speed)
{
	double	x_next;
	double	y_next;

	x_next = (data->player.x_pos + data->player.x_dir * move_speed);
	y_next = (data->player.y_pos + data->player.y_dir * move_speed);
	if ((int)x_next >= 0 && (int)x_next < data->map_width && (int)y_next >= 0
		&& (int)y_next < data->map_lenght
		&& data->map[(int)(y_next + 0.1)][(int)(x_next + 0.1)] != '1'
		&& data->map[(int)(y_next - 0.1)][(int)(x_next - 0.1)] != '1'
		&& data->map[(int)(y_next + 0.1)][(int)(x_next + 0.1)] != ' '
		&& data->map[(int)(y_next - 0.1)][(int)(x_next - 0.1)] != ' ')
	{
		data->player.x_pos = x_next;
		data->player.y_pos = y_next;
	}
	return (1);
}

int	move_down(t_data *data, double move_speed)
{
	int	x_next;
	int	y_next;

	x_next = (data->player.x_pos - data->player.x_dir * move_speed);
	y_next = (data->player.y_pos - data->player.y_dir * move_speed);
	if ((int)x_next >= 0 && (int)x_next < data->map_width && (int)y_next >= 0
		&& (int)y_next < data->map_lenght
		&& data->map[(int)(y_next + 0.1)][(int)(x_next + 0.1)] != '1'
		&& data->map[(int)(y_next + 0.1)][(int)(x_next + 0.1)] != ' ')
	{
		data->player.x_pos -= data->player.x_dir * move_speed;
		data->player.y_pos -= data->player.y_dir * move_speed;
	}
	return (1);
}

int	move_right(t_data *data, double move_speed)
{
	double	x_next;
	double	y_next;

	x_next = data->player.x_pos + data->player.plane_x * move_speed;
	y_next = data->player.y_pos + data->player.plane_y * move_speed;
	if (data->map[(int)data->player.y_pos][(int)x_next] != '1'
		&& data->map[(int)data->player.y_pos][(int)x_next] != ' ')
		data->player.x_pos += data->player.plane_x * move_speed;
	if (data->map[(int)y_next][(int)data->player.x_pos] != '1'
		&& data->map[(int)y_next][(int)data->player.x_pos] != ' ')
		data->player.y_pos += data->player.plane_y * move_speed;
	return (1);
}

int	move_left(t_data *data, double move_speed)
{
	double	x_next;
	double	y_next;

	x_next = data->player.x_pos - data->player.plane_x * move_speed;
	y_next = data->player.y_pos - data->player.plane_y * move_speed;
	if (data->map[(int)data->player.y_pos][(int)x_next] != '1'
		&& data->map[(int)data->player.y_pos][(int)x_next] != ' ')
		data->player.x_pos -= data->player.plane_x * move_speed;
	if (data->map[(int)y_next][(int)data->player.x_pos] != '1'
		&& data->map[(int)y_next][(int)data->player.x_pos] != ' ')
		data->player.y_pos -= data->player.plane_y * move_speed;
	return (1);
}
