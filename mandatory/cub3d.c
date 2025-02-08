/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:32:48 by kelmounj          #+#    #+#             */
/*   Updated: 2025/02/08 13:11:00 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
            y = 0;
            while (y < CELL_SIZE)
            {
                x = 0;
                while (x < CELL_SIZE)
                {
                    data->pixel_x = j * CELL_SIZE + x;
                    data->pixel_y = i * CELL_SIZE + y;
                    mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->pixel_x, data->pixel_y, color);
                    x++;
                }
                y++;
            }
            j++;
        }
        i++;
    }
}

int render_frame(t_data *data)
{
    raycast(data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img, 0, 0);
    return (0);
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
    data.img.img = mlx_new_image(data.mlx_ptr, data.screen_width, data.screen_height);
    data.img.buffer = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.size_line, &data.img.endian);

    // fill_map(data);
    mlx_loop_hook(data.mlx_ptr, render_frame, &data);
	mlx_loop(data.mlx_ptr);
}
