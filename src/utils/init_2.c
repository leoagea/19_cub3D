/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:01:01 by lagea             #+#    #+#             */
/*   Updated: 2024/09/06 17:01:30 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_minimap_struct(t_data *data)
{
	data->minimap.start_x = WIDTH - (MINIMAP_NBR_CELL * MINIMAP_CELL_SIZE)
		- MINIMAP_GAP;
	data->minimap.start_y = MINIMAP_GAP;
	data->minimap.end_x = WIDTH - MINIMAP_GAP;
	data->minimap.end_y = MINIMAP_GAP + (MINIMAP_NBR_CELL * MINIMAP_CELL_SIZE);
	data->minimap.map_size = MINIMAP_CELL_SIZE * MINIMAP_NBR_CELL;
	data->minimap.offset = (double)MINIMAP_NBR_CELL / 2;
}

void	init_key_struct(t_data *data)
{
	data->key.m_forward = KEY_W;
	data->key.m_backward = KEY_S;
	data->key.m_right = KEY_D;
	data->key.m_left = KEY_A;
	data->key.r_right = KEY_RIGHT_ARROW;
	data->key.r_left = KEY_LEFT_ARROW;
	data->key.speed_up = KEY_EQUAL;
	data->key.speed_down = KEY_MINUS;
}

void	init_slider(t_data *data)
{
	data->slider.start_x = (WIDTH - SLIDERS_LEN) / 2;
	data->slider.pos_slider = 4;
	data->slider.last_pos_slider = 4;
}
