/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:28:06 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/10 17:30:20 by kelmounj         ###   ########.fr       */
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

int	*which_color(t_data *data, char *line)
{
	int	*color_array;

	color_array = NULL;
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		color_array = data->floor_color;
		data->order.f_line = data->order.line_order;
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		color_array = data->ceiling_color;
		data->order.c_line = data->order.line_order;
	}
	return (color_array);
}

int	check_spaces(char *splited)
{
	int	start;
	int	end;

	start = skip_beg_spaces(splited);
	end = skip_end_spaces(splited);
	while (splited[start] && start <= end)
	{
		if (splited[start] == ' ' || splited[start] == '\t')
			return (1);
		start++;
	}
	return (0);
}

void	set_colors(t_data *data, char *line, int i)
{
	char	*colors;
	char	**splited;
	int		*color_array;

	while (*line == ' ' || *line == '\t')
		line++;
	color_array = which_color(data, line);
	colors = extract_content(line + 1);
	if (!check_content(colors))
		ft_error('c');
	splited = ft_split(colors, ',');
	if (!splited || s_array(splited) != 3)
		ft_error('c');
	while (i < 3)
	{
		if (ft_strlen(splited[i]) > 3 && (ft_strlen(splited[i])
				- count_spaces(splited[i]) > 3))
			ft_error('c');
		if (check_spaces(splited[i]))
			ft_error('c');
		color_array[i] = ft_atoi(splited[i]);
		if (color_array[i] < 0 || color_array[i] > 255)
			ft_error('c');
		i++;
	}
}
