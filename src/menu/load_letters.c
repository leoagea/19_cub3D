/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_letters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:27:10 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 15:14:38 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	load_letters_xpm_suite_2(t_data *data)
{
	letters_to_img(data, KEY_UP_ARROW,
		"./assets/menu/keyboard_keys/ARR_UP.xpm");
	letters_to_img(data, KEY_DOWN_ARROW,
		"./assets/menu/keyboard_keys/ARR_DOWN.xpm");
	letters_to_img(data, KEY_LEFT_ARROW,
		"./assets/menu/keyboard_keys/ARR_LEFT.xpm");
	letters_to_img(data, KEY_RIGHT_ARROW,
		"./assets/menu/keyboard_keys/ARR_RIGHT.xpm");
}

static void	load_letters_xpm_suite(t_data *data)
{
	letters_to_img(data, KEY_B, "./assets/menu/keyboard_keys/B.xpm");
	letters_to_img(data, KEY_N, "./assets/menu/keyboard_keys/N.xpm");
	letters_to_img(data, KEY_M, "./assets/menu/keyboard_keys/M.xpm");
	letters_to_img(data, KEY_1, "./assets/menu/keyboard_keys/1.xpm");
	letters_to_img(data, KEY_2, "./assets/menu/keyboard_keys/2.xpm");
	letters_to_img(data, KEY_3, "./assets/menu/keyboard_keys/3.xpm");
	letters_to_img(data, KEY_4, "./assets/menu/keyboard_keys/4.xpm");
	letters_to_img(data, KEY_5, "./assets/menu/keyboard_keys/5.xpm");
	letters_to_img(data, KEY_6, "./assets/menu/keyboard_keys/6.xpm");
	letters_to_img(data, KEY_7, "./assets/menu/keyboard_keys/7.xpm");
	letters_to_img(data, KEY_8, "./assets/menu/keyboard_keys/8.xpm");
	letters_to_img(data, KEY_9, "./assets/menu/keyboard_keys/9.xpm");
	letters_to_img(data, KEY_0, "./assets/menu/keyboard_keys/0.xpm");
	letters_to_img(data, KEY_MINUS, "./assets/menu/keyboard_keys/Minus.xpm");
	letters_to_img(data, KEY_EQUAL, "./assets/menu/keyboard_keys/Plus.xpm");
	letters_to_img(data, KEY_NUM_0, "./assets/menu/keyboard_keys/NUM_0.xpm");
	letters_to_img(data, KEY_NUM_1, "./assets/menu/keyboard_keys/NUM_1.xpm");
	letters_to_img(data, KEY_NUM_2, "./assets/menu/keyboard_keys/NUM_2.xpm");
	letters_to_img(data, KEY_NUM_3, "./assets/menu/keyboard_keys/NUM_3.xpm");
	letters_to_img(data, KEY_NUM_4, "./assets/menu/keyboard_keys/NUM_4.xpm");
	letters_to_img(data, KEY_NUM_5, "./assets/menu/keyboard_keys/NUM_5.xpm");
	letters_to_img(data, KEY_NUM_6, "./assets/menu/keyboard_keys/NUM_6.xpm");
	letters_to_img(data, KEY_NUM_7, "./assets/menu/keyboard_keys/NUM_7.xpm");
	letters_to_img(data, KEY_NUM_8, "./assets/menu/keyboard_keys/NUM_8.xpm");
	letters_to_img(data, KEY_NUM_9, "./assets/menu/keyboard_keys/NUM_9.xpm");
}

void	load_letters_xpm(t_data *data)
{
	letters_to_img(data, KEY_W, "./assets/menu/keyboard_keys/W.xpm");
	letters_to_img(data, KEY_S, "./assets/menu/keyboard_keys/S.xpm");
	letters_to_img(data, KEY_A, "./assets/menu/keyboard_keys/A.xpm");
	letters_to_img(data, KEY_D, "./assets/menu/keyboard_keys/D.xpm");
	letters_to_img(data, KEY_K, "./assets/menu/keyboard_keys/K.xpm");
	letters_to_img(data, KEY_E, "./assets/menu/keyboard_keys/E.xpm");
	letters_to_img(data, KEY_I, "./assets/menu/keyboard_keys/I.xpm");
	letters_to_img(data, KEY_O, "./assets/menu/keyboard_keys/O.xpm");
	letters_to_img(data, KEY_P, "./assets/menu/keyboard_keys/P.xpm");
	letters_to_img(data, KEY_Q, "./assets/menu/keyboard_keys/Q.xpm");
	letters_to_img(data, KEY_R, "./assets/menu/keyboard_keys/R.xpm");
	letters_to_img(data, KEY_T, "./assets/menu/keyboard_keys/T.xpm");
	letters_to_img(data, KEY_U, "./assets/menu/keyboard_keys/U.xpm");
	letters_to_img(data, KEY_Y, "./assets/menu/keyboard_keys/Y.xpm");
	letters_to_img(data, KEY_F, "./assets/menu/keyboard_keys/F.xpm");
	letters_to_img(data, KEY_G, "./assets/menu/keyboard_keys/G.xpm");
	letters_to_img(data, KEY_H, "./assets/menu/keyboard_keys/H.xpm");
	letters_to_img(data, KEY_J, "./assets/menu/keyboard_keys/J.xpm");
	letters_to_img(data, KEY_L, "./assets/menu/keyboard_keys/L.xpm");
	letters_to_img(data, KEY_Z, "./assets/menu/keyboard_keys/Z.xpm");
	letters_to_img(data, KEY_X, "./assets/menu/keyboard_keys/X.xpm");
	letters_to_img(data, KEY_C, "./assets/menu/keyboard_keys/C.xpm");
	letters_to_img(data, KEY_V, "./assets/menu/keyboard_keys/V.xpm");
	load_letters_xpm_suite(data);
	load_letters_xpm_suite_2(data);
}
