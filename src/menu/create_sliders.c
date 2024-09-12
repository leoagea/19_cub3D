/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sliders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:23:05 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 12:51:16 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	create_slider_border(t_data *data, int start_x, int start_y)
{
	int	y;
	int	x;

	y = start_y;
	while (y <= start_y + SLIDERS_HEIGHT - 2)
	{
		x = start_x;
		while (x <= start_x + 2)
		{
			mlx_pixel_put(data->mlx_connection, data->mlx_window, x, y,
				0x00FFFFFF);
			x++;
		}
		y++;
	}
}

void	create_cursor(t_data *data, int x, int y)
{
	int	start_x;
	int	start_y;
	int	len;

	start_y = y;
	start_x = x;
	while (y <= start_y + SLIDERS_HEIGHT + 4)
	{
		if (y % (start_y) == 0 || y % (start_y) == 1 || y % start_y == 11 || y
			% (start_y) == 12)
		{
			len = SLIDERS_HEIGHT + 2;
			x = start_x - 1;
		}
		else
		{
			x = start_x - 3;
			len = SLIDERS_HEIGHT + 4;
		}
		while (++x < start_x + len)
			mlx_pixel_put(data->mlx_connection, data->mlx_window, x, y,
				0x00FF0000);
		y++;
	}
}

void	create_slider(t_data *data, int start_x, int start_y, int len)
{
	int	x;
	int	y;
	int	flag;

	flag = 0;
	y = start_y;
	while (y <= start_y + SLIDERS_HEIGHT + 2)
	{
		x = start_x;
		while (x < start_x + len)
		{
			mlx_pixel_put(data->mlx_connection, data->mlx_window, x, y,
				0x00FFFFFF);
			x++;
		}
		if (flag % 2 == 0)
			y++;
		else
			y += SLIDERS_HEIGHT;
		flag++;
	}
	create_slider_border(data, start_x - 2, start_y + 2);
	create_slider_border(data, x, start_y + 2);
}
