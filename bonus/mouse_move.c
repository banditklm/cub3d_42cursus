/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:22:47 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/04 15:31:24 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	mouse_move2(t_data *data, double old_dirx, double old_planex)
{
	data->player.x_dir = data->player.x_dir * cos(-SPEED_MOS) \
		- data->player.y_dir * sin(-SPEED_MOS);
	data->player.y_dir = old_dirx * sin(-SPEED_MOS) \
		+ data->player.y_dir * cos(-SPEED_MOS);
	data->player.plane_x = data->player.plane_x * cos(-SPEED_MOS) \
	- data->player.plane_y * sin(-SPEED_MOS);
	data->player.plane_y = old_planex * sin(-SPEED_MOS) \
		+ data->player.plane_y * cos(-SPEED_MOS);
}

static void	mouse_move3(t_data *data, double old_dirx, double old_planex)
{
	data->player.x_dir = data->player.x_dir * cos(SPEED_MOS) \
		- data->player.y_dir * sin(SPEED_MOS);
	data->player.y_dir = old_dirx * sin(SPEED_MOS) \
		+ data->player.y_dir * cos(SPEED_MOS);
	data->player.plane_x = data->player.plane_x * cos(SPEED_MOS) \
		- data->player.plane_y * sin(SPEED_MOS);
	data->player.plane_y = old_planex * sin(SPEED_MOS) \
		+ data->player.plane_y * cos(SPEED_MOS);
}

void	mouse_move(double x, double y, void *param)
{
	static int	last_x = -1;
	double		old_dirx;
	double		old_planex;
	t_data		*data;

	data = (t_data *)param;
	if (last_x < 0 || last_x > data->screen_width
		|| y > data->screen_height || y < 0)
	{
		last_x = x;
		return ;
	}
	(1) && (old_dirx = data->player.x_dir, old_planex = data->player.plane_x);
	if (last_x > x)
		mouse_move2(data, old_dirx, old_planex);
	else
		mouse_move3(data, old_dirx, old_planex);
	last_x = x;
}
