/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:49:35 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:06:10 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
