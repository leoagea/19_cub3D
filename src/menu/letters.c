/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:26:16 by lagea             #+#    #+#             */
/*   Updated: 2024/09/02 16:12:46 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_letters(t_data *data)
{
    int x;
    int y;
    int i = -1;
    
    while (++i < 128)
        data->letters[i] = NULL;
    i = -1;
    while (++i < 128)
        data->highlight[i] = NULL;
    data->letters[KEY_W] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/W.xpm",&x, &y);
    data->letters[KEY_S] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/S.xpm",&x, &y);
    data->letters[KEY_A] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/A.xpm",&x, &y);
    data->letters[KEY_D] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/D.xpm",&x, &y);
    data->letters[KEY_K] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/K.xpm",&x, &y);
    data->letters[KEY_E] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/E.xpm",&x, &y);
    data->letters[KEY_I] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/I.xpm",&x, &y);
    data->letters[KEY_O] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/O.xpm",&x, &y);
    data->letters[KEY_P] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/P.xpm",&x, &y);
    data->letters[KEY_Q] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Q.xpm",&x, &y);
    data->letters[KEY_R] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/R.xpm",&x, &y);
    data->letters[KEY_T] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/T.xpm",&x, &y);
    data->letters[KEY_U] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/U.xpm",&x, &y);
    data->letters[KEY_Y] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Y.xpm",&x, &y);
    data->letters[KEY_F] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/F.xpm",&x, &y);
    data->letters[KEY_G] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/G.xpm",&x, &y);
    data->letters[KEY_H] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/H.xpm",&x, &y);
    data->letters[KEY_J] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/J.xpm",&x, &y);
    data->letters[KEY_L] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/L.xpm",&x, &y);
    data->letters[KEY_Z] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Z.xpm",&x, &y);
    data->letters[KEY_X] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/X.xpm",&x, &y);
    data->letters[KEY_C] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/C.xpm",&x, &y);
    data->letters[KEY_V] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/V.xpm",&x, &y);
    data->letters[KEY_B] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/B.xpm",&x, &y);
    data->letters[KEY_N] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/N.xpm",&x, &y);
    data->letters[KEY_M] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/M.xpm",&x, &y);
    data->letters[KEY_1] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/1.xpm",&x, &y);
    data->letters[KEY_2] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/2.xpm",&x, &y);
    data->letters[KEY_3] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/3.xpm",&x, &y);
    data->letters[KEY_4] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/4.xpm",&x, &y);
    data->letters[KEY_5] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/5.xpm",&x, &y);
    data->letters[KEY_6] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/6.xpm",&x, &y);
    data->letters[KEY_7] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/7.xpm",&x, &y);
    data->letters[KEY_8] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/8.xpm",&x, &y);
    data->letters[KEY_9] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/9.xpm",&x, &y);
    data->letters[KEY_0] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/0.xpm",&x, &y);
    data->letters[KEY_MINUS] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Minus.xpm",&x, &y);
    data->letters[KEY_EQUAL] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Plus.xpm",&x, &y);
    data->letters[KEY_NUM_0] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_0.xpm",&x, &y);
    data->letters[KEY_NUM_1] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_1.xpm",&x, &y);
    data->letters[KEY_NUM_2] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_2.xpm",&x, &y);
    data->letters[KEY_NUM_3] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_3.xpm",&x, &y);
    data->letters[KEY_NUM_4] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_4.xpm",&x, &y);
    data->letters[KEY_NUM_5] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_5.xpm",&x, &y);
    data->letters[KEY_NUM_6] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_6.xpm",&x, &y);
    data->letters[KEY_NUM_7] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_7.xpm",&x, &y);
    data->letters[KEY_NUM_8] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_8.xpm",&x, &y);
    data->letters[KEY_NUM_9] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_9.xpm",&x, &y);

    data->highlight[KEY_W] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/W_high.xpm",&x, &y);
    data->highlight[KEY_S] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/S_high.xpm",&x, &y);
    data->highlight[KEY_A] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/A_high.xpm",&x, &y);
    data->highlight[KEY_D] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/D_high.xpm",&x, &y);
    data->highlight[KEY_K] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/K_high.xpm",&x, &y);
    data->highlight[KEY_E] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/E_high.xpm",&x, &y);
    data->highlight[KEY_I] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/I_high.xpm",&x, &y);
    data->highlight[KEY_O] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/O_high.xpm",&x, &y);
    data->highlight[KEY_P] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/P_high.xpm",&x, &y);
    data->highlight[KEY_Q] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Q_high.xpm",&x, &y);
    data->highlight[KEY_R] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/R_high.xpm",&x, &y);
    data->highlight[KEY_T] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/T_high.xpm",&x, &y);
    data->highlight[KEY_U] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/U_high.xpm",&x, &y);
    data->highlight[KEY_Y] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Y_high.xpm",&x, &y);
    data->highlight[KEY_F] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/F_high.xpm",&x, &y);
    data->highlight[KEY_G] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/G_high.xpm",&x, &y);
    data->highlight[KEY_H] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/H_high.xpm",&x, &y);
    data->highlight[KEY_J] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/J_high.xpm",&x, &y);
    data->highlight[KEY_L] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/L_high.xpm",&x, &y);
    data->highlight[KEY_Z] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Z_high.xpm",&x, &y);
    data->highlight[KEY_X] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/X_high.xpm",&x, &y);
    data->highlight[KEY_C] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/C_high.xpm",&x, &y);
    data->highlight[KEY_V] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/V_high.xpm",&x, &y);
    data->highlight[KEY_B] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/B_high.xpm",&x, &y);
    data->highlight[KEY_N] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/N_high.xpm",&x, &y);
    data->highlight[KEY_M] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/M_high.xpm",&x, &y);
    data->highlight[KEY_1] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/1_high.xpm",&x, &y);
    data->highlight[KEY_2] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/2_high.xpm",&x, &y);
    data->highlight[KEY_3] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/3_high.xpm",&x, &y);
    data->highlight[KEY_4] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/4_high.xpm",&x, &y);
    data->highlight[KEY_5] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/5_high.xpm",&x, &y);
    data->highlight[KEY_6] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/6_high.xpm",&x, &y);
    data->highlight[KEY_7] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/7_high.xpm",&x, &y);
    data->highlight[KEY_8] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/8_high.xpm",&x, &y);
    data->highlight[KEY_9] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/9_high.xpm",&x, &y);
    data->highlight[KEY_0] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/0_high.xpm",&x, &y);
    data->highlight[KEY_MINUS] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Minu_high..xpm",&x, &y);
    data->highlight[KEY_EQUAL] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/Plus_high.xpm",&x, &y);
    data->highlight[KEY_NUM_0] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_0_high.xpm",&x, &y);
    data->highlight[KEY_NUM_1] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_1_high.xpm",&x, &y);
    data->highlight[KEY_NUM_2] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_2_high.xpm",&x, &y);
    data->highlight[KEY_NUM_3] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_3_high.xpm",&x, &y);
    data->highlight[KEY_NUM_4] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_4_high.xpm",&x, &y);
    data->highlight[KEY_NUM_5] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_5_high.xpm",&x, &y);
    data->highlight[KEY_NUM_6] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_6_high.xpm",&x, &y);
    data->highlight[KEY_NUM_7] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_7_high.xpm",&x, &y);
    data->highlight[KEY_NUM_8] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_8_high.xpm",&x, &y);
    data->highlight[KEY_NUM_9] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/keyboard_keys/NUM_9_high.xpm",&x, &y);
    
    if (!data->letters[KEY_Q] || !data->letters[KEY_W] || !data->letters[KEY_E] || !data->letters[KEY_R] || !data->letters[KEY_T] || !data->letters[KEY_Y] \
    || !data->letters[KEY_U] || !data->letters[KEY_I] || !data->letters[KEY_O] || !data->letters[KEY_P] || !data->letters[KEY_A] || !data->letters[KEY_S] \
    || !data->letters[KEY_D] || !data->letters[KEY_F] || !data->letters[KEY_G] || !data->letters[KEY_H] || !data->letters[KEY_J] || !data->letters[KEY_K] \
    || !data->letters[KEY_L] || !data->letters[KEY_Z] || !data->letters[KEY_X] || !data->letters[KEY_C] || !data->letters[KEY_V] || !data->letters[KEY_B] \
    || !data->letters[KEY_N] || !data->letters[KEY_M] || !data->letters[KEY_1] || !data->letters[KEY_2] || !data->letters[KEY_3] || !data->letters[KEY_4] \
    || !data->letters[KEY_5] || !data->letters[KEY_6] || !data->letters[KEY_7] || !data->letters[KEY_8] || !data->letters[KEY_9] || !data->letters[KEY_0] \
    || !data->letters[KEY_NUM_1] || !data->letters[KEY_NUM_2] || !data->letters[KEY_NUM_3] || !data->letters[KEY_NUM_4] || !data->letters[KEY_NUM_5] \
    || !data->letters[KEY_NUM_6] || !data->letters[KEY_NUM_7] || !data->letters[KEY_NUM_8] || !data->letters[KEY_NUM_9] || !data->letters[KEY_NUM_0])
        ft_error(ERR_XPM_MENU, data);
    if (!data->highlight[KEY_Q] || !data->highlight[KEY_W] || !data->highlight[KEY_E] || !data->highlight[KEY_R] || !data->highlight[KEY_T] || !data->highlight[KEY_Y] \
    || !data->highlight[KEY_U] || !data->highlight[KEY_I] || !data->highlight[KEY_O] || !data->highlight[KEY_P] || !data->highlight[KEY_A] || !data->highlight[KEY_S] \
    || !data->highlight[KEY_D] || !data->highlight[KEY_F] || !data->highlight[KEY_G] || !data->highlight[KEY_H] || !data->highlight[KEY_J] || !data->highlight[KEY_K] \
    || !data->highlight[KEY_L] || !data->highlight[KEY_Z] || !data->highlight[KEY_X] || !data->highlight[KEY_C] || !data->highlight[KEY_V] || !data->highlight[KEY_B] \
    || !data->highlight[KEY_N] || !data->highlight[KEY_M] || !data->highlight[KEY_1] || !data->highlight[KEY_2] || !data->highlight[KEY_3] || !data->highlight[KEY_4] \
    || !data->highlight[KEY_5] || !data->highlight[KEY_6] || !data->highlight[KEY_7] || !data->highlight[KEY_8] || !data->highlight[KEY_9] || !data->highlight[KEY_0] \
    || !data->highlight[KEY_NUM_1] || !data->highlight[KEY_NUM_2] || !data->highlight[KEY_NUM_3] || !data->highlight[KEY_NUM_4] || !data->highlight[KEY_NUM_5] \
    || !data->highlight[KEY_NUM_6] || !data->highlight[KEY_NUM_7] || !data->highlight[KEY_NUM_8] || !data->highlight[KEY_NUM_9] || !data->highlight[KEY_NUM_0])
        ft_error(ERR_XPM_MENU, data);
}
