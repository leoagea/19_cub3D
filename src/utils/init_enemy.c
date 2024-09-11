/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:00:56 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:41:24 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_enemy_struct(t_enemy *enemy, int j)
{
	enemy[j].current_frame = 0;
	enemy[j].number_frames = 6;
	enemy[j].hp = 2;
	enemy[j].has_shot = 0;
	enemy[j].was_shot = 0;
	enemy[j].died = 0;
}

static void	init_enemy_frames(t_data *data, int j, int i,
		const char tab[6][100])
{
	data->enemy[j].img_frames[i].img_ptr = mlx_xpm_file_to_image(\
		data->mlx_connection,
			(char *)tab[i], &data->enemy[j].width, &data->enemy[j].height);
	if (!data->enemy[j].img_frames[i].img_ptr)
		ft_error(ERR_XPM_ENEMY, data);
	data->enemy[j].img_frames[i].img_pixels_ptr = mlx_get_data_addr(\
		data->enemy[j].img_frames[i].img_ptr,
			&data->enemy[j].img_frames[i].bits_per_pixel,
			&data->enemy[j].img_frames[i].size_line,
			&data->enemy[j].img_frames[i].endian);
	data->enemy_alive = data->nb_enemy;
}

void	init_enemy(t_data *data, t_enemy *enemy)
{
	int			i;
	int			j;
	const char	tab[6][100] = {"assets/monster/SlayerSimple.xpm",
		"assets/monster/SlayerShoot.xpm", "assets/monster/SlayerDeath1.xpm",
		"assets/monster/SlayerDeath2.xpm",
		"assets/monster/SlayerDeath3.xpm",
		"assets/monster/SlayerDeath4.xpm"};

	j = 0;
	while (j < data->nb_enemy)
	{
		i = -1;
		init_enemy_struct(enemy, j);
		gettimeofday(&enemy[i].last_update, NULL);
		while (++i < 6)
			init_enemy_frames(data, j, i, tab);
		enemy[j].last_shoot_time = time(NULL);
		j++;
	}
	data->player.sprite_order = malloc(sizeof(int) * data->nb_enemy);
	data->player.sprite_dist = malloc(sizeof(double) * data->nb_enemy);
}
