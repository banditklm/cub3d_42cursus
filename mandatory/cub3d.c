/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:32:48 by kelmounj          #+#    #+#             */
/*   Updated: 2025/01/29 01:57:50 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    render_minimap(t_data *data)
// {
    
// }

void    fill_map(t_data *data)
{
    int i;
    int j;
    int x;
    int y;
    int color;
    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            
            if (data->map[i][j] == '1')
                color = 0xAAAAAA;
            else if (data->map[i][j] == '0')
                color = 0xFFFFFF;
            else
                color = 0xFF0000;
            for (y = 0; y < TILE_SIZE; y++)
            {
                for (x = 0; x < TILE_SIZE; x++)
                {
                    int pixel_x = j * TILE_SIZE + x;
                    int pixel_y = i * TILE_SIZE + y;
                    mlx_pixel_put(data->mlx_ptr, data->mlx_win, pixel_x, pixel_y, color);
                }
            }
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    t_data  data;


    if (ac != 2)
	{
		printf("Error\nyou need 1 file , .cub file\n");
		return (1);
	}
	check_file_ext(av[1]);
	parse(&data, av[1]);
    init_data(&data);
    init_player(&data);
    data.mlx_ptr = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx_ptr, data.screen_width, data.screen_height, "cub3d");
    fill_map(&data);
    // render_minimap(&data);
	mlx_loop(data.mlx_ptr);
}
