/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:40:53 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:41:30 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_struct_file(t_data *data)
{
	data->file.line = 0;
	data->file.count = 0;
	data->file.map = NULL;
	data->file.cpy = NULL;
	data->file.file = NULL;
	data->file.wall_no = NULL;
	data->file.wall_so = NULL;
	data->file.wall_we = NULL;
	data->file.wall_ea = NULL;
	data->file.c_floor = NULL;
	data->file.c_ceiling = NULL;
	data->file.color_floor = NULL;
	data->file.color_ceiling = NULL;
	data->file.flag_no = 0;
	data->file.flag_so = 0;
	data->file.flag_ea = 0;
	data->file.flag_we = 0;
	data->file.flag_f = 0;
	data->file.flag_c = 0;
}

void	init_player_struct(t_data *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0;
	data->player.key_backward = 0;
	data->player.key_forward = 0;
	data->player.key_left = 0;
	data->player.key_right = 0;
	data->player.key_move_left = 0;
	data->player.key_move_right = 0;
	data->player.speed = 0.1;
	data->player.is_firing = 0;
	data->player.fire_frame = 0;
	data->player.counter = 0;
	data->player.hp = 100;
	data->player.fov = 77;
	data->player.sensibility = 0.0010;
	data->player.damage = 5;
}

t_color	*init_color_struct(t_data *data)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		ft_error(ERR_ALLOC, data);
	color->r = NULL;
	color->g = NULL;
	color->b = NULL;
	color->color = 0;
	return (color);
}

void	init_data(t_data *data)
{
	data->img = NULL;
	data->mlx_connection = NULL;
	data->mlx_window = NULL;
	data->player.anim.current_frame = 0;
	gettimeofday(&data->player.anim.last_update, NULL);
	data->menu.menu = 1;
	data->menu.pause = 0;
	data->menu.mouse = 1;
	data->menu.controls = 0;
	data->menu.change = 0;
	data->menu.dead = 0;
	data->menu.victory = 0;
	data->menu.playing = 0;
	data->menu.check_win = 0;
	data->nb_enemy = 0;
	data->enemy = NULL;
	data->nb_door = 0;
	data->door = NULL;
	init_key_struct(data);
	init_minimap_struct(data);
	init_slider_struct(data);
	init_xpm_struct(data);
}
