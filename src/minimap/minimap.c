/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:24:55 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 19:37:42 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	create_minimap(t_data *data)
{
	draw_horizontal_minimap_border(data, data->minimap.start_y - 2,
		MINIMAP_BORDER_THICKNESS);
	draw_horizontal_minimap_border(data, data->minimap.end_y + 1,
		MINIMAP_BORDER_THICKNESS);
	draw_vertical_minimap_border(data, data->minimap.start_x - 2,
		MINIMAP_BORDER_THICKNESS);
	draw_vertical_minimap_border(data, data->minimap.end_x + 1,
		MINIMAP_BORDER_THICKNESS);
	draw_tiles(data);
	draw_player(data);
	draw_enemies(data);
}

void	calc_map_enemies(t_data *data, int *enemy_x, int *enemy_y, int i)
{
	*enemy_x = data->minimap.start_x + (data->enemy[i].pos_x
			- data->player.pos_x + data->minimap.offset)
		* data->minimap.map_size / (data->minimap.offset * 2);
	*enemy_y = data->minimap.start_y + (data->enemy[i].pos_y
			- data->player.pos_y + data->minimap.offset)
		* data->minimap.map_size / (data->minimap.offset * 2);
}
