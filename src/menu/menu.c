/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:18:50 by lagea             #+#    #+#             */
/*   Updated: 2024/09/02 18:29:55 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int handle_mouse_controls(t_data *data, int keysim, int x, int y)
{
    if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause) && (x > 365 && x < 400) && (y > 120 && y < 155))
    {
        data->menu.change = 1;
        data->menu.key = M_FORWARD;
    }
    else if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause) && (x > 365 && x < 400) && (y > 170 && y < 205))
    {
        data->menu.change = 1;
        data->menu.key = M_BACKWARD;
    }
    else if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause) && (x > 365 && x < 400) && (y > 220 && y < 255))
    {
        data->menu.change = 1;
        data->menu.key = M_RIGHT;
    }
    else if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause) && (x > 365 && x < 400) && (y > 270 && y < 305))
    {
        data->menu.change = 1;
        data->menu.key = M_LEFT;
    }
    else if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause) && (x > 675 && x < 775) && (y > 115 && y < 150))
    {
        data->menu.change = 1;
        data->menu.key = R_RIGHT;
    }
    else if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause) && (x > 675 && x < 775) && (y > 165 && y < 200))
    {
        data->menu.change = 1;
        data->menu.key = R_LEFT;
    }
    return 0;
}

int handle_mouse(int keysm, int x, int y, t_data *data)
{
    // printf("keysm : %d      x : %d          y : %d\n",keysm, x, y);
    // printf("Test\n");
    if (keysm == 1 && data->menu.menu && !data->menu.pause && !data->menu.controls && (x > 375 && x < 900) && (y > 140 && y < 230))
        data->menu.menu = 0;
    else if (keysm == 1 && data->menu.menu == 1 && !data->menu.pause && !data->menu.controls && (x > 450 && x < 830) && (y > 300 && y < 400))
    {
        data->menu.controls = 1; //aller dans controls
        data->menu.menu = 1;
        data->menu.pause = 0;
    }
    else if (keysm == 1 && data->menu.menu && !data->menu.pause && !data->menu.controls && (x > 540 && x < 730) && (y > 490 && y < 580))
        handle_input(keysm, data);
    else if (keysm == 1 && data->menu.pause && !data->menu.controls && (x > 375 && x < 900) && (y > 140 && y < 230))
        data->menu.pause = 0;
    else if (keysm == 1 && data->menu.pause && !data->menu.menu && (x > 540 && x < 730) && (y > 490 && y < 580))
        handle_input(keysm, data);
    else if (keysm == 1 && data->menu.pause && !data->menu.controls && (x > 450 && x < 830) && (y > 300 && y < 400))
    {
        data->menu.pause = 1;
        data->menu.controls = 1;
        data->menu.menu = 0;
    }
    else if (keysm == 1 && data->menu.controls && !data->menu.pause && data->menu.menu && (x > 450 && x < 810) && (y > 575 && y < 680))
    {
        data->menu.controls = 0; //ok sortir de controls dans le menu
    }
    else if (keysm == 1 && data->menu.controls && data->menu.pause && !data->menu.menu && (x > 450 && x < 810) && (y > 575 && y < 680))
    {
        data->menu.controls = 0; //ok sortir de controls dans le pause
    }
    else 
        handle_mouse_controls(data, keysm, x, y);
    // else if (keysm == 1 && data->menu.controls == 1 && !data->menu.pause && (x > 365 && x < 400) && (y > 120 && y < 155))
    // {
    //     data->menu.change = 1;
    //     // change_controls(data);
        
    // }
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
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->letters[data->key.m_forward], 375, 128);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_back, 200, 175);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->letters[data->key.m_backward], 375, 178);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_right, 200, 225);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->letters[data->key.m_right], 375, 228);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_left, 200, 275);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->letters[data->key.m_left], 375, 278);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm._return, 475, 600);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_vision, 475, 75);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_right, 575, 125);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->letters[data->key.r_right], 675, 125);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.cont_left, 575, 175);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->letters[data->key.r_left], 675, 175);
    
    mlx_mouse_get_pos(data->mlx_window, &x, &y);
    if ((x > 450 && x < 810) && (y > 575 && y < 680))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm._return_highlight, 475, 600);
    else if ((x > 365 && x < 400) && (y > 120 && y < 155))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->highlight[data->key.m_forward], 375, 128);
    else if ((x > 365 && x < 400) && (y > 170 && y < 205))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->highlight[data->key.m_backward], 375, 178);
    else if ((x > 365 && x < 400) && (y > 220 && y < 255))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->highlight[data->key.m_right], 375, 228);
    else if ((x > 365 && x < 400) && (y > 270 && y < 305))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->highlight[data->key.m_left], 375, 278);
    else if ((x > 675 && x < 775) && (y > 115 && y < 150))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->highlight[data->key.r_right], 675, 125);
    else if ((x > 675 && x < 775) && (y > 165 && y < 200))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->highlight[data->key.r_left], 675, 175);
    printf("mouse x : %d            y : %d\n", x, y);
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
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit, 550, 500);
    mlx_mouse_get_pos(data->mlx_window, &x, &y);
    if ((x > 375 && x < 900) && (y > 140 && y < 230))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm._continue_highlight,445, 150);
    else if ((x > 450 && x < 830) && (y > 300 && y < 400))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.controls_highlight, 465, 312);
    else if ((x > 540 && x < 730) && (y > 490 && y < 580))
        mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.exit_highlight, 550, 500);
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
