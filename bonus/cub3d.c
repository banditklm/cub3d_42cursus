/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:32:48 by kelmounj          #+#    #+#             */
/*   Updated: 2025/04/10 11:16:34 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	render_frame(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	check_doors(param);
	raycast(data);
	play_s2(data);
	put_weapon(data);
	mini_map(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("Error\nyou need 1 file , .cub file\n");
		return (1);
	}
	check_file_ext(av[1]);
	parse(&data, av[1]);
	init_data(&data);
	init_player(&data);
	init_keys(&data);
	data.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", false);
	data.img = mlx_new_image(data.mlx, data.screen_width, data.screen_height);
	mlx_set_cursor_mode(data.mlx, MLX_MOUSE_HIDDEN);
	mlx_close_hook(data.mlx, ft_destroy_win, &data);
	mlx_cursor_hook(data.mlx, mouse_move, &data);
	load_all_text(&data);
	load_frames(&data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop_hook(data.mlx, move_to, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	c_malloc(0, 0);
}
