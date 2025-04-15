/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:38:43 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/04 16:39:03 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_steps(t_data *data, int map_x, int map_y)
{
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
}

void	init_dist(t_data *data, int x)
{
	int		map_x;
	int		map_y;

	map_x = (int)data->player.x_pos;
	map_y = (int)data->player.y_pos;
	if (data->ray.rayd_x == 0)
		data->ray.delta_x = INF;
	else
		data->ray.delta_x = fabs(1 / data->ray.rayd_x);
	if (data->ray.rayd_y == 0)
		data->ray.delta_y = INF;
	else
		data->ray.delta_y = fabs(1 / data->ray.rayd_y);
	init_steps(data, map_x, map_y);
	raytrace(data, map_x, map_y, x);
}
