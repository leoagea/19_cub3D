/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:18:50 by lagea             #+#    #+#             */
/*   Updated: 2024/08/28 16:01:38 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void switch_menu(t_data *data)
{
    data->menu = 1;
}

int handle_mouse(int keysm, int x, int y, t_data *data)
{
    if (keysm == 1 && data->menu == 0 && (x > 375 && x < 900) && (y > 140 && y < 230))
        data->menu = 1;
    else if (keysm == 1 && data->menu == 0 && (x > 540 && x < 730) && (y > 490 && y < 580))
        exit(0);
    else if (keysm == 1 && data->menu == 1)
    {
        data->player.is_firing = 1;
		data->player.fire_frame = 0;
    }
    // printf("menu : %d\n", data->menu);
    return 0;
}

int create_menu(t_data *data)
{
    int x;
    int y;
    
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.menu, 0, 0);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.start, 395, 150);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit, 555, 500);
    // mlx_string_put(data->mlx_connection, data->mlx_window, (WIDTH / 2) - 15, (HEIGHT / 2) + 65, 0xFFFFFF, "Exit");
    mlx_mouse_get_pos(data->mlx_window, &x, &y);
    if ((x > 375 && x < 900) && (y > 140 && y < 230))
    {
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.start_select, 395, 150);
        // mlx_hook(data->mlx_window,4, 1L<<2, handle_mouse, data);
        if (data->menu == 1)
        return 0;
    }
    if ((x > 540 && x < 730) && (y > 490 && y < 580))
    {
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit_select, 555, 500);
    }
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