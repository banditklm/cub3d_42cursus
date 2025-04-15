/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:32:41 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/09 15:13:33 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	raycast(t_data *data)
{
	double	camerax;
	int		i;

	i = 0;
	while (i < data->screen_width)
	{
		camerax = 2 * i / (double)data->screen_width - 1;
		data->ray.rayd_x = data->player.x_dir + data->player.plane_x * camerax;
		data->ray.rayd_y = data->player.y_dir + data->player.plane_y * camerax;
		init_dist(data, i);
		i++;
	}
}

int	color_from_pixel(mlx_texture_t *texture, int index)
{
	int	r;
	int	g;
	int	b;

	r = texture->pixels[index];
	g = texture->pixels[index + 1];
	b = texture->pixels[index + 2];
	return (rgb(r, g, b));
}

void	ft_put_pixel(t_data *data, uint32_t x,
	uint32_t y, uint32_t color)
{
	if (x >= 0 && x < (uint32_t)data->screen_width
		&& y >= 0 && y < (uint32_t)data->screen_height)
		mlx_put_pixel(data->img, x, y, color);
}

void	put_texture(t_data *data, int end_line, int start_line, int x)
{
	mlx_texture_t	*texture;
	int				tmp_start;
	int				tmp_end;
	uint32_t		tmp_value;
	int				index;

	(1) && (tmp_start = start_line, tmp_end = end_line);
	if (data->hit_d)
		texture = data->door;
	else if (data->hit_s)
		texture = data->sprite;
	else
		texture = get_wall_texture(data);
	data->tex_pos_x *= texture->width;
	if (data->side_wall == 1 && data->ray.rayd_y < 0)
		data->tex_pos_x = texture->width - data->tex_pos_x - 1;
	while (start_line < end_line)
	{
		(1) && (data->tex_pos_y = (start_line - tmp_start) / (double)(tmp_end \
		- tmp_start), data->tex_pos_y *= texture->height, tmp_value = (int) \
		data->tex_pos_y * texture->width, tmp_value += (int)data->tex_pos_x, \
		index = tmp_value * 4, data->color = color_from_pixel(texture, index));
		put_pixel_to_image(data, x, start_line, data->color);
		start_line++;
	}
}

void	raytrace(t_data *data, int map_x, int map_y, int x)
{
	int		hit_w;
	double	pwd;
	int		sid_w;

	(1) && (hit_w = 0, pwd = 0.0, sid_w = -1, data->hit_d = 0, data->hit_s = 0);
	while (hit_w == 0)
	{
		check_steps(data, &map_x, &map_y, &sid_w);
		if (map_x < 0 || map_x >= data->map_width || map_y < 0
			|| map_y >= data->map_lenght)
		{
			hit_w = 1;
			break ;
		}
		check_dr_or_sp(data, map_x, map_y, &hit_w);
	}
	(1) && (data->ray.map_x = map_x, data->ray.map_y = map_y);
	if (sid_w == 0)
		(1) && (pwd = data->ray.side_x - data->ray.delta_x, \
		data->tex_pos_x = data->player.y_pos + pwd * data->ray.rayd_y);
	else
		(1) && (pwd = data->ray.side_y - data->ray.delta_y, \
		data->tex_pos_x = data->player.x_pos + pwd * data->ray.rayd_x);
	(1) && (data->tex_pos_x -= floor(data->tex_pos_x), data->side_wall = sid_w);
	draw_line(data, pwd, x);
}
