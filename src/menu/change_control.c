/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:25:42 by lagea             #+#    #+#             */
/*   Updated: 2024/09/02 16:06:37 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void menu_change_controls(t_data *data)
{
	// printf("data.menu.menu %d\ndata.menu.pause %d\ndata.menu.mouse %d\ndata.menu.controls%d\ndata.menu.change %d\n\n",data->menu.menu, data->menu.pause, data->menu.mouse, data->menu.controls, data->menu.change);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->xpm.waitng_key_press, 480, 500);
    // exit(1);
}

void change_controls(t_data *data, int keysim)
{
    printf("Test %d\n", keysim);
    if (keysim == data->key.m_forward || keysim == data->key.m_backward || keysim == data->key.m_right || keysim == data->key.m_left)
        return ;
    if (data->menu.key == M_FORWARD)
        data->key.m_forward = keysim;
    else if (data->menu.key == M_BACKWARD)
        data->key.m_backward = keysim;
    else if (data->menu.key == M_RIGHT)
        data->key.m_right = keysim;
    else if (data->menu.key == M_LEFT)
        data->key.m_left = keysim;
    data->menu.change = 0;
}