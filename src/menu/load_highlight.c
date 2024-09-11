/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_highlight.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:56:34 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 15:15:23 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	load_highlight_xpm_suite_2(t_data *data)
{
	highlight_to_img(data, KEY_NUM_3,
		"./assets/menu/keyboard_keys/NUM_3_high.xpm");
	highlight_to_img(data, KEY_NUM_4,
		"./assets/menu/keyboard_keys/NUM_4_high.xpm");
	highlight_to_img(data, KEY_NUM_5,
		"./assets/menu/keyboard_keys/NUM_5_high.xpm");
	highlight_to_img(data, KEY_NUM_6,
		"./assets/menu/keyboard_keys/NUM_6_high.xpm");
	highlight_to_img(data, KEY_NUM_7,
		"./assets/menu/keyboard_keys/NUM_7_high.xpm");
	highlight_to_img(data, KEY_NUM_8,
		"./assets/menu/keyboard_keys/NUM_8_high.xpm");
	highlight_to_img(data, KEY_NUM_9,
		"./assets/menu/keyboard_keys/NUM_9_high.xpm");
	highlight_to_img(data, KEY_UP_ARROW,
		"./assets/menu/keyboard_keys/ARR_UP_high.xpm");
	highlight_to_img(data, KEY_DOWN_ARROW,
		"./assets/menu/keyboard_keys/ARR_DOWN_high.xpm");
	highlight_to_img(data, KEY_LEFT_ARROW,
		"./assets/menu/keyboard_keys/ARR_LEFT_high.xpm");
	highlight_to_img(data, KEY_RIGHT_ARROW,
		"./assets/menu/keyboard_keys/ARR_RIGHT_high.xpm");
}

static void	load_highlight_xpm_suite(t_data *data)
{
	highlight_to_img(data, KEY_B, "./assets/menu/keyboard_keys/B_high.xpm");
	highlight_to_img(data, KEY_N, "./assets/menu/keyboard_keys/N_high.xpm");
	highlight_to_img(data, KEY_M, "./assets/menu/keyboard_keys/M_high.xpm");
	highlight_to_img(data, KEY_1, "./assets/menu/keyboard_keys/1_high.xpm");
	highlight_to_img(data, KEY_2, "./assets/menu/keyboard_keys/2_high.xpm");
	highlight_to_img(data, KEY_3, "./assets/menu/keyboard_keys/3_high.xpm");
	highlight_to_img(data, KEY_4, "./assets/menu/keyboard_keys/4_high.xpm");
	highlight_to_img(data, KEY_5, "./assets/menu/keyboard_keys/5_high.xpm");
	highlight_to_img(data, KEY_6, "./assets/menu/keyboard_keys/6_high.xpm");
	highlight_to_img(data, KEY_7, "./assets/menu/keyboard_keys/7_high.xpm");
	highlight_to_img(data, KEY_8, "./assets/menu/keyboard_keys/8_high.xpm");
	highlight_to_img(data, KEY_9, "./assets/menu/keyboard_keys/9_high.xpm");
	highlight_to_img(data, KEY_0, "./assets/menu/keyboard_keys/0_high.xpm");
	highlight_to_img(data, KEY_MINUS,
		"./assets/menu/keyboard_keys/Minus_high.xpm");
	highlight_to_img(data, KEY_EQUAL,
		"./assets/menu/keyboard_keys/Plus_high.xpm");
	highlight_to_img(data, KEY_NUM_0,
		"./assets/menu/keyboard_keys/NUM_0_high.xpm");
	highlight_to_img(data, KEY_NUM_1,
		"./assets/menu/keyboard_keys/NUM_1_high.xpm");
	highlight_to_img(data, KEY_NUM_2,
		"./assets/menu/keyboard_keys/NUM_2_high.xpm");
}

void	load_highlight_xpm(t_data *data)
{
	highlight_to_img(data, KEY_W, "./assets/menu/keyboard_keys/W_high.xpm");
	highlight_to_img(data, KEY_S, "./assets/menu/keyboard_keys/S_high.xpm");
	highlight_to_img(data, KEY_A, "./assets/menu/keyboard_keys/A_high.xpm");
	highlight_to_img(data, KEY_D, "./assets/menu/keyboard_keys/D_high.xpm");
	highlight_to_img(data, KEY_K, "./assets/menu/keyboard_keys/K_high.xpm");
	highlight_to_img(data, KEY_E, "./assets/menu/keyboard_keys/E_high.xpm");
	highlight_to_img(data, KEY_I, "./assets/menu/keyboard_keys/I_high.xpm");
	highlight_to_img(data, KEY_O, "./assets/menu/keyboard_keys/O_high.xpm");
	highlight_to_img(data, KEY_P, "./assets/menu/keyboard_keys/P_high.xpm");
	highlight_to_img(data, KEY_Q, "./assets/menu/keyboard_keys/Q_high.xpm");
	highlight_to_img(data, KEY_R, "./assets/menu/keyboard_keys/R_high.xpm");
	highlight_to_img(data, KEY_T, "./assets/menu/keyboard_keys/T_high.xpm");
	highlight_to_img(data, KEY_U, "./assets/menu/keyboard_keys/U_high.xpm");
	highlight_to_img(data, KEY_Y, "./assets/menu/keyboard_keys/Y_high.xpm");
	highlight_to_img(data, KEY_F, "./assets/menu/keyboard_keys/F_high.xpm");
	highlight_to_img(data, KEY_G, "./assets/menu/keyboard_keys/G_high.xpm");
	highlight_to_img(data, KEY_H, "./assets/menu/keyboard_keys/H_high.xpm");
	highlight_to_img(data, KEY_J, "./assets/menu/keyboard_keys/J_high.xpm");
	highlight_to_img(data, KEY_L, "./assets/menu/keyboard_keys/L_high.xpm");
	highlight_to_img(data, KEY_Z, "./assets/menu/keyboard_keys/Z_high.xpm");
	highlight_to_img(data, KEY_X, "./assets/menu/keyboard_keys/X_high.xpm");
	highlight_to_img(data, KEY_C, "./assets/menu/keyboard_keys/C_high.xpm");
	highlight_to_img(data, KEY_V, "./assets/menu/keyboard_keys/V_high.xpm");
	load_highlight_xpm_suite(data);
	load_highlight_xpm_suite_2(data);
}
