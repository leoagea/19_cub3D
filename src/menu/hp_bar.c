/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hp_bar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:40:28 by lagea             #+#    #+#             */
/*   Updated: 2024/09/04 15:54:41 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void draw_hp_bar_section(t_data *data, int start)
{
    int x;
	int y = 675;
	while (y < 675 + 20)
	{
		x = start;
		while(x < start + 16)
		{
            draw_point(data, x, y, 16711680);
			x++;
		}
		y++;
	}
}

static void draw_border_vertical_hp_bar(t_data *data, int start)
{
	int x;
	int y;

	y = 669;
	while(++y < 700)
	{
		x = start;
		while (++x < start + 5)
			draw_point(data, x, y, 919191);
	}
}

static void draw_border_horizontal_hp_bar(t_data *data, int start)
{
	int x;
	int y;

	y = start;
	while(++y < start + 5)
	{
		x = 89;
		while (++x < 426)
			draw_point(data, x, y, 919191);
	}
}

void draw_separation_section(t_data *data, int start)
{
	int y;

	y = 675;
	while (y < 675 + 20)
	{
		draw_point(data, start, y, 0);
		y++;
	}
}

void draw_hp_bar(t_data *data)
{
    int i;

    i = 0;
	draw_border_vertical_hp_bar(data, 85);
	draw_border_vertical_hp_bar(data, 425);
	draw_border_horizontal_hp_bar(data, 669);
	draw_border_horizontal_hp_bar(data, 695);
    while(i <= data->player.hp / 5)
    {    
    	draw_hp_bar_section(data, 90 + (i * 16));
		i++;
    }
	i = 0;
	while(i <= data->player.hp / 5)
    {    
		draw_separation_section(data, 105 + (i * 16));
		i++;
    }
}
