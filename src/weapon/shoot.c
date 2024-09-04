#include "../../inc/cub3d.h"

void	render_weapon(t_data *data)
{
	struct timeval current_time;
	long		   delta_time;

	check_if_enemy(data, &data->player, data->enemy);
	gettimeofday(&current_time, NULL);
	delta_time =(current_time.tv_sec - data->player.anim.last_update.tv_sec) * 1000000 + (current_time.tv_usec - data->player.anim.last_update.tv_usec);
	if (delta_time >= ANIM)
	{
		data->player.anim.current_frame++;
		if (data->player.anim.current_frame >= 4)
		{
			data->player.anim.current_frame = 0;
			data->player.is_firing = 0;
		}
		data->player.anim.last_update = current_time;
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[data->player.anim.current_frame].img_ptr,((WIDTH - data->player.weapon[SIMPLE].width) / 2) + 100, 400);
	}
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->player.weapon[data->player.anim.current_frame].img_ptr,((WIDTH - data->player.weapon[SIMPLE].width) / 2) + 100, 400);
}

void	check_if_enemy(t_data *data, t_player *player, t_enemy *enemy)
{
	int hitbox;
	int	enemy_center;
	int	i;

	i = 0;
	while (i < data->nb_enemy)
	{
		enemy_center = enemy[i].sprite_screen_x;
		hitbox = (1 / enemy[i].transform_y) * 150;
		if (enemy[i].transform_y > 0 && enemy_center > (WIDTH / 2 - hitbox)
									 && enemy_center < (WIDTH / 2 + hitbox)
									 && enemy[i].transform_y < player->z_buffer[WIDTH / 2]
									 && !enemy[i].was_shot)
		{
			enemy[i].hp--;
			// printf("Monster number %d has lost 1 hp, hp left %d", i, enemy[i].hp);
			if (enemy[i].hp <= 0)
				enemy[i].died = 1;
			ft_putstr_fd("SHOT\n", 2);
			enemy[i].was_shot = 1;
		}
		i++;
	}
}

void	reset_shot(t_data *data, t_enemy *enemy)
{
	int i;

	i = 0;
	while (i < data->nb_enemy)
	{
		enemy[i].was_shot = 0;
		i++;	
	}
}