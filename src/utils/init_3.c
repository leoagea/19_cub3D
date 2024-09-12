/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:59:59 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 12:42:43 by lagea            ###   ########.fr       */
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
