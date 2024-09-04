#include "../../inc/cub3d.h"

void take_damage(t_player *player)
{
	player->hp = player->hp - 1;
	if (player->hp <= 0)
		exit (1); //LEAK
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

// void	render_weapon(t_data *data)
// {
// 	struct timeval current_time;
// 	long		   delta_time;

// 	check_if_enemy(data, &data->player, data->enemy);
// 	gettimeofday(&current_time, NULL);
// 	delta_time =(current_time.tv_sec - data->player.anim.last_update.tv_sec) * 1000000 + (current_time.tv_usec - data->player.anim.last_update.tv_usec);
// 	if (delta_time >= ANIM)
// 	{
// 		data->player.anim.current_frame++;
// 		if (data->player.anim.current_frame >= 4)
// 		{
// 			data->player.anim.current_frame = 0;
// 			data->player.is_firing = 0;
// 		}
// 		data->player.anim.last_update = current_time;
// 		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[data->player.anim.current_frame].img_ptr, ((WIDTH - data->player.weapon[SIMPLE].width) / 2) + 100, 400);
// 	}
// 	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[data->player.anim.current_frame].img_ptr, ((WIDTH - data->player.weapon[SIMPLE].width) / 2) + 100, 400);
// }