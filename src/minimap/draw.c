/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:55:32 by lagea             #+#    #+#             */
/*   Updated: 2024/08/23 18:16:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_cell(t_data *data, int x, int y, int color)
{
    int dx;
    int dy;
    
    dy = 0;
    while (dy < data->minimap->cell_height)
    {
        dx = 0;
        while (dx < data->minimap->cell_width)
        {
            // printf("dx : %d     dy : %d\n", dx + x, dy + y);
            draw_point(data, dx + x, dy + y, color);
            dx++;
        }
        dy++;
    }
}

void draw_player(t_data *data, int x, int y, int color)
{
    int dx;
    int dy;
    
    dy = 0;
    while (dy < 6)
    {
        dx = 0;
        while (dx < 6)
        {
            // printf("dx : %d     dy : %d\n", dx + x, dy + y);
            draw_point(data, dx + x, dy + y, color);
            dx++;
        }
        dy++;
    }
}

void draw_dda(t_data *data, int start_x, int start_y, int end_x, int end_y)
{
    int dx;
    int dy;
    float incr_x;
    float incr_y;
    int steps;
    int i;
    
    dx = end_x - start_x;
    dy = end_y - start_y;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    incr_x = dx / (float) steps;
    incr_y = dy / (float) steps;
    i = 0;
    while (i < steps)
    {
        draw_point(data, round(start_x), round(start_y), 12779520);
        start_x += incr_x;
        start_y += incr_y; 
        i++;
    }
}

void draw_view(t_data *data, int x, int y, int color)
{
    double x_proj;
    double y_proj;

    x_proj = x + (cos(1.0472) * 20);
    y_proj = y + (sin(1.0472) * 20);
    
    printf("player x : %d       player y :%d\n", x, y);
    printf("proj   x : %d       poej   y :%d\n",(int) floor(x_proj),(int) floor(y_proj));
    
    draw_dda(data, x, y, x - x_proj, y - y_proj);
    draw_dda(data, x, y, x + x_proj, y - y_proj);
    
}
