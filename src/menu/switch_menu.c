/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:05:57 by lagea             #+#    #+#             */
/*   Updated: 2024/09/09 18:12:52 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	handle_mouse_menu_suite(int keysm, int x, int y, t_data *data)
{
	if (keysm == 1 && data->menu.pause && !data->menu.menu && (x > 540
			&& x < 730) && (y > 490 && y < 580))
		handle_input(keysm, data);
	else if (keysm == 1 && data->menu.pause && !data->menu.controls && (x > 450
			&& x < 830) && (y > 300 && y < 400))
	{
		data->menu.pause = 1;
		data->menu.controls = 1;
		data->menu.menu = 0;
	}
	else if (keysm == 1 && data->menu.controls && !data->menu.pause
		&& data->menu.menu && (x > 450 && x < 810) && (y > 575 && y < 680))
	{
		data->menu.controls = 0;
	}
	else if (keysm == 1 && data->menu.controls && data->menu.pause
		&& !data->menu.menu && (x > 450 && x < 810) && (y > 575 && y < 680))
	{
		data->menu.controls = 0;
	}
	else
		handle_mouse_controls_menu(data, keysm, x, y);
	return (0);
}

int	handle_mouse_menu(int keysm, int x, int y, t_data *data)
{
	if (keysm == 1 && !data->menu.menu && !data->menu.pause
		&& !data->menu.controls && !data->menu.change)
	{
		data->player.is_firing = 1;
		data->player.fire_frame = 0;
	}
	else if (keysm == 1 && data->menu.menu && !data->menu.pause
		&& !data->menu.controls && (x > 375 && x < 900) && (y > 140 && y < 230))
		data->menu.menu = 0;
	else if (keysm == 1 && data->menu.menu == 1 && !data->menu.pause
		&& !data->menu.controls && (x > 450 && x < 830) && (y > 300 && y < 400))
	{
		data->menu.controls = 1;
		data->menu.menu = 1;
		data->menu.pause = 0;
	}
	else if (keysm == 1 && data->menu.menu && !data->menu.pause
		&& !data->menu.controls && (x > 540 && x < 730) && (y > 490 && y < 580))
		handle_input(keysm, data);
	else if (keysm == 1 && data->menu.pause && !data->menu.controls && (x > 375
			&& x < 900) && (y > 140 && y < 230))
		data->menu.pause = 0;
	else
		handle_mouse_menu_suite(keysm, x, y, data);
	return (0);
}
