/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:32:48 by kelmounj          #+#    #+#             */
/*   Updated: 2025/01/29 00:56:42 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    render_minimap(t_data *data)
// {
    
// }

int main()
{
    t_data  data;


    // if (ac != 2)
	// {
	// 	printf("Error\nyou need 1 file , .cub file\n");
	// 	return (1);
	// }
	// check_file_ext(av[1]);
	// parse(&data, av[1]);
    init_data(&data);
    init_player(&data);
    printf("%d\n", data.screen_width);
    data.mlx_ptr = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx_ptr, data.screen_width, data.screen_height, "cub3d");
    // render_minimap(&data);
	mlx_loop(data.mlx_ptr);
}
