/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:58:31 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/10 16:00:31 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_content(char *colors)
{
	int	i;
	int	track;

	i = 0;
	track = 0;
	while (colors && colors[i])
	{
		if (colors[i] != ' ' && colors[i] != '\n' && colors[i] != '\t'
			&& colors[i] != ',' && !ft_isdigit(colors[i]))
			return (0);
		if (colors[i] == ',')
			track++;
		if (track > 3)
			return (0);
		i++;
	}
	return (1);
}

static int	*select_color_array(t_data *data, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		data->order.f_line = data->order.line_order;
		return (data->floor_color);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		data->order.c_line = data->order.line_order;
		return (data->ceiling_color);
	}
	return (NULL);
}

static void	parse_color_values(int *color_array, char *colors)
{
	char	**splited;
	int		i;

	i = 0;
	if (!check_content(colors))
		ft_error('c');
	splited = ft_split(colors, ',');
	if (!splited || s_array(splited) != 3)
		ft_error('c');
	while (i < 3)
	{
		if (ft_strlen(splited[i]) > 3
			&& (ft_strlen(splited[i]) - count_spaces(splited[i]) > 3))
			ft_error('c');
		if (check_spaces(splited[i]))
			ft_error('c');
		color_array[i] = ft_atoi(splited[i]);
		if (color_array[i] < 0 || color_array[i] > 255)
			ft_error('c');
		i++;
	}
}

void	set_colors(t_data *data, char *line)
{
	char	*colors;
	int		*color_array;

	color_array = select_color_array(data, line);
	if (!color_array)
		return ;
	colors = extract_content(line + 1);
	parse_color_values(color_array, colors);
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
