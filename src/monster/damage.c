#include "../../inc/cub3d.h"

void take_damage(t_player *player)
{
	player->hp = player->hp - 5;
	printf("HP left : %d\n", player->hp);
	if (player->hp <= 0)
	{
		ft_putstr_fd("YOU DIED\n", 2);
		exit (1); //LEAK
	}
}

void	enemy_die(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	struct timeval current_time;
	long		   delta_time;
	gettimeofday(&current_time, NULL);
	delta_time =(current_time.tv_sec - data->player.anim.last_update.tv_sec) * 1000000 + (current_time.tv_usec - data->player.anim.last_update.tv_usec);
	
	enemy[i].current_frame = 1;
	if (delta_time >= ANIM)
		enemy[i].current_frame++;
	enemy[i].last_update = current_time;
}
