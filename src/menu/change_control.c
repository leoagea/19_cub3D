/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:25:42 by lagea             #+#    #+#             */
/*   Updated: 2024/08/30 17:33:18 by lagea            ###   ########.fr       */
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
    printf("Test\n");
    if ((data->menu.menu || data->menu.pause) && data->menu.controls && data->menu.change && (keysim != KEY_Q && keysim != KEY_W && keysim != KEY_E \
	 && keysim != KEY_R && keysim != KEY_T && keysim != KEY_Y && keysim != KEY_U && keysim != KEY_I && keysim != KEY_O && keysim != KEY_P \
	 && keysim != KEY_A && keysim != KEY_S && keysim != KEY_D && keysim != KEY_F && keysim != KEY_G && keysim != KEY_H && keysim != KEY_J \
	 && keysim != KEY_K && keysim != KEY_L && keysim != KEY_Z && keysim != KEY_X && keysim != KEY_C && keysim != KEY_V && keysim != KEY_B \
	 && keysim != KEY_N && keysim != KEY_M && keysim != KEY_1 && keysim != KEY_2 && keysim != KEY_3 && keysim != KEY_4 && keysim != KEY_5 \
	 && keysim != KEY_6 && keysim != KEY_7 && keysim != KEY_8 && keysim != KEY_9 && keysim != KEY_0))
        return ;
    if (data->menu.key == M_FORWARD)
        data->key.m_forward = keysim;
    data->menu.change = 0;
}