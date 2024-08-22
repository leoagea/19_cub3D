/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:55:32 by lagea             #+#    #+#             */
/*   Updated: 2024/08/22 19:03:17 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_point(t_data *data, int x, int y, int color)
{
	int	pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = (y * data->img->size_line) + (x * (data->img->bits_per_pixel
					/ 8));
		if (data->img->endian == 0)
		{
			data->img->img_pixels_ptr[pixel + 0] = (color & 0xFF);
			data->img->img_pixels_ptr[pixel + 1] = (color >> 8) & 0xFF;
			data->img->img_pixels_ptr[pixel + 2] = (color >> 16) & 0xFF;
			data->img->img_pixels_ptr[pixel + 3] = (color >> 24) & 0xFF;
		}
		else
		{
			data->img->img_pixels_ptr[pixel + 0] = (color >> 24) & 0xFF;
			data->img->img_pixels_ptr[pixel + 1] = (color >> 16) & 0xFF;
			data->img->img_pixels_ptr[pixel + 2] = (color >> 8) & 0xFF;
			data->img->img_pixels_ptr[pixel + 3] = (color & 0xFF);
		}
	}
}

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
