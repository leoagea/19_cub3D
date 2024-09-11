/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dying.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:28:35 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 15:04:40 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	enemy_dying(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	struct timeval	current_time;
	long			delta_time;

	gettimeofday(&current_time, NULL);
	delta_time = (current_time.tv_sec - data->player.anim.last_update.tv_sec)
		* 1000000 + (current_time.tv_usec
			- data->player.anim.last_update.tv_usec);
	if (delta_time >= ANIM_DIE)
	{
		enemy[player->sprite_order[i]].current_frame++;
		if (enemy[player->sprite_order[i]].current_frame == 5)
			enemy[player->sprite_order[i]].died = 2;
		enemy[player->sprite_order[i]].last_update = current_time;
	}
	enemy_draw_dying(data, player, enemy, i);
}

static void	set_dying_pixels(t_data *data, t_player *player, t_enemy *enemy,
		t_draw_enemy draw)
{
	while (draw.pix < enemy[player->sprite_order[draw.i]].draw_end_y)
	{
		draw.l = draw.pix * 256 - HEIGHT * 128
			+ enemy[player->sprite_order[draw.i]].height * 128;
		draw.tex_y = ((draw.l * TEXHEIGHT)
				/ enemy[player->sprite_order[draw.i]].height) / 256;
		draw.color = *(uint32_t *)(enemy[player->sprite_order[draw.i]].\
			img_frames[enemy[player->sprite_order[draw.i]].current_frame].\
			img_pixels_ptr
				+ (draw.tex_y
					* enemy[player->sprite_order[draw.i]].img_frames[enemy \
					[player->sprite_order[draw.i]].current_frame].size_line
					+ draw.tex_x
					* (enemy[player->sprite_order[draw.i]].img_frames[enemy \
					[player->sprite_order[draw.i]].current_frame]. \
					bits_per_pixel / 8)));
		if ((draw.color & 0x00FFFFFF) != 0)
			*(uint32_t *)(data->img->img_pixels_ptr + draw.pix
					* data->img->size_line + player->col
					* (data->img->bits_per_pixel / 8)) = draw.color;
		draw.pix++;
	}
}

void	enemy_draw_dying(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	t_draw_enemy	draw;

	player->col = enemy[player->sprite_order[i]].draw_start_x;
	while (player->col < enemy[player->sprite_order[i]].draw_end_x)
	{
		draw.tex_x = (int)(256 * (player->col
					- (-enemy[player->sprite_order[i]].width / 2
						+ enemy[player->sprite_order[i]].sprite_screen_x))
				* TEXWIDTH / enemy[player->sprite_order[i]].width) / 256;
		draw.pix = enemy[player->sprite_order[i]].draw_start_y;
		if (enemy[player->sprite_order[i]].transform_y > 0 && player->col > 0
			&& player->col < WIDTH
			&& enemy[player->sprite_order[i]].transform_y < \
				player->z_buffer[player->col])
		{
			draw.i = i;
			set_dying_pixels(data, player, enemy, draw);
		}
		player->col++;
	}
}

static void	set_dead_pixels(t_data *data, t_player *player, t_enemy *enemy,
		t_draw_enemy draw)
{
	while (draw.pix < enemy[player->sprite_order[draw.i]].draw_end_y)
	{
		draw.l = draw.pix * 256 - HEIGHT * 128
			+ enemy[player->sprite_order[draw.i]].height * 128;
		draw.tex_y = ((draw.l * TEXHEIGHT)
				/ enemy[player->sprite_order[draw.i]].height) / 256;
		draw.color = *(uint32_t *)(enemy[player->sprite_order[draw.i]]. \
		img_frames[5].img_pixels_ptr
				+ (draw.tex_y
					* enemy[player->sprite_order[draw.i]].img_frames[5]. \
					size_line
					+ draw.tex_x
					* (enemy[player->sprite_order[draw.i]].img_frames[5]. \
					bits_per_pixel
						/ 8)));
		if ((draw.color & 0x00FFFFFF) != 0)
			*(uint32_t *)(data->img->img_pixels_ptr + draw.pix
					* data->img->size_line + player->col
					* (data->img->bits_per_pixel / 8)) = draw.color;
		draw.pix++;
	}
}

void	enemy_draw_dead(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	t_draw_enemy	draw;

	player->col = enemy[player->sprite_order[i]].draw_start_x;
	while (player->col < enemy[player->sprite_order[i]].draw_end_x)
	{
		draw.tex_x = (int)(256 * (player->col
					- (-enemy[player->sprite_order[i]].width / 2
						+ enemy[player->sprite_order[i]].sprite_screen_x))
				* TEXWIDTH / enemy[player->sprite_order[i]].width) / 256;
		draw.pix = enemy[player->sprite_order[i]].draw_start_y;
		if (enemy[player->sprite_order[i]].transform_y > 0 && player->col > 0
			&& player->col < WIDTH
			&& enemy[player->sprite_order[i]].transform_y < \
			player->z_buffer[player->col])
		{
			draw.i = i;
			set_dead_pixels(data, player, enemy, draw);
		}
		player->col++;
	}
}
