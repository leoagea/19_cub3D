/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:23:05 by lagea             #+#    #+#             */
/*   Updated: 2024/09/05 18:56:18 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void create_slider_border(t_data *data, int start_x, int start_y, bool side)
{
    int y;
    int x;
    
    y = start_y;
    while(y <= start_y + SLIDERS_HEIGHT - 2)
    {
        x = start_x;
        while (x <= start_x + 2)
        {
            mlx_pixel_put(data->mlx_connection, data->mlx_window, x, y, 0x00FFFFFF);
            x++;
        }
        y++;
    }
}

void create_cursor(t_data *data, int x, int y)
{
    int start_x;
    int start_y;
    int len;
    
    start_y = y;
    start_x = x;
    while (y <= start_y + SLIDERS_HEIGHT + 4)
    {
        if (y % (start_y) == 0 || y % (start_y) == 1 || y % start_y == 11 || y % (start_y) == 12)
        {
            len = SLIDERS_HEIGHT + 2;
            x = start_x;
        }
        else
        {
            x = start_x - 2;
            len = SLIDERS_HEIGHT + 4;
        }
        while (x < start_x + len)
        {
            mlx_pixel_put(data->mlx_connection, data->mlx_window, x, y, 0x00FF0000);
            x++;
        }
        y++;
    }
}

void draw_slider(t_data *data)
{
    if (data->slider.pos_slider == 1)
        create_cursor(data, data->slider.start_x, 449);
    else if (data->slider.pos_slider == 2)
        create_cursor(data, data->slider.start_x + 50, 449);
    else if (data->slider.pos_slider == 3)
        create_cursor(data, data->slider.start_x + 100, 449);
    else if (data->slider.pos_slider == 4)
        create_cursor(data, data->slider.start_x + 150, 449);
    else if (data->slider.pos_slider == 5)
        create_cursor(data, data->slider.start_x + 200, 449);
    else if (data->slider.pos_slider == 6)
        create_cursor(data, data->slider.start_x + 250, 449);
    else if (data->slider.pos_slider == 7)
        create_cursor(data, data->slider.start_x + SLIDERS_LEN, 449);

}

void create_slider(t_data *data, int start_x, int start_y, int len)
{
    int x;
    int y;
    int flag;

    flag = 0;
    y = start_y;
    while (y <= start_y + SLIDERS_HEIGHT + 2)
    {
        x = start_x;
        while (x < start_x + len)
        {
            mlx_pixel_put(data->mlx_connection, data->mlx_window, x, y, 0x00FFFFFF);
            x++;
        }
        if (flag % 2 == 0)
            y++;
        else
            y += SLIDERS_HEIGHT;
        flag++;
    }
    create_slider_border(data, start_x - 2, start_y + 2, 0);
    create_slider_border(data, x, start_y + 2, 1);
    draw_slider(data);
}
