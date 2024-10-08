/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:25:42 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 12:59:24 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	menu_change_controls(t_data *data)
{
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm.waitng_key_press, 480, 500);
}

void	change_controls(t_data *data, int keysim)
{
	if (keysim == data->key.m_forward || keysim == data->key.m_backward
		|| keysim == data->key.m_right || keysim == data->key.m_left
		|| keysim == data->key.r_right || keysim == data->key.r_left
		|| keysim == data->key.speed_up || keysim == data->key.speed_down
		|| keysim == data->key.interact)
		return ;
	if (data->menu.key == M_FORWARD)
		data->key.m_forward = keysim;
	else if (data->menu.key == M_BACKWARD)
		data->key.m_backward = keysim;
	else if (data->menu.key == M_RIGHT)
		data->key.m_right = keysim;
	else if (data->menu.key == M_LEFT)
		data->key.m_left = keysim;
	else if (data->menu.key == R_LEFT)
		data->key.r_left = keysim;
	else if (data->menu.key == R_RIGHT)
		data->key.r_right = keysim;
	else if (data->menu.key == SPEED_UP)
		data->key.speed_up = keysim;
	else if (data->menu.key == SPEED_DOWN)
		data->key.speed_down = keysim;
	data->menu.change = 0;
}
