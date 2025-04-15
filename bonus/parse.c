/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:07:03 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/09 12:19:40 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isonly_spaces(char *input)
{
	int	i;

	i = 0;
	while (input && input[i])
	{
		while ((input[i] >= 9 && input[i] <= 13) || input[i] == ' ' )
			i++;
		if (input[i])
			return (0);
	}
	return (1);
}

int	s_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	check_order(t_data *data)
{
	if (data->order.map_line < data->order.c_line
		|| data->order.map_line < data->order.f_line
		|| data->order.map_line < data->order.no_line
		|| data->order.map_line < data->order.so_line
		|| data->order.map_line < data->order.ea_line
		|| data->order.map_line < data->order.we_line
		|| data->order.map_line < data->order.do_line
		|| data->order.map_line < data->order.sp_line)
		return (0);
	return (1);
}

void	parse(t_data *file_data, char *file_name)
{
	int	fd;

	fd = open_cub_file(file_name);
	file_data->no = NULL;
	file_data->so = NULL;
	file_data->ea = NULL;
	file_data->we = NULL;
	file_data->doo = NULL;
	file_data->sp = NULL;
	manip_file(file_data, fd, 0);
	if (!check_order(file_data))
		ft_error('m');
	if (!surrounded_by_walls(file_data->map, 0, 0, 0)
		|| !deep_surr_walls(file_data->map, 0, 0))
		ft_error('m');
	if (!composition_checker(file_data, 0, 0))
		ft_error('m');
	where_doors(file_data);
	where_sprites(file_data);
	map_lenght(file_data);
	map_width(file_data);
}
