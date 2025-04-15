/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:32:41 by kelmounj          #+#    #+#             */
/*   Updated: 2025/03/28 06:35:15 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycast(t_data *data)
{
	double	camera_x;
	int		i;

	i = 0;
	while (i < data->screen_width)
	{
		camera_x = 2 * i / (double)data->screen_width - 1;
		data->ray.rayd_x = data->player.x_dir + data->player.plane_x * camera_x;
		data->ray.rayd_y = data->player.y_dir + data->player.plane_y * camera_x;
		init_dist(data, i);
		i++;
	}
}

void	check_side_wall(t_data *data, double *pwd, int side_wall)
{
	if (side_wall == 0)
		(1) && (*pwd = data->ray.side_x - data->ray.delta_x,
			data->tex_pos_x = data->player.y_pos
				+ *pwd * data->ray.rayd_y);
	else
		(1) && (*pwd = data->ray.side_y - data->ray.delta_y,
			data->tex_pos_x = data->player.x_pos
				+ *pwd * data->ray.rayd_x);
	(1) && (data->tex_pos_x -= floor(data->tex_pos_x),
		data->side_wall = side_wall);
}

void	raytrace(t_data *data, int map_x, int map_y, int x)
{
	bool	hit_wall;
	double	pwd;
	int		side_wall;

	(1) && (hit_wall = 0, pwd = 0.0, side_wall = -1);
	while (hit_wall == 0)
	{
		if (data->ray.side_x < data->ray.side_y)
			(1) && (data->ray.side_x += data->ray.delta_x
				, map_x += data->ray.step_x, side_wall = 0);
		else
			(1) && (data->ray.side_y += data->ray.delta_y
				, map_y += data->ray.step_y, side_wall = 1);
		if (map_x < 0 || map_x >= data->map_width || map_y < 0
			|| map_y >= data->map_lenght)
		{
			hit_wall = 1;
			break ;
		}
		if (data->map[map_y][map_x] == '1')
			hit_wall = 1;
	}
	check_side_wall(data, &pwd, side_wall);
	draw_line(data, pwd, x);
}

void	init_steps(t_data *data, int mapx, int mapy)
{
	if (data->ray.rayd_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_x = (data->player.x_pos - mapx) * data->ray.delta_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_x = (mapx + 1 - data->player.x_pos) * data->ray.delta_x;
	}
	if (data->ray.rayd_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_y = (data->player.y_pos - mapy) * data->ray.delta_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_y = (mapy + 1 - data->player.y_pos) * data->ray.delta_y;
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
