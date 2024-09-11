/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:14:09 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:04:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_keysym(t_data *data, int keysym)
{
	if (keysym == KEY_Q || keysym == KEY_W || keysym == KEY_E || keysym == KEY_R
		|| keysym == KEY_T || keysym == KEY_Y || keysym == KEY_U
		|| keysym == KEY_I || keysym == KEY_O || keysym == KEY_P
		|| keysym == KEY_A || keysym == KEY_S || keysym == KEY_D
		|| keysym == KEY_F || keysym == KEY_G || keysym == KEY_H
		|| keysym == KEY_J || keysym == KEY_K || keysym == KEY_L
		|| keysym == KEY_Z || keysym == KEY_X || keysym == KEY_C
		|| keysym == KEY_V || keysym == KEY_B || keysym == KEY_N
		|| keysym == KEY_M || keysym == KEY_1 || keysym == KEY_2
		|| keysym == KEY_3 || keysym == KEY_4 || keysym == KEY_5
		|| keysym == KEY_6 || keysym == KEY_7 || keysym == KEY_8
		|| keysym == KEY_9 || keysym == KEY_0 || keysym == KEY_NUM_0
		|| keysym == KEY_NUM_1 || keysym == KEY_NUM_2 || keysym == KEY_NUM_3
		|| keysym == KEY_NUM_4 || keysym == KEY_NUM_5 || keysym == KEY_NUM_6
		|| keysym == KEY_NUM_7 || keysym == KEY_NUM_8 || keysym == KEY_NUM_9
		|| keysym == KEY_MINUS || keysym == KEY_EQUAL)
		return (1);
	return (0);
}

static int	key_press_check_end(int keysym, t_data *data)
{
	if (keysym == KEY_ESCAPE && !data->menu.menu && !data->menu.controls
		&& !data->menu.change && ((data->menu.dead && !data->menu.victory)
			|| (!data->menu.dead && data->menu.victory)))
		ft_error(NULL, data);
	if (check_keysym(data, keysym) && !data->menu.controls && !data->menu.change
		&& (!data->menu.dead && data->menu.victory) && data->menu.playing)
	{
		data->menu.playing = 0;
		data->menu.victory = 0;
		data->menu.check_win = 1;
	}
	return (0);
}

static int	key_press_suite_2(int keysym, t_data *data)
{
	if (keysym == data->key.speed_up && !data->menu.controls
		&& !data->menu.pause && !data->menu.menu && !data->menu.dead
		&& !data->menu.victory)
	{
		if (data->player.speed * 100.0 <= 30.0)
		{
			data->player.speed += 0.01;
			raycasting(&data->player, data);
		}
	}
	if (keysym == data->key.speed_down && !data->menu.controls
		&& !data->menu.pause && !data->menu.menu && !data->menu.dead
		&& !data->menu.victory)
	{
		if (data->player.speed * 100 >= -30.0)
		{
			data->player.speed -= 0.01;
			raycasting(&data->player, data);
		}
	}
	key_press_check_end(keysym, data);
	return (0);
}

static int	key_press_suite(int keysym, t_data *data)
{
	if (keysym == data->key.m_left && !data->menu.controls && !data->menu.pause
		&& !data->menu.menu && !data->menu.dead && !data->menu.victory)
		data->player.key_move_left = 1;
	if (keysym == data->key.m_right && !data->menu.controls && !data->menu.pause
		&& !data->menu.menu && !data->menu.dead && !data->menu.victory)
		data->player.key_move_right = 1;
	if (keysym == KEY_ESCAPE && !data->menu.menu && !data->menu.pause
		&& !data->menu.controls && !data->menu.change && !data->menu.dead
		&& !data->menu.victory)
	{
		data->menu.pause = 1;
		mlx_mouse_show(data->mlx_window);
		menu_pause(data);
	}
	key_press_suite_2(keysym, data);
	return (0);
}

int	key_press(int keysym, t_data *data)
{
	if ((data->menu.menu || data->menu.pause) && data->menu.controls
		&& data->menu.change && check_keysym(data, keysym) && !data->menu.dead
		&& !data->menu.victory)
		change_controls(data, keysym);
	else if ((data->menu.menu || data->menu.pause) && data->menu.controls
		&& data->menu.change && !data->menu.dead && !data->menu.victory)
	{
		data->menu.change = 0;
		menu_controls(data);
	}
	if (keysym == data->key.r_left && !data->menu.controls && !data->menu.pause
		&& !data->menu.menu && !data->menu.dead && !data->menu.victory)
		data->player.key_left = 1;
	if (keysym == data->key.r_right && !data->menu.controls && !data->menu.pause
		&& !data->menu.menu && !data->menu.dead && !data->menu.victory)
		data->player.key_right = 1;
	if (keysym == data->key.m_forward && !data->menu.controls
		&& !data->menu.pause && !data->menu.menu && !data->menu.dead
		&& !data->menu.victory)
		data->player.key_forward = 1;
	if (keysym == data->key.m_backward && !data->menu.controls
		&& !data->menu.pause && !data->menu.menu && !data->menu.dead
		&& !data->menu.victory)
		data->player.key_backward = 1;
	return (key_press_suite(keysym, data), 0);
}
