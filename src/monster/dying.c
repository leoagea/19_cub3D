#include "../../inc/cub3d.h"

void	enemy_dying(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	struct timeval current_time;
	long		   delta_time;

	gettimeofday(&current_time, NULL);
	delta_time =(current_time.tv_sec - data->player.anim.last_update.tv_sec) * 1000000 + (current_time.tv_usec - data->player.anim.last_update.tv_usec);
	if (delta_time >= ANIM_DIE)
	{
		enemy[player->sprite_order[i]].current_frame++;
		if (enemy[player->sprite_order[i]].current_frame == 5)
			enemy[player->sprite_order[i]].died = 2;
		enemy[player->sprite_order[i]].last_update = current_time;
	}
	enemy_draw_dying(data, player, enemy, i);
}

void	enemy_draw_dying(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	int	tex_x;
	int tex_y;
	uint32_t color;
	int	pix;
	int l;

	player->col = enemy[player->sprite_order[i]].draw_start_x;
	while (player->col < enemy[player->sprite_order[i]].draw_end_x)
	{
		tex_x = (int) (256 * (player->col - (-enemy[player->sprite_order[i]].width / 2 + enemy[player->sprite_order[i]].sprite_screen_x)) * TEXWIDTH / enemy[player->sprite_order[i]].width) / 256;
		pix = enemy[player->sprite_order[i]].draw_start_y;
		if (enemy[player->sprite_order[i]].transform_y > 0 && player->col > 0
			&& player->col < WIDTH && enemy[player->sprite_order[i]].transform_y < player->z_buffer[player->col])
		{
			while (pix < enemy[player->sprite_order[i]].draw_end_y)
			{
				l = pix * 256 - HEIGHT * 128 + enemy[player->sprite_order[i]].height * 128;
				tex_y = ((l * TEXHEIGHT) / enemy[player->sprite_order[i]].height) / 256;
				color = *(uint32_t *)(enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].img_pixels_ptr 
									+ (tex_y * enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].size_line 
									+ tex_x * (enemy[player->sprite_order[i]].img_frames[enemy[player->sprite_order[i]].current_frame].bits_per_pixel / 8)));
				if ((color & 0x00FFFFFF) != 0)
					*(uint32_t *)(data->img->img_pixels_ptr + pix * data->img->size_line + player->col * (data->img->bits_per_pixel / 8)) = color;
				pix++;
			}
		}
		player->col++;
	}
}


void	enemy_draw_dead(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	int	tex_x;
	int tex_y;
	uint32_t color;
	int	pix;
	int l;

	player->col = enemy[player->sprite_order[i]].draw_start_x;
	while (player->col < enemy[player->sprite_order[i]].draw_end_x)
	{
		tex_x = (int) (256 * (player->col - (-enemy[player->sprite_order[i]].width / 2 + enemy[player->sprite_order[i]].sprite_screen_x)) * TEXWIDTH / enemy[player->sprite_order[i]].width) / 256;
		pix = enemy[player->sprite_order[i]].draw_start_y;
		if (enemy[player->sprite_order[i]].transform_y > 0 && player->col > 0
			&& player->col < WIDTH && enemy[player->sprite_order[i]].transform_y < player->z_buffer[player->col])
		{
			while (pix < enemy[player->sprite_order[i]].draw_end_y)
			{

				l = pix * 256 - HEIGHT * 128 + enemy[player->sprite_order[i]].height * 128;
				tex_y = ((l * TEXHEIGHT) / enemy[player->sprite_order[i]].height) / 256;
				color = *(uint32_t *)(enemy[player->sprite_order[i]].img_frames[5].img_pixels_ptr 
									+ (tex_y * enemy[player->sprite_order[i]].img_frames[5].size_line 
									+ tex_x * (enemy[player->sprite_order[i]].img_frames[5].bits_per_pixel / 8)));
				if ((color & 0x00FFFFFF) != 0)
					*(uint32_t *)(data->img->img_pixels_ptr + pix * data->img->size_line + player->col * (data->img->bits_per_pixel / 8)) = color;
				pix++;
			}
		}
		player->col++;
	}
}

int	verif_all_dead(t_data *data, t_enemy *enemy)
{
	int i;

	i = 0;
	while (i < data->nb_enemy)
	{
		if (enemy[i].died != 2)
			return (0);
		i++;
	}
	return (1);
}