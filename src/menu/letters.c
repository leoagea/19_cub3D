/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:26:16 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 12:54:10 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_letters_xpm(t_data *data)
{
	void	**arr;

	arr = data->letters;
	if (!arr[KEY_Q] || !arr[KEY_W] || !arr[KEY_E] || !arr[KEY_R] || !arr[KEY_T]
		|| !arr[KEY_Y] || !arr[KEY_U] || !arr[KEY_I] || !arr[KEY_O]
		|| !arr[KEY_P] || !arr[KEY_A] || !arr[KEY_S] || !arr[KEY_D]
		|| !arr[KEY_F] || !arr[KEY_G] || !arr[KEY_H] || !arr[KEY_J]
		|| !arr[KEY_K] || !arr[KEY_L] || !arr[KEY_Z] || !arr[KEY_X]
		|| !arr[KEY_C] || !arr[KEY_V] || !arr[KEY_B] || !arr[KEY_N]
		|| !arr[KEY_M] || !arr[KEY_1] || !arr[KEY_2] || !arr[KEY_3]
		|| !arr[KEY_4] || !arr[KEY_5] || !arr[KEY_6] || !arr[KEY_7]
		|| !arr[KEY_8] || !arr[KEY_9] || !arr[KEY_0] || !arr[KEY_NUM_1]
		|| !arr[KEY_NUM_2] || !arr[KEY_NUM_3] || !arr[KEY_NUM_4]
		|| !arr[KEY_NUM_5] || !arr[KEY_NUM_6] || !arr[KEY_NUM_7]
		|| !arr[KEY_NUM_8] || !arr[KEY_NUM_9] || !arr[KEY_NUM_0]
		|| !arr[KEY_MINUS] || !arr[KEY_EQUAL] || !arr[KEY_UP_ARROW]
		|| !arr[KEY_DOWN_ARROW] || !arr[KEY_LEFT_ARROW]
		|| !arr[KEY_RIGHT_ARROW])
		ft_error(ERR_XPM_MENU, data);
}

static void	check_highlight_xpm(t_data *data)
{
	void	**arr;

	arr = data->highlight;
	if (!arr[KEY_Q] || !arr[KEY_W] || !arr[KEY_E] || !arr[KEY_R] || !arr[KEY_T]
		|| !arr[KEY_Y] || !arr[KEY_U] || !arr[KEY_I] || !arr[KEY_O]
		|| !arr[KEY_P] || !arr[KEY_A] || !arr[KEY_S] || !arr[KEY_D]
		|| !arr[KEY_F] || !arr[KEY_G] || !arr[KEY_H] || !arr[KEY_J]
		|| !arr[KEY_K] || !arr[KEY_L] || !arr[KEY_Z] || !arr[KEY_X]
		|| !arr[KEY_C] || !arr[KEY_V] || !arr[KEY_B] || !arr[KEY_N]
		|| !arr[KEY_M] || !arr[KEY_1] || !arr[KEY_2] || !arr[KEY_3]
		|| !arr[KEY_4] || !arr[KEY_5] || !arr[KEY_6] || !arr[KEY_7]
		|| !arr[KEY_8] || !arr[KEY_9] || !arr[KEY_0] || !arr[KEY_NUM_1]
		|| !arr[KEY_NUM_2] || !arr[KEY_NUM_3] || !arr[KEY_NUM_4]
		|| !arr[KEY_NUM_5] || !arr[KEY_NUM_6] || !arr[KEY_NUM_7]
		|| !arr[KEY_NUM_8] || !arr[KEY_NUM_9] || !arr[KEY_NUM_0]
		|| !arr[KEY_MINUS] || !arr[KEY_EQUAL] || !arr[KEY_UP_ARROW]
		|| !arr[KEY_DOWN_ARROW] || !arr[KEY_LEFT_ARROW]
		|| !arr[KEY_RIGHT_ARROW])
		ft_error(ERR_XPM_MENU, data);
}

void	load_letters(t_data *data)
{
	load_letters_xpm(data);
	load_highlight_xpm(data);
	check_letters_xpm(data);
	check_highlight_xpm(data);
}
