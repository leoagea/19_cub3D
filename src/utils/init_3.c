/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:59:59 by lagea             #+#    #+#             */
/*   Updated: 2024/09/17 14:56:45 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 6)
		data->texture[i].img_ptr = NULL;
}

void	init_ennemy_textures(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->nb_enemy)
	{
		i = -1;
		while (++i < 6)
			data->enemy[j].img_frames[i].img_ptr = NULL;
	}
}

void	init_weapon_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		data->player.weapon[i].img_ptr = NULL;
}

void	init_menu_struct(t_data *data)
{
	data->menu.menu = 1;
	data->menu.pause = 0;
	data->menu.mouse = 1;
	data->menu.controls = 0;
	data->menu.change = 0;
	data->menu.dead = 0;
	data->menu.victory = 0;
	data->menu.playing = 0;
	data->menu.check_win = 0;
}
