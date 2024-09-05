/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:17:05 by lagea             #+#    #+#             */
/*   Updated: 2024/09/05 15:35:53 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_horizontal_minimap_border(t_data *data, int y, int size)
{
    int x;
    int start;
    
    start = y;
    while (y < start  + size)
    {
        x = data->minimap.start_x - size;
        while (x < data->minimap.end_x + size)
        {
            draw_point(data, x, y, 919191);
            x++;
        }
        y++;
    }
}

void draw_vertical_minimap_border(t_data *data, int x, int size)
{
    int y;
    int start;

    start = x;
    while (x < start + size)
    {
        y = data->minimap.start_y - size;
        while (y < data->minimap.end_y  + size)
        {
            draw_point(data, x, y, 919191);
            y++;
        }
        x++;
    }
}

void  draw_player(t_data *data)
{
    int pos_x;
    int pos_y;
    int start_x;
    int start_y;

    pos_x = data->minimap.start_x + (data->minimap.map_size / 2); 
    pos_y = data->minimap.start_y + (data->minimap.map_size) / 2;
    // printf("pos_x : %d\npos_y : %d\n", pos_x, pos_y);
    start_x = pos_x - 2;
    while (start_x <= pos_x + 2)
    {
        start_y = pos_y - 2;
        while (start_y <= pos_y + 2)
        {
            draw_point(data, start_x, start_y, 16711680);
            start_y++;
        }
        start_x++;
    }
    // draw_point(data, pos_x, pos_y, 16711680);
}

void draw_tiles(t_data *data)
{
    int x;
    int y;
    double dist_x;
    double dist_y;

    y = data->minimap.start_y;
    dist_y = data->player.pos_y - data->minimap.offset;
    while (y < data->minimap.map_size + data->minimap.start_y)
    {
        x = data->minimap.start_x;
        dist_x = data->player.pos_x - data->minimap.offset;
        while (x < data->minimap.start_x + data->minimap.map_size)
        {
            if (is_in_map(data, (int)dist_x, (int)dist_y) && is_wall(data, (int)dist_x, (int)dist_y))
                draw_point(data, x, y, 1710618);
            else
                draw_point(data, x, y, 14342874);
            x++;
            dist_x += 0.05;
        }
        y++;
        dist_y += 0.05;
    }
}
