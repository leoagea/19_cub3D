/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:14:09 by lagea             #+#    #+#             */
/*   Updated: 2025/01/23 17:43:56 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_keysym(int keysym)
{
	if (keysym == XK_q || keysym == XK_w || keysym == XK_e || keysym == XK_r
		|| keysym == XK_t || keysym == XK_y || keysym == XK_u
		|| keysym == XK_i || keysym == XK_o || keysym == XK_p
		|| keysym == XK_a || keysym == XK_s || keysym == XK_d
		|| keysym == XK_f || keysym == XK_g || keysym == XK_h
		|| keysym == XK_j || keysym == XK_k || keysym == XK_l
		|| keysym == XK_z || keysym == XK_x || keysym == XK_c
		|| keysym == XK_v || keysym == XK_b || keysym == XK_n
		|| keysym == XK_m || keysym == XK_1 || keysym == XK_2
		|| keysym == XK_3 || keysym == XK_4 || keysym == XK_5
		|| keysym == XK_6 || keysym == XK_7 || keysym == XK_8
		|| keysym == XK_9 || keysym == XK_0 || keysym == XK_0
		|| keysym == XK_1 || keysym == XK_2 || keysym == XK_3
		|| keysym == XK_4 || keysym == XK_5 || keysym == XK_6
		|| keysym == XK_7 || keysym == XK_8 || keysym == XK_9
		|| keysym == XK_minus || keysym == XK_equal)
		return (1);
	return (0);
}

static int	key_press_check_end(int keysym, t_data *data)
{
	if (keysym == XK_Escape && !data->menu.menu && !data->menu.controls
		&& !data->menu.change && ((data->menu.dead && !data->menu.victory)
			|| (!data->menu.dead && data->menu.victory)))
		ft_error(NULL, data);
	if (check_keysym(keysym) && !data->menu.controls && !data->menu.change
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
	if (keysym == XK_Escape && !data->menu.menu && !data->menu.pause
		&& !data->menu.controls && !data->menu.change && !data->menu.dead
		&& !data->menu.victory)
	{
		data->menu.pause = 1;
		mlx_mouse_show(data->mlx_connection ,data->mlx_window);
		menu_pause(data);
	}
	if (keysym == data->key.interact)
		interact_door(data, &data->player, data->door);
	key_press_suite_2(keysym, data);
	return (0);
}

int	key_press(int keysym, t_data *data)
{
	if ((data->menu.menu || data->menu.pause) && data->menu.controls
		&& data->menu.change && check_keysym(keysym) && !data->menu.dead
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
