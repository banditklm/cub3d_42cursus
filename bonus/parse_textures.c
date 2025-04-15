/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:04:19 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/09 12:06:29 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_texture2(t_data *data, char *line)
{
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		data->we = extract_content(line + 2);
		data->order.we_line = data->order.line_order;
	}
	else if (ft_strncmp(line, "D ", 2) == 0)
	{
		data->doo = extract_content(line + 1);
		data->order.do_line = data->order.line_order;
	}
	else if (ft_strncmp(line, "SP ", 3) == 0)
	{
		data->sp = extract_content(line + 2);
		data->order.sp_line = data->order.line_order;
	}
}

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
	else if (ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "D ", 2) == 0
		|| ft_strncmp(line, "SP ", 3) == 0)
		set_texture2(data, line);
}

mlx_texture_t	*load_texutes(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error('t');
	return (texture);
}

void	load_frames(t_data *data)
{
	int		i;
	char	*s;
	char	*path;

	i = 1;
	while (i <= 30)
	{
		s = ft_itoa(i);
		path = ft_strjoin("bonus/textures/weapon/", ft_strjoin(s, ".png"));
		data->frames[i - 1] = load_texutes(path);
		i++;
	}
}

void	load_all_text(t_data *data)
{
	data->north = load_texutes(data->no);
	data->south = load_texutes(data->so);
	data->east = load_texutes(data->ea);
	data->west = load_texutes(data->we);
	data->door = load_texutes(data->doo);
	data->sprite = load_texutes(data->sp);
}
