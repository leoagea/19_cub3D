/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:18:50 by lagea             #+#    #+#             */
/*   Updated: 2024/08/26 17:15:24 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void create_menu(t_data *data)
{
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.menu, 0, 0);
    mlx_string_put(data->mlx_connection, data->mlx_window, (WIDTH / 2) - 35, (HEIGHT / 2) - 55, 0xFFFFFF, "Start Game");
    mlx_string_put(data->mlx_connection, data->mlx_window, (WIDTH / 2) - 15, (HEIGHT / 2) + 65, 0xFFFFFF, "Exit");
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
}