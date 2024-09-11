/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:35:20 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:40:32 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_sensibility(t_data *data)
{
	if (data->slider[0].pos_slider == 1)
		data->player.sensibility = 0.00025;
	else if (data->slider[0].pos_slider == 2)
		data->player.sensibility = 0.00050;
	else if (data->slider[0].pos_slider == 3)
		data->player.sensibility = 0.00075;
	else if (data->slider[0].pos_slider == 4)
		data->player.sensibility = 0.0010;
	else if (data->slider[0].pos_slider == 5)
		data->player.sensibility = 0.0015;
	else if (data->slider[0].pos_slider == 6)
		data->player.sensibility = 0.0020;
	else if (data->slider[0].pos_slider == 7)
		data->player.sensibility = 0.0025;
}

void	draw_slider_sensi(t_data *data)
{
	if (data->slider[0].pos_slider == 1)
		create_cursor(data, data->slider[0].start_x, 449);
	else if (data->slider[0].pos_slider == 2)
		create_cursor(data, data->slider[0].start_x + 50, 449);
	else if (data->slider[0].pos_slider == 3)
		create_cursor(data, data->slider[0].start_x + 100, 449);
	else if (data->slider[0].pos_slider == 4)
		create_cursor(data, data->slider[0].start_x + 150, 449);
	else if (data->slider[0].pos_slider == 5)
		create_cursor(data, data->slider[0].start_x + 200, 449);
	else if (data->slider[0].pos_slider == 6)
		create_cursor(data, data->slider[0].start_x + 250, 449);
	else if (data->slider[0].pos_slider == 7)
		create_cursor(data, data->slider[0].start_x + SLIDERS_LEN, 449);
	set_sensibility(data);
}

void	set_difficulty(t_data *data)
{
	if (data->slider[1].pos_slider == 1)
		data->player.damage = 1;
	else if (data->slider[1].pos_slider == 2)
		data->player.damage = 5;
	else if (data->slider[1].pos_slider == 3)
		data->player.damage = 10;
}

void	draw_slider_dmg(t_data *data, t_slider slider)
{
	if (slider.pos_slider == 1)
		create_cursor(data, slider.start_x, 349);
	else if (slider.pos_slider == 2)
		create_cursor(data, slider.start_x + 150, 349);
	else if (slider.pos_slider == 3)
		create_cursor(data, slider.start_x + SLIDERS_LEN, 349);
	set_difficulty(data);
}
