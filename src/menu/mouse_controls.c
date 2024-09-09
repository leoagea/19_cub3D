/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:49:35 by lagea             #+#    #+#             */
/*   Updated: 2024/09/09 18:15:16 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	handle_mouse_slider_suite(t_data *data, int keysim, int x, int y)
{
	if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause)
		&& (x > 645 && x < 689) && (y > 445 && y < 470))
		data->slider.pos_slider = 5;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 691 && x < 735) && (y > 445
			&& y < 470))
		data->slider.pos_slider = 6;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 736 && x < 780) && (y > 445
			&& y < 470))
		data->slider.pos_slider = 7;
	return (0);
}

int	handle_mouse_slider(t_data *data, int keysim, int x, int y)
{
	data->slider.last_pos_slider = data->slider.pos_slider;
	if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause)
		&& (x > 485 && x < 510) && (y > 445 && y < 470))
		data->slider.pos_slider = 1;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 511 && x < 553) && (y > 445
			&& y < 470))
		data->slider.pos_slider = 2;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 554 && x < 598) && (y > 445
			&& y < 470))
		data->slider.pos_slider = 3;
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 600 && x < 644) && (y > 445
			&& y < 470))
		data->slider.pos_slider = 4;
	else
		handle_mouse_slider_suite(data, keysim, x, y);
	return (0);
}

static int	handle_mouse_controls_suite_2(t_data *data, int keysim, int x,
		int y)
{
	if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause)
		&& (x > 1060 && x < 1110) && (y > 120 && y < 155))
	{
		data->menu.change = 1;
		data->menu.key = SPEED_UP;
	}
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 1060 && x < 1110) && (y > 165
			&& y < 200))
	{
		data->menu.change = 1;
		data->menu.key = SPEED_DOWN;
	}
	else
		handle_mouse_slider(data, keysim, x, y);
	return (0);
}

static int	handle_mouse_controls_suite(t_data *data, int keysim, int x, int y)
{
	if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause)
		&& (x > 365 && x < 400) && (y > 270 && y < 305))
	{
		data->menu.change = 1;
		data->menu.key = M_LEFT;
	}
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 675 && x < 775) && (y > 115
			&& y < 150))
	{
		data->menu.change = 1;
		data->menu.key = R_RIGHT;
	}
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 675 && x < 775) && (y > 165
			&& y < 200))
	{
		data->menu.change = 1;
		data->menu.key = R_LEFT;
	}
	else
		handle_mouse_controls_suite_2(data, keysim, x, y);
	return (0);
}

int	handle_mouse_controls_menu(t_data *data, int keysim, int x, int y)
{
	if (keysim && data->menu.controls && (data->menu.menu || data->menu.pause)
		&& (x > 365 && x < 400) && (y > 120 && y < 155))
	{
		data->menu.change = 1;
		data->menu.key = M_FORWARD;
	}
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 365 && x < 400) && (y > 170
			&& y < 205))
	{
		data->menu.change = 1;
		data->menu.key = M_BACKWARD;
	}
	else if (keysim && data->menu.controls && (data->menu.menu
			|| data->menu.pause) && (x > 365 && x < 400) && (y > 220
			&& y < 255))
	{
		data->menu.change = 1;
		data->menu.key = M_RIGHT;
	}
	else
		handle_mouse_controls_suite(data, keysim, x, y);
	return (0);
}
