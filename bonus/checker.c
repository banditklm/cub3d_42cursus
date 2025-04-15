/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:35:35 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/10 11:17:11 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_doors(t_data *data)
{
	int		i;
	double	dist;

	i = 0;
	while (i < data->n_of_doors)
	{
		dist = distance(data->player.x_pos, data->player.y_pos, \
			data->doors[i].x, data->doors[i].y);
		if (dist < DOOR_OPEN_DIST)
			data->doors[i].is_open = 1;
		else
			data->doors[i].is_open = 0;
		i++;
	}
}

t_door	*find_which_door(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < data->n_of_doors)
	{
		if (data->doors[i].x == x && data->doors[i].y == y)
			return (&data->doors[i]);
		i++;
	}
	return (NULL);
}

void	check_steps(t_data *data, int *map_x, int *map_y, int *sid_w)
{
	if (data->ray.side_x < data->ray.side_y)
	{
		data->ray.side_x += data->ray.delta_x;
		*map_x += data->ray.step_x;
		*sid_w = 0;
	}
	else
	{
		data->ray.side_y += data->ray.delta_y;
		*map_y += data->ray.step_y;
		*sid_w = 1;
	}
}

void	check_dr_or_sp(t_data *data, int map_x, int map_y, int *hit_w)
{
	t_door	*door;

	if (data->map[map_y][map_x] == '1' || data->map[map_y][map_x] == 'D'
		|| data->map[map_y][map_x] == 'A')
	{
		if (data->map[map_y][map_x] == 'D')
		{
			door = find_which_door(data, map_x, map_y);
			if (door && !door->is_open)
			{
				*hit_w = 1;
				data->hit_d = 1;
			}
		}
		else if (data->map[map_y][map_x] == 'A')
		{
			data->hit_s = 1;
			*hit_w = 1;
		}
		else
			*hit_w = 1;
	}
}
