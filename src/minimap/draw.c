/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:55:32 by lagea             #+#    #+#             */
/*   Updated: 2024/08/23 12:47:09 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_cell(t_data *data, int x, int y, int color)
{
    int dx;
    int dy;
    
    dy = 0;
    while (dy <data->minimap->cell_height)
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
