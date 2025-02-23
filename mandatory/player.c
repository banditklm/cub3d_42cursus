/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:36:18 by kelmounj          #+#    #+#             */
/*   Updated: 2025/02/17 14:10:59 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_data *data)
{
	data->player.x_pos = data->x_player;
	data->player.y_pos = data->y_player;
	if (data->direction == 'N')
	{
		data->player.x_dir = 0;
		data->player.y_dir = -1;
		data->player.plane_x = 0.66;
    	data->player.plane_y = 0;
	}
	else if (data->direction == 'S')
	{
		data->player.x_dir = 0;
		data->player.y_dir = 1;
		data->player.plane_x = -0.66;
    	data->player.plane_y = 0;
	}
	else if (data->direction == 'E')
	{
		data->player.x_dir = 1;
		data->player.y_dir = 0;
		data->player.plane_x = 0;
    	data->player.plane_y = 0.66;
	}
	else if (data->direction == 'W')
	{
		data->player.x_dir = -1;
		data->player.y_dir = 0;
		data->player.plane_x = 0;
    	data->player.plane_y = -0.66;
	}
}

void	init_data(t_data *data)
{
	data->screen_width = data->map_width * 60;
    data->screen_height = data->map_lenght * 60;
	if (data->fov <= 0)
		data->player.fov = pi / 3;
}
