/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:16:15 by lagea             #+#    #+#             */
/*   Updated: 2025/01/23 17:44:48 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	highlight_selection(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx_connection, data->mlx_window, &x, &y);
	if ((x > 450 && x < 810) && (y > 575 && y < 680))
		img_to_win(data, data->xpm._return_highlight, 475, 600);
	else if ((x > 365 && x < 400) && (y > 120 && y < 155))
		img_to_win(data, data->highlight[data->key.m_forward], 375, 128);
	else if ((x > 365 && x < 400) && (y > 170 && y < 205))
		img_to_win(data, data->highlight[data->key.m_backward], 375, 178);
	else if ((x > 365 && x < 400) && (y > 220 && y < 255))
		img_to_win(data, data->highlight[data->key.m_right], 375, 228);
	else if ((x > 365 && x < 400) && (y > 270 && y < 305))
		img_to_win(data, data->highlight[data->key.m_left], 375, 278);
	else if ((x > 625 && x < 725) && (y > 115 && y < 150))
		img_to_win(data, data->highlight[data->key.r_right], 625, 125);
	else if ((x > 625 && x < 725) && (y > 165 && y < 200))
		img_to_win(data, data->highlight[data->key.r_left], 625, 175);
	else if ((x > 1060 && x < 1110) && (y > 120 && y < 155))
		img_to_win(data, data->highlight[data->key.speed_up], 1075, 128);
	else if ((x > 1060 && x < 1110) && (y > 165 && y < 200))
		img_to_win(data, data->highlight[data->key.speed_down], 1075, 178);
}

static void	display_sensi_slider(t_data *data)
{
	img_to_win(data, data->letters[XK_s], 532, 400);
	img_to_win(data, data->letters[XK_e], 552, 400);
	img_to_win(data, data->letters[XK_n], 572, 400);
	img_to_win(data, data->letters[XK_s], 592, 400);
	img_to_win(data, data->letters[XK_i], 612, 400);
	img_to_win(data, data->letters[XK_b], 622, 400);
	img_to_win(data, data->letters[XK_i], 642, 400);
	img_to_win(data, data->letters[XK_l], 657, 400);
	img_to_win(data, data->letters[XK_i], 677, 400);
	img_to_win(data, data->letters[XK_t], 687, 400);
	img_to_win(data, data->letters[XK_y], 707, 400);
	create_slider(data, data->slider[0].start_x, 450, 300);
	draw_slider_sensi(data);
}

static void	display_dmg_slider(t_data *data)
{
	img_to_win(data, data->letters[XK_d], 552, 300);
	img_to_win(data, data->letters[XK_m], 572, 300);
	img_to_win(data, data->letters[XK_g], 592, 300);
	img_to_win(data, data->letters[XK_t], 622, 300);
	img_to_win(data, data->letters[XK_a], 642, 300);
	img_to_win(data, data->letters[XK_k], 662, 300);
	img_to_win(data, data->letters[XK_e], 682, 300);
	img_to_win(data, data->letters[XK_n], 707, 300);
	create_slider(data, data->slider[1].start_x, 350, 300);
	draw_slider_dmg(data, data->slider[1]);
}

int	menu_controls(t_data *data)
{
	mlx_mouse_show(data->mlx_connection, data->mlx_window);
	img_to_win(data, data->xpm.menu, 0, 0);
	img_to_win(data, data->xpm.cont_moves, 100, 75);
	img_to_win(data, data->xpm.cont_for, 200, 125);
	img_to_win(data, data->letters[data->key.m_forward], 375, 128);
	img_to_win(data, data->xpm.cont_back, 200, 175);
	img_to_win(data, data->letters[data->key.m_backward], 375, 178);
	img_to_win(data, data->xpm.cont_right, 200, 225);
	img_to_win(data, data->letters[data->key.m_right], 375, 228);
	img_to_win(data, data->xpm.cont_left, 200, 275);
	img_to_win(data, data->letters[data->key.m_left], 375, 278);
	img_to_win(data, data->xpm._return, 475, 600);
	img_to_win(data, data->xpm.cont_vision, 425, 75);
	img_to_win(data, data->xpm.cont_right, 525, 125);
	img_to_win(data, data->letters[data->key.r_right], 625, 125);
	img_to_win(data, data->xpm.cont_left, 525, 175);
	img_to_win(data, data->letters[data->key.r_left], 625, 175);
	img_to_win(data, data->xpm.cont_interations, 800, 75);
	img_to_win(data, data->xpm.speed_up, 900, 125);
	img_to_win(data, data->xpm.speed_down, 900, 175);
	img_to_win(data, data->letters[data->key.speed_up], 1075, 128);
	img_to_win(data, data->letters[data->key.speed_down], 1075, 178);
	display_sensi_slider(data);
	display_dmg_slider(data);
	return (highlight_selection(data), 0);
}
