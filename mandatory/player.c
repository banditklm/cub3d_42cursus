/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:36:18 by kelmounj          #+#    #+#             */
/*   Updated: 2024/12/30 15:15:48 by kelmounj         ###   ########.fr       */
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
	}
	else if (data->direction == 'S')
	{
		data->player.x_dir = 0;
		data->player.y_dir = 1;
	}
	else if (data->direction == 'E')
	{
		data->player.x_dir = 1;
		data->player.y_dir = 0;
	}
	else if (data->direction == 'W')
	{
		data->player.x_dir = -1;
		data->player.y_dir = 0;
	}
	data->player.fov = pi / 3;
}
// plane width = tan(fov / 2)
// plane_x and plane_y :
// plane_x = dir_y * tan(fov / 2)
// plane_y = -dir_x * tan(fov / 2)