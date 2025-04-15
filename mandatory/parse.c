/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:17:00 by cbajji            #+#    #+#             */
/*   Updated: 2025/04/08 18:28:10 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		|| data->order.map_line < data->order.we_line)
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
	manip_file(file_data, fd, 0);
	if (!check_order(file_data))
		ft_error('m');
	if (!surrounded_by_walls(file_data->map, 0, 0, 0)
		|| !deep_surr_walls(file_data->map, 0, 0))
		ft_error('m');
	if (!composition_checker(file_data, 0, 0, 0))
		ft_error('m');
	map_lenght(file_data);
	map_width(file_data);
}
