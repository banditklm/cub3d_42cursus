/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:25:32 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/09 14:38:16 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_destroy_win(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	c_malloc(0, 0);
	mlx_close_window(data->mlx);
	exit(0);
}
