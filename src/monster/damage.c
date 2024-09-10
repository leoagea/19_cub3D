/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:42:58 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 17:29:46 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	take_damage(t_data *data, t_player *player)
{
	player->hp = player->hp - 5;
	printf("HP left : %d\n", player->hp);
	if (player->hp <= 0 && !data->menu.dead)
	{
		ft_putstr_fd("Game over : You died\n", 1);
		data->menu.dead = 1;
	}
}

void	enemy_die(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	struct timeval	current_time;
	long			delta_time;

	gettimeofday(&current_time, NULL);
	delta_time = (current_time.tv_sec - data->player.anim.last_update.tv_sec)
		* 1000000 + (current_time.tv_usec
			- data->player.anim.last_update.tv_usec);
	enemy[i].current_frame = 1;
	if (delta_time >= ANIM)
		enemy[i].current_frame++;
	enemy[i].last_update = current_time;
}

int	verif_all_dead(t_data *data, t_enemy *enemy)
{
	int	i;

	i = 0;
	while (i < data->nb_enemy)
	{
		if (enemy[i].died != 2)
			return (0);
		i++;
	}
	return (1);
}
