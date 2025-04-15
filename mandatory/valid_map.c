/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:39 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/09 11:43:21 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_prev_line_bounds(int i, char **map, int curr_line_len)
{
	int		prev_line_len;
	char	c;

	if (i == 0)
		prev_line_len = 0;
	else
		prev_line_len = ft_strlen(map[i - 1]);
	if (prev_line_len > curr_line_len)
	{
		while (curr_line_len < prev_line_len)
		{
			c = map[i - 1][curr_line_len];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
				return (0);
			curr_line_len++;
		}
	}
	return (1);
}

static int	check_next_line_bounds(int i, char **map, int curr_line_len)
{
	int		next_line_len;
	char	c;

	if (!map[i + 1])
		next_line_len = 0;
	else
		next_line_len = ft_strlen(map[i + 1]);
	if (next_line_len > curr_line_len)
	{
		while (curr_line_len < next_line_len)
		{
			c = map[i + 1][curr_line_len];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
				return (0);
			curr_line_len++;
		}
	}
	return (1);
}

int	out_bounds(int i, char **map)
{
	int	curr_line_len;

	curr_line_len = ft_strlen(map[i]);
	if (!check_prev_line_bounds(i, map, curr_line_len))
		return (0);
	if (!check_next_line_bounds(i, map, curr_line_len))
		return (0);
	return (1);
}

int	deep_surr_walls(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		if (!out_bounds(i, map))
			return (0);
		while (map[i][j])
		{
			if (i != 0 && j != 0 && j < ft_strlen(map[i]) && map[i + 1])
			{
				if (map[i][j] == '0' || map[i][j] == 'E' || map[i][j] == 'N'
					|| map[i][j] == 'S' || map[i][j] == 'S')
				{
					if (is_space(map[i][j - 1]) || is_space(map[i][j + 1])
						|| is_space(map[i - 1][j]) || is_space(map[i + 1][j]))
						return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	composition_checker(t_data *data, int i, int j, int p_counter)
{
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
					&& data->map[i][j] != ' ' && data->map[i][j] != 'N'
					&& data->map[i][j] != 'S' && data->map[i][j] != 'E'
					&& data->map[i][j] != 'W' && data->map[i][j] != '\n')
				return (0);
			if (data->map[i][j] == 'S' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				p_counter++;
				data->x_player = j;
				data->y_player = i;
				data->direction = data->map[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (p_counter != 1)
		return (0);
	return (1);
}
