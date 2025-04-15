/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:31:53 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/08 18:16:15 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_texture(t_data *data, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		data->no = extract_content(line + 2);
		data->order.no_line = data->order.line_order;
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		data->so = extract_content(line + 2);
		data->order.so_line = data->order.line_order;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		data->ea = extract_content(line + 2);
		data->order.ea_line = data->order.line_order;
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		data->we = extract_content(line + 2);
		data->order.we_line = data->order.line_order;
	}
}

mlx_texture_t	*load_texutes(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error('t');
	return (texture);
}

void	load_all_text(t_data *data)
{
	data->north = load_texutes(data->no);
	data->south = load_texutes(data->so);
	data->east = load_texutes(data->ea);
	data->west = load_texutes(data->we);
}

mlx_texture_t	*get_wall_texture(t_data *data)
{
	if (data->side_wall == 0)
	{
		if (data->ray.rayd_x > 0)
			return (data->east);
		else
			return (data->west);
	}
	else
	{
		if (data->ray.rayd_y > 0)
			return (data->south);
		else
			return (data->north);
	}
}
