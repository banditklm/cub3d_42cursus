/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:13:32 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/09 11:41:18 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	skip_beg_spaces(char *row)
{
	int	i;

	i = 0;
	while (row[i] && row[i] == ' ')
		i++;
	return (i);
}

int	skip_end_spaces(char *row)
{
	int	i;

	i = ft_strlen(row) - 1;
	while (i && row[i] == ' ')
		i--;
	return (i);
}

int	surrounded_by_walls(char **map, int i, int j, int k)
{
	i = skip_beg_spaces(map[0]);
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != ' ' && map[0][i] != '\n')
			return (0);
		i++;
	}
	i = skip_beg_spaces(map[s_array(map) - 1]);
	while (map[s_array(map) - 1][i])
	{
		if (map[s_array(map) - 1][i] != '1' && map[s_array(map) - 1][i] != ' '
			&& map[s_array(map) - 1][i] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		j = skip_beg_spaces(map[i]);
		k = skip_end_spaces(map[i]);
		if (map[i][j] != '1' || map[i][k] != '1')
			return (0);
		i++;
	}
	return (1);
}
