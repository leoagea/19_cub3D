/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:18:48 by lagea             #+#    #+#             */
/*   Updated: 2024/08/22 19:03:32 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_minimap(t_data *data)
{
	int i;
	int j;
	char **map;
	
	int start_x;
	int start_y;
	i = 0;
	map = data->file->map;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '1')
			{
				start_x = data->minimap->start_x + (data->minimap->cell_width * j);
				start_y = data->minimap->start_y + (data->minimap->cell_height * i);
				// printf("start x cell : %d\nstart y cell : %d\n", start_x, start_y);
				draw_cell(data, start_x, start_y, 5984850);
			}
			j++;
		}
		i++;
	}
	draw_cell(data,(data->minimap->cell_width * (int)data->player->pos_x) + data->minimap->start_x, (data->minimap->cell_height * (int) data->player->pos_y ) + data->minimap->start_y, 12779520);
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img->img_ptr, 0, 0);
}

void create_minimap(t_data *data)
{
    init_minimap_struct(data);
	draw_minimap(data);
}
