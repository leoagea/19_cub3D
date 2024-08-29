/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:18:50 by lagea             #+#    #+#             */
/*   Updated: 2024/08/29 18:26:58 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int handle_mouse(int keysm, int x, int y, t_data *data)
{
    // printf("keysm : %d      x : %d          y : %d\n",keysm, x, y);
    // printf("Test\n");
    if (keysm == 1 && data->menu == 1 && (x > 375 && x < 900) && (y > 140 && y < 230))
        data->menu = 0;
    else if (keysm == 1 && data->menu == 1 && (x > 450 && x < 830) && (y > 300 && y < 400))
        data->controls = 1;
    else if (keysm == 1 && data->menu == 1 && (x > 540 && x < 730) && (y > 490 && y < 580))
        handle_input(keysm, data);
    else if (keysm == 1 && data->pause == 1 && (x > 375 && x < 900) && (y > 140 && y < 230))
        data->pause = 0;
    else if (keysm == 1 && data->pause == 1 && (x > 540 && x < 730) && (y > 490 && y < 580))
        handle_input(keysm, data);
    else if (keysm == 1 && data->pause == 1  && !data->controls && (x > 450 && x < 830) && (y > 300 && y < 400))
    {
        data->pause = 0;
        data->controls = 1;
    }
    else if (keysm == 1 && data->controls == 1 && !data->pause && (x > 540 && x < 730) && (y > 490 && y < 580))
    {
        data->pause = 1;
        data->controls = 0;
    }
    // printf("menu : %d\n", data->menu);
    return 0;
}

int menu_controls(t_data *data)
{
    int x;
    int y;
    
    mlx_mouse_show(data->mlx_window);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.menu, 0, 0);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_moves, 100, 75);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_for, 200, 125);
    // mlx_string_put(data->mlx_connection, data->mlx_window, 400, 200, 0xFFFFFF, data->keyboard[data->key.m_forward]);
    // mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->letters[KEY_W], 375, 130);
    // printf("key.m_for : %d\n", data->key.m_forward);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->letters[data->key.m_forward], 375, 130);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_back, 200, 175);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_right, 200, 225);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_left, 200, 275);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit, 555, 500);
    mlx_mouse_get_pos(data->mlx_window, &x, &y);
    if ((x > 540 && x < 730) && (y > 490 && y < 580))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit_highlight, 555, 500);
    // printf("mouse x : %d            y : %d\n", x, y);
    return 0;
}

int menu_pause(t_data *data)
{
    int x;
    int y;
    
    mlx_mouse_show(data->mlx_window);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.menu, 0, 0);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm._continue, 445, 150);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.controls, 465, 312);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit, 555, 500);
    mlx_mouse_get_pos(data->mlx_window, &x, &y);
    if ((x > 375 && x < 900) && (y > 140 && y < 230))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm._continue_highlight,445, 150);
    else if ((x > 450 && x < 830) && (y > 300 && y < 400))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.controls_highlight, 465, 312);
    else if ((x > 540 && x < 730) && (y > 490 && y < 580))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit_highlight, 555, 500);
    // printf("mouse x : %d            y : %d\n", x, y);
    return 0;
}

int create_menu(t_data *data)
{
    int x;
    int y;
    
    init_letters(data);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.menu, 0, 0);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.start, 395, 150);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.controls, 465, 312);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit, 555, 500);
    mlx_mouse_get_pos(data->mlx_window, &x, &y);
    if ((x > 375 && x < 900) && (y > 140 && y < 230))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.start_highlight, 395, 150);
    else if ((x > 450 && x < 830) && (y > 300 && y < 400))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.controls_highlight, 465, 312);
    else if ((x > 540 && x < 730) && (y > 490 && y < 580))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit_highlight, 555, 500);
    // printf("mouse x : %d            y : %d\n", x, y);
    return 0;
}
