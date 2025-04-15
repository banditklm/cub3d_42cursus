/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:07:38 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/04 15:08:35 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rot_left(t_data *data, double rot_speed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->player.x_dir;
	old_planex = data->player.plane_x;
	data->player.x_dir = data->player.x_dir \
		* cos(-rot_speed) - data->player.y_dir * sin(-rot_speed);
	data->player.y_dir = old_dirx * sin(-rot_speed) \
		+ data->player.y_dir * cos(-rot_speed);
	data->player.plane_x = data->player.plane_x \
		* cos(-rot_speed) - data->player.plane_y * sin(-rot_speed);
	data->player.plane_y = old_planex * sin(-rot_speed) \
		+ data->player.plane_y * cos(-rot_speed);
	return (1);
}

int	rot_right(t_data *data, double rot_speed)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->player.x_dir;
	old_planex = data->player.plane_x;
	data->player.x_dir = data->player.x_dir * cos(rot_speed) \
		- data->player.y_dir * sin(rot_speed);
	data->player.y_dir = old_dirx * sin(rot_speed) \
		+ data->player.y_dir * cos(rot_speed);
	data->player.plane_x = data->player.plane_x \
		* cos(rot_speed) - data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_planex * sin(rot_speed) \
		+ data->player.plane_y * cos(rot_speed);
	return (1);
}

void	move_to(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->key.right)
		rot_right(data, SPEED_ROT);
	if (data->key.left)
		rot_left(data, SPEED_ROT);
	if (data->key.d)
		move_right(data, SPEED_MOVE);
	if (data->key.a)
		move_left(data, SPEED_MOVE);
	if (data->key.w)
		move_up(data, SPEED_MOVE);
	if (data->key.s)
		move_down(data, SPEED_MOVE);
}
