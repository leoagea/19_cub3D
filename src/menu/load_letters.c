/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_letters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:27:10 by lagea             #+#    #+#             */
/*   Updated: 2025/01/23 17:33:19 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	load_letters_xpm_suite_2(t_data *data)
{
	letters_to_img(data, XK_Up,
		"./assets/menu/keyboard_keys/ARR_UP.xpm");
	letters_to_img(data, XK_Down,
		"./assets/menu/keyboard_keys/ARR_DOWN.xpm");
	letters_to_img(data, XK_Left,
		"./assets/menu/keyboard_keys/ARR_LEFT.xpm");
	letters_to_img(data, XK_Right,
		"./assets/menu/keyboard_keys/ARR_RIGHT.xpm");
}

static void	load_letters_xpm_suite(t_data *data)
{
	letters_to_img(data, XK_b, "./assets/menu/keyboard_keys/B.xpm");
	letters_to_img(data, XK_n, "./assets/menu/keyboard_keys/N.xpm");
	letters_to_img(data, XK_m, "./assets/menu/keyboard_keys/M.xpm");
	letters_to_img(data, XK_1, "./assets/menu/keyboard_keys/1.xpm");
	letters_to_img(data, XK_2, "./assets/menu/keyboard_keys/2.xpm");
	letters_to_img(data, XK_3, "./assets/menu/keyboard_keys/3.xpm");
	letters_to_img(data, XK_4, "./assets/menu/keyboard_keys/4.xpm");
	letters_to_img(data, XK_5, "./assets/menu/keyboard_keys/5.xpm");
	letters_to_img(data, XK_6, "./assets/menu/keyboard_keys/6.xpm");
	letters_to_img(data, XK_7, "./assets/menu/keyboard_keys/7.xpm");
	letters_to_img(data, XK_8, "./assets/menu/keyboard_keys/8.xpm");
	letters_to_img(data, XK_9, "./assets/menu/keyboard_keys/9.xpm");
	letters_to_img(data, XK_0, "./assets/menu/keyboard_keys/0.xpm");
	letters_to_img(data, XK_minus, "./assets/menu/keyboard_keys/Minus.xpm");
	letters_to_img(data, XK_equal, "./assets/menu/keyboard_keys/Plus.xpm");
	letters_to_img(data, XK_KP_0, "./assets/menu/keyboard_keys/NUM_0.xpm");
	letters_to_img(data, XK_KP_1, "./assets/menu/keyboard_keys/NUM_1.xpm");
	letters_to_img(data, XK_KP_2, "./assets/menu/keyboard_keys/NUM_2.xpm");
	letters_to_img(data, XK_KP_3, "./assets/menu/keyboard_keys/NUM_3.xpm");
	letters_to_img(data, XK_KP_4, "./assets/menu/keyboard_keys/NUM_4.xpm");
	letters_to_img(data, XK_KP_5, "./assets/menu/keyboard_keys/NUM_5.xpm");
	letters_to_img(data, XK_KP_6, "./assets/menu/keyboard_keys/NUM_6.xpm");
	letters_to_img(data, XK_KP_7, "./assets/menu/keyboard_keys/NUM_7.xpm");
	letters_to_img(data, XK_KP_8, "./assets/menu/keyboard_keys/NUM_8.xpm");
	letters_to_img(data, XK_KP_9, "./assets/menu/keyboard_keys/NUM_9.xpm");
}

void	load_letters_xpm(t_data *data)
{
	letters_to_img(data, XK_w, "./assets/menu/keyboard_keys/W.xpm");
	letters_to_img(data, XK_s, "./assets/menu/keyboard_keys/S.xpm");
	letters_to_img(data, XK_a, "./assets/menu/keyboard_keys/A.xpm");
	letters_to_img(data, XK_d, "./assets/menu/keyboard_keys/D.xpm");
	letters_to_img(data, XK_k, "./assets/menu/keyboard_keys/K.xpm");
	letters_to_img(data, XK_e, "./assets/menu/keyboard_keys/E.xpm");
	letters_to_img(data, XK_i, "./assets/menu/keyboard_keys/I.xpm");
	letters_to_img(data, XK_o, "./assets/menu/keyboard_keys/O.xpm");
	letters_to_img(data, XK_p, "./assets/menu/keyboard_keys/P.xpm");
	letters_to_img(data, XK_q, "./assets/menu/keyboard_keys/Q.xpm");
	letters_to_img(data, XK_r, "./assets/menu/keyboard_keys/R.xpm");
	letters_to_img(data, XK_t, "./assets/menu/keyboard_keys/T.xpm");
	letters_to_img(data, XK_u, "./assets/menu/keyboard_keys/U.xpm");
	letters_to_img(data, XK_y, "./assets/menu/keyboard_keys/Y.xpm");
	letters_to_img(data, XK_f, "./assets/menu/keyboard_keys/F.xpm");
	letters_to_img(data, XK_g, "./assets/menu/keyboard_keys/G.xpm");
	letters_to_img(data, XK_h, "./assets/menu/keyboard_keys/H.xpm");
	letters_to_img(data, XK_j, "./assets/menu/keyboard_keys/J.xpm");
	letters_to_img(data, XK_l, "./assets/menu/keyboard_keys/L.xpm");
	letters_to_img(data, XK_z, "./assets/menu/keyboard_keys/Z.xpm");
	letters_to_img(data, XK_x, "./assets/menu/keyboard_keys/X.xpm");
	letters_to_img(data, XK_c, "./assets/menu/keyboard_keys/C.xpm");
	letters_to_img(data, XK_v, "./assets/menu/keyboard_keys/V.xpm");
	load_letters_xpm_suite(data);
	load_letters_xpm_suite_2(data);
}
