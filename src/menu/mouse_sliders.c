/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_sliders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:05:43 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:07:23 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	handle_mouse_slider_dmg(t_data *data, int keysim, int x, int y)
{
	if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause)
		&& (x > 485 && x < 553) && (y > 345 && y < 370))
		data->slider[1].pos_slider = 1;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 554 && x < 689) && (y > 345
			&& y < 370))
		data->slider[1].pos_slider = 2;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 690 && x < 780) && (y > 345
			&& y < 370))
		data->slider[1].pos_slider = 3;
	return (0);
}

static int	handle_mouse_slider_suite(t_data *data, int keysim, int x, int y)
{
	if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause)
		&& (x > 645 && x < 689) && (y > 445 && y < 470))
		data->slider[0].pos_slider = 5;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 691 && x < 735) && (y > 445
			&& y < 470))
		data->slider[0].pos_slider = 6;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 736 && x < 780) && (y > 445
			&& y < 470))
		data->slider[0].pos_slider = 7;
	else
		handle_mouse_slider_dmg(data, keysim, x, y);
	return (0);
}

int	handle_mouse_slider(t_data *data, int keysim, int x, int y)
{
	if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause)
		&& (x > 485 && x < 510) && (y > 445 && y < 470))
		data->slider[0].pos_slider = 1;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 511 && x < 553) && (y > 445
			&& y < 470))
		data->slider[0].pos_slider = 2;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 554 && x < 598) && (y > 445
			&& y < 470))
		data->slider[0].pos_slider = 3;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 600 && x < 644) && (y > 445
			&& y < 470))
		data->slider[0].pos_slider = 4;
	else
		handle_mouse_slider_suite(data, keysim, x, y);
	return (0);
}
