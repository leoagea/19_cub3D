/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:13:02 by vdarras           #+#    #+#             */
/*   Updated: 2024/09/11 19:00:20 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	load_door(t_data *data)
{
	data->texture[DOOR].img_ptr = mlx_xpm_file_to_image(
			data->mlx_connection,
			"./assets/door/door.xpm", &data->texture[DOOR].width,
			&data->texture[DOOR].height);
	data->texture[DOOR].img_pixels_ptr = mlx_get_data_addr(
			data->texture[DOOR].img_ptr,
			&(data->texture[DOOR].bits_per_pixel),
			&(data->texture[0].size_line), &(data->texture[DOOR].endian));
}

void	interact_door(t_data *data, t_player *player, t_door *door)
{
	int	i;

	i = 0;
	while (i < data->nb_door)
	{
		if (abs(door[i].x - (int)player->pos_x) < 2 && abs(door[i].y
				- (int)player->pos_y) < 2)
		{
			data->door[i].is_open = !data->door[i].is_open;
			if (data->door[i].is_open)
				data->file.map[data->door[i].y][data->door[i].x] = '0';
			else
				data->file.map[data->door[i].y][data->door[i].x] = 'D';
			break ;
		}
		i++;
	}
}

void	check_near_door(t_data *data, t_player *player, t_door *door)
{
	int	i;

	i = 0;
	while (i < data->nb_door)
	{
		if (abs(door[i].x - (int)player->pos_x) < 2 && abs(door[i].y
				- (int)player->pos_y) < 2
			&& data->file.map[data->door[i].y][data->door[i].x] == 'D')
		{
			mlx_string_put(data->mlx_connection, data->mlx_window, 450, 450,
				0x00ffffff, "Press E to open door");
		}
		else if (abs(door[i].x - (int)player->pos_x) < 2 && abs(door[i].y
				- (int)player->pos_y) < 2
			&& data->file.map[data->door[i].y][data->door[i].x] == '0')
		{
			mlx_string_put(data->mlx_connection, data->mlx_window, 450, 450,
				0x00ffffff, "Press E to close door");
		}
		i++;
	}
}
