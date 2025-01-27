/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_highlight.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:56:34 by lagea             #+#    #+#             */
/*   Updated: 2025/01/23 17:24:20 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	load_highlight_xpm_suite_2(t_data *data)
{
	highlight_to_img(data, XK_KP_3,
		"./assets/menu/keyboard_keys/NUM_3_high.xpm");
	highlight_to_img(data, XK_KP_4,
		"./assets/menu/keyboard_keys/NUM_4_high.xpm");
	highlight_to_img(data, XK_KP_5,
		"./assets/menu/keyboard_keys/NUM_5_high.xpm");
	highlight_to_img(data, XK_KP_6,
		"./assets/menu/keyboard_keys/NUM_6_high.xpm");
	highlight_to_img(data, XK_KP_7,
		"./assets/menu/keyboard_keys/NUM_7_high.xpm");
	highlight_to_img(data, XK_KP_8,
		"./assets/menu/keyboard_keys/NUM_8_high.xpm");
	highlight_to_img(data, XK_KP_9,
		"./assets/menu/keyboard_keys/NUM_9_high.xpm");
	highlight_to_img(data, XK_Up,
		"./assets/menu/keyboard_keys/ARR_UP_high.xpm");
	highlight_to_img(data, XK_Down,
		"./assets/menu/keyboard_keys/ARR_DOWN_high.xpm");
	highlight_to_img(data, XK_Left,
		"./assets/menu/keyboard_keys/ARR_LEFT_high.xpm");
	highlight_to_img(data, XK_Right,
		"./assets/menu/keyboard_keys/ARR_RIGHT_high.xpm");
}

static void	load_highlight_xpm_suite(t_data *data)
{
	highlight_to_img(data, XK_b, "./assets/menu/keyboard_keys/B_high.xpm");
	highlight_to_img(data, XK_n, "./assets/menu/keyboard_keys/N_high.xpm");
	highlight_to_img(data, XK_m, "./assets/menu/keyboard_keys/M_high.xpm");
	highlight_to_img(data, XK_1, "./assets/menu/keyboard_keys/1_high.xpm");
	highlight_to_img(data, XK_2, "./assets/menu/keyboard_keys/2_high.xpm");
	highlight_to_img(data, XK_3, "./assets/menu/keyboard_keys/3_high.xpm");
	highlight_to_img(data, XK_4, "./assets/menu/keyboard_keys/4_high.xpm");
	highlight_to_img(data, XK_5, "./assets/menu/keyboard_keys/5_high.xpm");
	highlight_to_img(data, XK_6, "./assets/menu/keyboard_keys/6_high.xpm");
	highlight_to_img(data, XK_7, "./assets/menu/keyboard_keys/7_high.xpm");
	highlight_to_img(data, XK_8, "./assets/menu/keyboard_keys/8_high.xpm");
	highlight_to_img(data, XK_9, "./assets/menu/keyboard_keys/9_high.xpm");
	highlight_to_img(data, XK_0, "./assets/menu/keyboard_keys/0_high.xpm");
	highlight_to_img(data, XK_minus,
		"./assets/menu/keyboard_keys/Minus_high.xpm");
	highlight_to_img(data, XK_equal,
		"./assets/menu/keyboard_keys/Plus_high.xpm");
	highlight_to_img(data, XK_KP_0,
		"./assets/menu/keyboard_keys/NUM_0_high.xpm");
	highlight_to_img(data, XK_KP_1,
		"./assets/menu/keyboard_keys/NUM_1_high.xpm");
	highlight_to_img(data, XK_KP_2,
		"./assets/menu/keyboard_keys/NUM_2_high.xpm");
}

void	load_highlight_xpm(t_data *data)
{
	highlight_to_img(data, XK_w, "./assets/menu/keyboard_keys/W_high.xpm");
	highlight_to_img(data, XK_s, "./assets/menu/keyboard_keys/S_high.xpm");
	highlight_to_img(data, XK_a, "./assets/menu/keyboard_keys/A_high.xpm");
	highlight_to_img(data, XK_d, "./assets/menu/keyboard_keys/D_high.xpm");
	highlight_to_img(data, XK_k, "./assets/menu/keyboard_keys/K_high.xpm");
	highlight_to_img(data, XK_e, "./assets/menu/keyboard_keys/E_high.xpm");
	highlight_to_img(data, XK_i, "./assets/menu/keyboard_keys/I_high.xpm");
	highlight_to_img(data, XK_o, "./assets/menu/keyboard_keys/O_high.xpm");
	highlight_to_img(data, XK_p, "./assets/menu/keyboard_keys/P_high.xpm");
	highlight_to_img(data, XK_q, "./assets/menu/keyboard_keys/Q_high.xpm");
	highlight_to_img(data, XK_r, "./assets/menu/keyboard_keys/R_high.xpm");
	highlight_to_img(data, XK_t, "./assets/menu/keyboard_keys/T_high.xpm");
	highlight_to_img(data, XK_u, "./assets/menu/keyboard_keys/U_high.xpm");
	highlight_to_img(data, XK_y, "./assets/menu/keyboard_keys/Y_high.xpm");
	highlight_to_img(data, XK_f, "./assets/menu/keyboard_keys/F_high.xpm");
	highlight_to_img(data, XK_g, "./assets/menu/keyboard_keys/G_high.xpm");
	highlight_to_img(data, XK_h, "./assets/menu/keyboard_keys/H_high.xpm");
	highlight_to_img(data, XK_j, "./assets/menu/keyboard_keys/J_high.xpm");
	highlight_to_img(data, XK_l, "./assets/menu/keyboard_keys/L_high.xpm");
	highlight_to_img(data, XK_z, "./assets/menu/keyboard_keys/Z_high.xpm");
	highlight_to_img(data, XK_x, "./assets/menu/keyboard_keys/X_high.xpm");
	highlight_to_img(data, XK_c, "./assets/menu/keyboard_keys/C_high.xpm");
	highlight_to_img(data, XK_v, "./assets/menu/keyboard_keys/V_high.xpm");
	load_highlight_xpm_suite(data);
	load_highlight_xpm_suite_2(data);
}
