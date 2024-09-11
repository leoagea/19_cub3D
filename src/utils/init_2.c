/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:01:01 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:41:20 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_minimap_struct(t_data *data)
{
	data->minimap.map_size = 140;
	data->minimap.start_x = WIDTH - (MINIMAP_NBR_CELL * MINIMAP_CELL_SIZE)
		- MINIMAP_GAP;
	data->minimap.start_y = MINIMAP_GAP;
	data->minimap.end_x = WIDTH - MINIMAP_GAP;
	data->minimap.end_y = MINIMAP_GAP + (MINIMAP_NBR_CELL * MINIMAP_CELL_SIZE);
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
	data->key.interact = KEY_E;
}

void	init_slider_struct(t_data *data)
{
	data->slider[0].start_x = (WIDTH - SLIDERS_LEN) / 2;
	data->slider[0].pos_slider = 4;
	data->slider[1].start_x = (WIDTH - SLIDERS_LEN) / 2;
	data->slider[1].pos_slider = 2;
	data->slider[2].start_x = (WIDTH - SLIDERS_LEN) / 2;
	data->slider[2].pos_slider = 3;
}

static void	init_xpm_struct_suite(t_data *data)
{
	data->xpm.dead = NULL;
	data->xpm.escape = NULL;
	data->xpm.victory = NULL;
	data->xpm.waiting_victory = NULL;
	data->xpm.speed_down_highlight = NULL;
}

void	init_xpm_struct(t_data *data)
{
	data->xpm.exit = NULL;
	data->xpm.menu = NULL;
	data->xpm.start = NULL;
	data->xpm.floor = NULL;
	data->xpm.ceiling = NULL;
	data->xpm._return = NULL;
	data->xpm.controls = NULL;
	data->xpm.speed_up = NULL;
	data->xpm.cont_for = NULL;
	data->xpm._continue = NULL;
	data->xpm.cont_back = NULL;
	data->xpm.cont_left = NULL;
	data->xpm.cont_right = NULL;
	data->xpm.cont_moves = NULL;
	data->xpm.speed_down = NULL;
	data->xpm.cont_vision = NULL;
	data->xpm.exit_highlight = NULL;
	data->xpm.start_highlight = NULL;
	data->xpm.waitng_key_press = NULL;
	data->xpm.cont_interations = NULL;
	data->xpm._return_highlight = NULL;
	data->xpm.controls_highlight = NULL;
	data->xpm.speed_up_highlight = NULL;
	data->xpm._continue_highlight = NULL;
	init_xpm_struct_suite(data);
}
