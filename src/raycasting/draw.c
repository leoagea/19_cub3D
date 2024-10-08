/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:25:09 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 11:09:06 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw(t_data *data, t_player *player)
{
	int	i;
	int	total;

	i = 0;
	total = HEIGHT * WIDTH;
	while (i < HEIGHT)
	{
		draw_point(data, player->column, i, data->file.c_floor->color);
		i++;
	}
	player->column++;
}

void	draw_point(t_data *data, int x, int y, long color)
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

void	draw_crosshair(t_data *data)
{
	int	i;

	i = -10;
	while (i < 10)
	{
		draw_point(data, WIDTH / 2 + i, HEIGHT / 2, 4294967295);
		i++;
	}
	i = -10;
	while (i < 10)
	{
		draw_point(data, WIDTH / 2, HEIGHT / 2 + i, 4294967295);
		i++;
	}
}
