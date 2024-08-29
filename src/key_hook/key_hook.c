/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:30 by vdarras           #+#    #+#             */
/*   Updated: 2024/08/29 15:46:00 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	cross_event(t_data *data)
{
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	free(data->img);
	write(1, "Window has been closed\n", 24);
	exit(1);
	return (0);
}

void	handle_input(int keysym, t_data *data)
{
	(void) keysym;
	// mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	free(data->img);
	write(1, "Window has been closed\n", 24);
	exit(1);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == data->key.r_left)
		data->player.key_left = 1;
	if (keysym == data->key.r_right)
		data->player.key_right = 1;
	if (keysym == data->key.m_forward)
		data->player.key_forward = 1;
	if (keysym == data->key.m_backward)
		data->player.key_backward = 1;
	if (keysym == data->key.m_left)
		data->player.key_move_left = 1;
	if (keysym == data->key.m_right)
		data->player.key_move_right = 1;
	if (keysym == KEY_ESCAPE && data->menu == 0)
	{
		data->pause = 1;
    	mlx_mouse_show(data->mlx_window);
		menu_pause(data);
		// handle_input(keysym ,data);
	}
	if (keysym == KEY_G)
	{
		if (data->player.speed * 100.0 <= 30.0 && data->player.speed >= -30.0)
		{
			data->player.speed += 0.01;
			raycasting(&data->player, data);
		}
	}
	if (keysym == KEY_R)
	{
		if (data->player.speed * 100.0 <= 30.0 && data->player.speed >= -30.0)
		{
			data->player.speed -= 0.01;
			raycasting(&data->player, data);
		}
	}
	if (keysym == KEY_TAB)
		data->player.minimap = 1;
	return (0);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == data->key.r_left)
		data->player.key_left = 0;
	if (keysym == data->key.r_right)
		data->player.key_right = 0;
	if (keysym == data->key.m_forward)
		data->player.key_forward = 0;
	if (keysym == data->key.m_backward)
		data->player.key_backward = 0;
	if (keysym == data->key.m_left)
		data->player.key_move_left = 0;
	if (keysym == data->key.m_right)
		data->player.key_move_right = 0;
	if (keysym == KEY_TAB)
		data->player.minimap = 0;
	return (0);
}