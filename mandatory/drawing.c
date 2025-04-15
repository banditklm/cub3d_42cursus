/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 03:24:45 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/09 15:13:33 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_ceiling(t_data *data, int start_line, int x, int color)
{
	int	y;

	y = start_line;
	while (y >= 0)
	{
		put_pixel_to_image(data, x, y, color);
		y--;
	}
}

void	draw_floor(t_data *data, int end_line, int x, int color)
{
	int	y;

	y = end_line + 1;
	while (y <= data->screen_height)
	{
		put_pixel_to_image(data, x, y, color);
		y++;
	}
}

void	draw_line(t_data *data, double pwd, int x)
{
	data->line_h = (int)(data->screen_height / pwd);
	data->start_line = -data->line_h / 2 + data->screen_height / 2;
	data->end_line = data->line_h / 2 + data->screen_height / 2;
	draw_ceiling(data, data->start_line, x, rgb(data->ceiling_color[0],
			data->ceiling_color[1], data->ceiling_color[2]));
	put_texture(data, data->end_line, data->start_line, x);
	draw_floor(data, data->end_line, x, rgb(data->floor_color[0],
			data->floor_color[1], data->floor_color[2]));
}
