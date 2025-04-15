/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:50:08 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/10 17:30:50 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_valid_map_char(char c)
{
	return (c == '0' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == 'D');
}

static int	check_previous_line(int i, char **map, int curr_len)
{
	int	prev_len;

	if (i == 0)
		prev_len = 0;
	else
		prev_len = ft_strlen(map[i - 1]);
	if (prev_len > curr_len)
	{
		while (curr_len < prev_len)
		{
			if (is_valid_map_char(map[i - 1][curr_len]))
				return (0);
			curr_len++;
		}
	}
	return (1);
}

static int	check_next_line(int i, char **map, int curr_len)
{
	int	next_len;

	if (!map[i + 1])
		next_len = 0;
	else
		next_len = ft_strlen(map[i + 1]);
	if (next_len > curr_len)
	{
		while (curr_len < next_len)
		{
			if (is_valid_map_char(map[i + 1][curr_len]))
				return (0);
			curr_len++;
		}
	}
	return (1);
}

int	out_bounds(int i, char **map)
{
	int	curr_len;

	curr_len = ft_strlen(map[i]);
	if (!check_previous_line(i, map, curr_len))
		return (0);
	if (!check_next_line(i, map, curr_len))
		return (0);
	return (1);
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
