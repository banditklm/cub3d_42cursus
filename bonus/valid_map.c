/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:22:39 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/09 12:51:15 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	deep_surr_walls(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		if (!out_bounds(i, map))
		{
			return (0);
		}
		while (map[i][j])
		{
			if (i != 0 && j != 0 && j < ft_strlen(map[i]) && map[i + 1])
			{
				if (map[i][j] == '0' || map[i][j] == 'E' || map[i][j] == 'N'
					|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'D')
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

static int	valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == 'D' || c == 'A'
		|| c == '\n');
}

static int	process_map_char(t_data *data, int i, int j, int *p_counter)
{
	char	current;

	current = data->map[i][j];
	if (!valid_map_char(current))
		return (0);
	if (current == 'N' || current == 'S'
		|| current == 'E' || current == 'W')
	{
		(*p_counter)++;
		data->x_player = j;
		data->y_player = i;
		data->direction = current;
	}
	else if (current == 'D')
		data->n_of_doors++;
	else if (current == 'A')
		data->sprite_n++;
	return (1);
}

int	composition_checker(t_data *data, int i, int j)
{
	int	p_counter;

	data->n_of_doors = 0;
	data->sprite_n = 0;
	p_counter = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (!process_map_char(data, i, j, &p_counter))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (p_counter != 1)
		return (0);
	return (1);
}
