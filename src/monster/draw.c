/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:27:46 by lagea             #+#    #+#             */
/*   Updated: 2024/09/09 17:28:28 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_low_timing(t_data *data, t_player *player, t_enemy *enemy,
		int i)
{
	enemy[player->sprite_order[i]].current_frame = SHOOT;
	if (enemy[player->sprite_order[i]].transform_y > 0
		&& enemy[player->sprite_order[i]].sprite_screen_x > 0
		&& enemy[player->sprite_order[i]].sprite_screen_x < WIDTH
		&& enemy[player->sprite_order[i]].transform_y < \
		player->z_buffer[player->col]
		&& !enemy[player->sprite_order[i]].has_shot)
	{
		take_damage(data, player);
		enemy[player->sprite_order[i]].has_shot = 1;
	}
}

static void	check_timing(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	time_t	current_time;
	double	elapsed_time;

	current_time = time(NULL);
	elapsed_time = difftime(current_time,
			enemy[player->sprite_order[i]].last_shoot_time);
	player->col = enemy[player->sprite_order[i]].draw_start_x;
	if (elapsed_time < SHOOT_DURATION)
	{
		check_low_timing(data, player, enemy, i);
	}
	else if (elapsed_time < SHOOT_DURATION + STOP_DURATION)
	{
		enemy[player->sprite_order[i]].current_frame = STAND;
		enemy[player->sprite_order[i]].has_shot = 0;
	}
	else
	{
		enemy[player->sprite_order[i]].last_shoot_time = current_time;
		enemy[player->sprite_order[i]].current_frame = SHOOT;
		enemy[player->sprite_order[i]].has_shot = 0;
	}
}

static void	set_ennemy_pixels(t_data *data, t_player *player, t_enemy *enemy,
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
				+ (draw.tex_y * enemy[player->sprite_order \
				[draw.i]].img_frames
				[enemy[player->sprite_order[draw.i]].current_frame].size_line
					+ draw.tex_x \
				* (enemy[player->sprite_order[draw.i]].img_frames[enemy[player->\
				sprite_order[draw.i]].current_frame].bits_per_pixel / 8)));
		if ((draw.color & 0x00FFFFFF) != 0)
			*(uint32_t *)(data->img->img_pixels_ptr + draw.pix
					* data->img->size_line + player->col
					* (data->img->bits_per_pixel / 8)) = draw.color;
		draw.pix++;
	}
}

void	enemy_draw(t_data *data, t_player *player, t_enemy *enemy, int i)
{
	t_draw_enemy	draw;

	check_timing(data, player, enemy, i);
	while (player->col < enemy[player->sprite_order[i]].draw_end_x)
	{
		draw.tex_x = (int)(256 * (player->col
					- (-enemy[player->sprite_order[i]].width / 2
						+ enemy[player->sprite_order[i]].sprite_screen_x))
				* TEXWIDTH / enemy[player->sprite_order[i]].width) / 256;
		draw.pix = enemy[player->sprite_order[i]].draw_start_y;
		if (enemy[player->sprite_order[i]].transform_y > 0
			&& player->col > 0
			&& player->col < WIDTH
			&& enemy[player->sprite_order[i]].transform_y < \
				player->z_buffer[player->col])
		{
			draw.i = i;
			set_ennemy_pixels(data, player, enemy, draw);
		}
		player->col++;
	}
}
