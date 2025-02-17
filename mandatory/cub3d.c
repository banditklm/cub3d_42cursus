/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:32:48 by kelmounj          #+#    #+#             */
/*   Updated: 2025/02/17 14:10:44 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_line1(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (x0 != x1 || y0 != y1)
    {
        put_pixel_to_image(data, x0, y0, color);
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

void    put_player(t_data *data)
{
    int player_x;
    int player_y;
    int player_size;
    int x;
    int y;
    
    player_x = (int)(data->player.x_pos * CELL_SIZE);
    player_y = (int)(data->player.y_pos * CELL_SIZE);
    player_size = CELL_SIZE / 8;
    x = -player_size;
    while (x <= player_size)
    {
        y = -player_size;
        while (y <= player_size)
        {
            put_pixel_to_image(data, player_x + x, player_y + y, 0x00FFFF);
            y++;
        }
        x++;
    }
    // double ray_x = data->player.x_pos;
    // double ray_y = data->player.y_pos;
    // double step = 0.1;

    // while (data->map[(int)ray_y][(int)ray_x] != '1')
    // {
    //     ray_x += data->ray.rayd_x * step;
    //     ray_y += data->ray.rayd_y * step;
    // }

    // int ray_pixel_x = ray_x * CELL_SIZE;
    // int ray_pixel_y = ray_y * CELL_SIZE;
    // draw_line1(data, player_x, player_y, ray_pixel_x, ray_pixel_y, 0xFF0000);
}

int render_minimap(t_data *data)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            y = 0;
            while (y < CELL_SIZE)
            {
                x = 0;
                while (x < CELL_SIZE)
                {
                    data->pixel_x = j * CELL_SIZE + x;
                    data->pixel_y = i * CELL_SIZE + y;
                    if (data->map[i][j] == '1')
                        put_pixel_to_image(data, data->pixel_x, data->pixel_y, 0xAAAAAA);
                    else
                        put_pixel_to_image(data, data->pixel_x, data->pixel_y, 0xFFFFFF);
                    x++;
                }
                y++;
            }
            j++;
        }
       i++;
    }
    put_player(data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img, 0, 0);
    return (0);
}

int render_frame(t_data *data)
{
    raycast(data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img, 0, 0);
    render_minimap(data);
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
	mlx_hook(data.mlx_win, 2, 0, move, &data);
    mlx_loop_hook(data.mlx_ptr, render_frame, &data);
	mlx_loop(data.mlx_ptr);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     