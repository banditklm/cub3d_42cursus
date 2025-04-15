/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 02:40:03 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/15 22:31:16 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

mlx_texture_t	*init_values(t_data *data, int frame)
{
	mlx_texture_t	*texture;

	if (!data->is_animating)
		texture = data->frames[0];
	else
		texture = data->frames[frame];
	data->weapon.height = texture->height * 0.5;
	data->weapon.width = texture->width * 0.5;
	data->weapon.start_x = data->screen_width / 2 - data->weapon.width / 2;
	data->weapon.start_y = data->screen_height - data->weapon.height;
	return (texture);
}

void	check_end(t_data *data, int *frame)
{
	if (data->is_animating)
	{
		(*frame)++;
		if (*frame == 1)
		{
			play_s1("afplay bonus/hamas.m4a");
		}
		if (*frame >= 28)
		{
			*frame = 0;
			data->is_animating = false;
		}
	}
}

void	init_values2(t_data *data, mlx_texture_t *texture, int x, int *y)
{
	(1) && (data->weapon.tex_x = (double)(x - data->weapon.start_x) / \
		data->weapon.width * texture->width, *y = data->weapon.start_y);
}

void	update_value(t_data *data, int *index, mlx_texture_t *texture, int y)
{
	(1) && (data->weapon.tex_y = (double)(y - data->weapon.start_y) / \
			data->weapon.height * texture->height, data->weapon.tmp_value = \
			(int)data->weapon.tex_y * texture->width + (int)data->weapon.tex_x \
			, *index = data->weapon.tmp_value * 4);
}

void	put_weapon(t_data *data)
{
	static int		frame = 0;
	mlx_texture_t	*texture;
	int				x;
	int				y;
	int				index;

	(1) && (texture = init_values(data, frame), x = data->weapon.start_x);
	while (x < data->weapon.start_x + data->weapon.width)
	{
		init_values2(data, texture, x, &y);
		while (y < data->screen_height)
		{
			update_value(data, &index, texture, y);
			if (texture->pixels[index + 3] == 0)
			{
				y++;
				continue ;
			}
			data->weapon.color = color_from_pixel(texture, index);
			put_pixel_to_image(data, x, y, data->weapon.color);
			y++;
		}
		x++;
	}
	check_end(data, &frame);
}
