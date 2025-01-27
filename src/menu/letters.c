/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:26:16 by lagea             #+#    #+#             */
/*   Updated: 2025/01/23 17:42:14 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_letters_xpm(t_data *data)
{
	void	**arr;

	arr = data->letters;
	if (!arr[XK_q] || !arr[XK_w] || !arr[XK_e] || !arr[XK_r] || !arr[XK_t]
		|| !arr[XK_y] || !arr[XK_u] || !arr[XK_i] || !arr[XK_o]
		|| !arr[XK_p] || !arr[XK_a] || !arr[XK_s] || !arr[XK_d]
		|| !arr[XK_f] || !arr[XK_g] || !arr[XK_h] || !arr[XK_j]
		|| !arr[XK_k] || !arr[XK_l] || !arr[XK_z] || !arr[XK_x]
		|| !arr[XK_c] || !arr[XK_v] || !arr[XK_b] || !arr[XK_n]
		|| !arr[XK_m] || !arr[XK_1] || !arr[XK_2] || !arr[XK_3]
		|| !arr[XK_4] || !arr[XK_5] || !arr[XK_6] || !arr[XK_7]
		|| !arr[XK_8] || !arr[XK_9] || !arr[XK_0] || !arr[XK_KP_1]
		|| !arr[XK_KP_2] || !arr[XK_KP_3] || !arr[XK_KP_4] || !arr[XK_KP_5]
		|| !arr[XK_KP_6] || !arr[XK_KP_7] || !arr[XK_KP_8] || !arr[XK_KP_9] 
		|| !arr[XK_KP_0] || !arr[XK_minus] || !arr[XK_equal] 
		|| !arr[XK_Up]|| !arr[XK_Down] || !arr[XK_Left]
		|| !arr[XK_Right]){
			printf("Ici\n");
			ft_error(ERR_XPM_MENU, data);
		}
}

static void	check_highlight_xpm(t_data *data)
{
	void	**arr;

	arr = data->highlight;
	if (!arr[XK_q] || !arr[XK_w] || !arr[XK_e] || !arr[XK_r] || !arr[XK_t]
		|| !arr[XK_y] || !arr[XK_u] || !arr[XK_i] || !arr[XK_o]
		|| !arr[XK_p] || !arr[XK_a] || !arr[XK_s] || !arr[XK_d]
		|| !arr[XK_f] || !arr[XK_g] || !arr[XK_h] || !arr[XK_j]
		|| !arr[XK_k] || !arr[XK_l] || !arr[XK_z] || !arr[XK_x]
		|| !arr[XK_c] || !arr[XK_v] || !arr[XK_b] || !arr[XK_n])
			printf("Ici 2\n");
	if (!arr[XK_q] || !arr[XK_w] || !arr[XK_e] || !arr[XK_r] || !arr[XK_t]
		|| !arr[XK_y] || !arr[XK_u] || !arr[XK_i] || !arr[XK_o]
		|| !arr[XK_p] || !arr[XK_a] || !arr[XK_s] || !arr[XK_d]
		|| !arr[XK_f] || !arr[XK_g] || !arr[XK_h] || !arr[XK_j]
		|| !arr[XK_k] || !arr[XK_l] || !arr[XK_z] || !arr[XK_x]
		|| !arr[XK_c] || !arr[XK_v] || !arr[XK_b] || !arr[XK_n]
		|| !arr[XK_m] || !arr[XK_1] || !arr[XK_2] || !arr[XK_3]
		|| !arr[XK_4] || !arr[XK_5] || !arr[XK_6] || !arr[XK_7]
		|| !arr[XK_8] || !arr[XK_9] || !arr[XK_0] || !arr[XK_KP_1]
		|| !arr[XK_KP_2] || !arr[XK_KP_3] || !arr[XK_KP_4] || !arr[XK_KP_5]
		|| !arr[XK_KP_6] || !arr[XK_KP_7] || !arr[XK_KP_8] || !arr[XK_KP_9] 
		|| !arr[XK_KP_0] || !arr[XK_minus] || !arr[XK_equal] 
		|| !arr[XK_Up]|| !arr[XK_Down] || !arr[XK_Left]
		|| !arr[XK_Right]){
			printf("Ici 1\n");
			ft_error(ERR_XPM_MENU, data);
		}
}

void	load_letters(t_data *data)
{
	load_letters_xpm(data);
	load_highlight_xpm(data);
	check_letters_xpm(data);
	check_highlight_xpm(data);
}
