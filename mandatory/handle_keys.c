/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:50:38 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/09 14:25:24 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_keys(t_data *data)
{
	data->key.a = false;
	data->key.d = false;
	data->key.w = false;
	data->key.s = false;
	data->key.left = false;
	data->key.right = false;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_RIGHT)
			data->key.right = true;
		if (keydata.key == MLX_KEY_LEFT)
			data->key.left = true;
		if (keydata.key == MLX_KEY_D)
			data->key.d = true;
		if (keydata.key == MLX_KEY_A)
			data->key.a = true;
		if (keydata.key == MLX_KEY_S)
			data->key.s = true;
		if (keydata.key == MLX_KEY_W)
			data->key.w = true;
	}
	else if (keydata.action == MLX_RELEASE)
		key_release(keydata, param);
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_destroy_win(param);
}

void	key_release(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_RIGHT)
		data->key.right = false;
	if (keydata.key == MLX_KEY_LEFT)
		data->key.left = false;
	if (keydata.key == MLX_KEY_D)
		data->key.d = false;
	if (keydata.key == MLX_KEY_A)
		data->key.a = false;
	if (keydata.key == MLX_KEY_S)
		data->key.s = false;
	if (keydata.key == MLX_KEY_W)
		data->key.w = false;
}
