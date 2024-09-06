/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:27:13 by lagea             #+#    #+#             */
/*   Updated: 2024/09/06 17:31:55 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	delta_distance(t_player *player)
{
	player->map_x = (int)player->pos_x;
	player->map_y = (int)player->pos_y;
	if (player->ray_dir_x == 0)
		player->delta_dist_x = 1e30;
	else
		player->delta_dist_x = fabs(1 / player->ray_dir_x);
	if (player->ray_dir_y == 0)
		player->delta_dist_y = 1e30;
	else
		player->delta_dist_y = fabs(1 / player->ray_dir_y);
}

void	init_dda(t_player *player)
{
	if (player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->pos_x - player->map_x)
			* player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->pos_x)
			* player->delta_dist_x;
	}
	if (player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->pos_y - player->map_y)
			* player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->pos_y)
			* player->delta_dist_y;
	}
}

void	dda_algorithm(t_player *player, t_data *data)
{
	while (1)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (data->file.map[player->map_y][player->map_x] == '1')
			break ;
	}
	if (player->side == 0)
		player->perp_wall_dist = player->side_dist_x - player->delta_dist_x;
	else
		player->perp_wall_dist = player->side_dist_y - player->delta_dist_y;
}

void	wall_height(t_player *player)
{
	player->wall_height = (int)(HEIGHT / player->perp_wall_dist);
	player->draw_start = -1 * player->wall_height / 2 + HEIGHT / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->wall_height / 2 + HEIGHT / 2;
	if (player->draw_end >= HEIGHT)
		player->draw_end = HEIGHT - 1;
}
