/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:41:56 by lagea             #+#    #+#             */
/*   Updated: 2024/09/09 17:36:33 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	sort_sprites(t_data *data, t_player *player)
{
	int		i;
	int		j;
	double	tmp;
	int		is_sort;

	i = data->nb_enemy;
	while (i > 0)
	{
		j = 0;
		while (j < i - 1)
		{
			if (player->sprite_dist[j] < player->sprite_dist[j + 1])
			{
				tmp = player->sprite_dist[j];
				player->sprite_dist[j] = player->sprite_dist[j + 1];
				player->sprite_dist[j + 1] = tmp;
				tmp = player->sprite_order[j];
				player->sprite_order[j] = player->sprite_order[j + 1];
				player->sprite_order[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

static void	calcul_enemy_dist(t_data *data, t_player *player, t_enemy *enemy)
{
	int	i;

	i = 0;
	while (i < data->nb_enemy)
	{
		player->sprite_order[i] = i;
		player->sprite_dist[i] = sqrt(((player->pos_x - enemy[i].pos_x)
					* (player->pos_x - enemy[i].pos_x)) + ((player->pos_y
						- enemy[i].pos_y) * (player->pos_y - enemy[i].pos_y)));
		i++;
	}
}

void	enemy_calculation(t_data *data, t_player *player, t_enemy *enemy)
{
	int	i;

	calcul_enemy_dist(data, player, enemy);
	sort_sprites(data, player);
	i = 0;
	while (i < data->nb_enemy)
	{
		enemy_raycast(player, enemy, i);
		if (enemy[player->sprite_order[i]].died == 0)
			enemy_draw(data, player, enemy, i);
		if (enemy[player->sprite_order[i]].died == 1)
			enemy_dying(data, player, enemy, i);
		if (enemy[player->sprite_order[i]].died == 2)
		{
			data->file.map[(int)enemy[player->sprite_order[i]].pos_y] \
			[(int)enemy[player->sprite_order[i]].pos_x] = '0';
			enemy_draw_dead(data, player, enemy, i);
		}
		i++;
	}
}

static void	enemy_raycast_suite(t_player *player, t_enemy *enemy, int i)
{
	if (enemy[player->sprite_order[i]].draw_start_y < 0)
		enemy[player->sprite_order[i]].draw_start_y = 0;
	enemy[player->sprite_order[i]].draw_end_y = \
		enemy[player->sprite_order[i]].height / 2 + HEIGHT / 2;
	if (enemy[player->sprite_order[i]].draw_end_y >= HEIGHT)
		enemy[player->sprite_order[i]].draw_end_y = HEIGHT - 1;
	enemy[player->sprite_order[i]].width = abs((int)(HEIGHT
				/ enemy[player->sprite_order[i]].transform_y));
	enemy[player->sprite_order[i]].draw_start_x = \
		-enemy[player->sprite_order[i]].width / 2
		+ enemy[player->sprite_order[i]].sprite_screen_x;
	if (enemy[player->sprite_order[i]].draw_start_x < 0)
		enemy[player->sprite_order[i]].draw_start_x = 0;
	enemy[player->sprite_order[i]].draw_end_x = \
		enemy[player->sprite_order[i]].width
		/ 2 + enemy[player->sprite_order[i]].sprite_screen_x;
	if (enemy[player->sprite_order[i]].draw_end_x >= WIDTH)
		enemy[player->sprite_order[i]].draw_end_x = WIDTH - 1;
}

void	enemy_raycast(t_player *player, t_enemy *enemy, int i)
{
	enemy[player->sprite_order[i]].pos_x_cam = \
		enemy[player->sprite_order[i]].pos_x - player->pos_x;
	enemy[player->sprite_order[i]].pos_y_cam = \
		enemy[player->sprite_order[i]].pos_y - player->pos_y;
	enemy[player->sprite_order[i]].inverse_matrix = 1.0 / (player->plane_x
			* player->dir_y - player->plane_y * player->dir_x);
	enemy[player->sprite_order[i]].transform_x = \
		enemy[player->sprite_order[i]].inverse_matrix
		* (player->dir_y * enemy[player->sprite_order[i]].pos_x_cam
			- player->dir_x * enemy[player->sprite_order[i]].pos_y_cam);
	enemy[player->sprite_order[i]].transform_y = \
		enemy[player->sprite_order[i]].inverse_matrix
		* (-player->plane_y * enemy[player->sprite_order[i]].pos_x_cam
			+ player->plane_x * enemy[player->sprite_order[i]].pos_y_cam);
	enemy[player->sprite_order[i]].sprite_screen_x = (int)((WIDTH / 2) * (1
				+ enemy[player->sprite_order[i]].transform_x
				/ enemy[player->sprite_order[i]].transform_y));
	enemy[player->sprite_order[i]].height = abs((int)(HEIGHT
				/ enemy[player->sprite_order[i]].transform_y));
	enemy[player->sprite_order[i]].draw_start_y = \
		-enemy[player->sprite_order[i]].height / 2 + HEIGHT / 2;
	enemy_raycast_suite(player, enemy, i);
}
