/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 05:48:12 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/10 10:52:20 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_error(char type)
{
	if (type == 'f')
		ft_putstr_fd("Error\nError in file structure\n", 2);
	else if (type == 'm')
		ft_putstr_fd("Error\nError in map\n", 2);
	else if (type == 'a')
		ft_putstr_fd("Error\nError in allocation\n", 2);
	else if (type == 'c')
		ft_putstr_fd("Error\nError in colors\n", 2);
	else if (type == 't')
		ft_putstr_fd("Error\nError in textures\n", 2);
	else if (type == 'o')
		ft_putstr_fd("Error\nError opening the file\n", 2);
	if (type != 'o')
		c_malloc(0, 0);
	exit(1);
}

int	open_cub_file(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_error('o');
	}
	return (fd);
}

void	check_file_ext(char *str)
{
	while (*str)
	{
		if (*str == '.' && ft_strcmp(str, ".cub") == 0)
			return ;
		str++;
	}
	ft_putstr_fd("Error\nInvalid .cub extension\n", 2);
	exit(1);
}

void	init_player(t_data *data)
{
	data->player.x_pos = data->x_player + 0.5;
	data->player.y_pos = data->y_player + 0.5;
	if (data->direction == 'N')
	{
		(1) && (data->player.x_dir = 0, data->player.y_dir = -1);
		(1) && (data->player.plane_x = 0.66, data->player.plane_y = 0);
	}
	else if (data->direction == 'S')
	{
		(1) && (data->player.x_dir = 0, data->player.y_dir = 1);
		(1) && (data->player.plane_x = -0.66, data->player.plane_y = 0);
	}
	else if (data->direction == 'E')
	{
		(1) && (data->player.x_dir = 1, data->player.y_dir = 0);
		(1) && (data->player.plane_x = 0, data->player.plane_y = 0.66);
	}
	else if (data->direction == 'W')
	{
		(1) && (data->player.x_dir = -1, data->player.y_dir = 0);
		(1) && (data->player.plane_x = 0, data->player.plane_y = -0.66);
	}
}

void	init_data(t_data *data)
{
	data->screen_width = SCREEN_WIDTH;
	data->screen_height = SCREEN_HEIGHT;
	data->is_animating = false;
	data->is_play = false;
}
