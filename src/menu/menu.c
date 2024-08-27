/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:18:50 by lagea             #+#    #+#             */
/*   Updated: 2024/08/27 15:47:40 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int handle_mouse(int keysm, t_data *data)
{
    printf("keysm : %d\n",keysm);
    if (keysm == 1)
    {
        data->menu = 1;
        usleep(500);
    }
    return 0;
}

int create_menu(t_data *data)
{
    int x;
    int y;
    
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.menu, 0, 0);
    mlx_string_put(data->mlx_connection, data->mlx_window, (WIDTH / 2) - 35, (HEIGHT / 2) - 55, 0xFFFFFF, "Start Game");
    mlx_string_put(data->mlx_connection, data->mlx_window, (WIDTH / 2) - 15, (HEIGHT / 2) + 65, 0xFFFFFF, "Exit");
    mlx_mouse_get_pos(data->mlx_window, &x, &y);
    if ((x > 575 && x < 700) && (y > 275 && y < 325))
    {
        mlx_string_put(data->mlx_connection, data->mlx_window, (WIDTH / 2) - 35, (HEIGHT / 2) - 55, 16711680, "Start Game");
        // mlx_mouse_hook(data->mlx_window, &handle_mouse, data);
    }
    if ((x > 600 && x < 675) && (y > 400 && y < 450))
    {
        mlx_string_put(data->mlx_connection, data->mlx_window, (WIDTH / 2) - 15, (HEIGHT / 2) + 65, 16711680, "Exit");
    }
    // mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.start, 0, 0);
    // printf("mouse x : %d            y : %d\n", x, y);
    return 0;
}
    // int x = (WIDTH / 2) - 1;
    // int y = 0;
    // while (y < HEIGHT)
    // {
    //     mlx_pixel_put(data->mlx_connection, data->mlx_window, x, y, 16711680);
    //     y++;
    // }
    // x = 0;
    // y = (HEIGHT / 2) - 1;
    // while (x < WIDTH)
    // {
    //     mlx_pixel_put(data->mlx_connection, data->mlx_window, x, y, 16711680);
    //     x++;
    // }