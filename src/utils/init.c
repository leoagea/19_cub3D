/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:40:53 by lagea             #+#    #+#             */
/*   Updated: 2024/08/30 14:40:31 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_struct_file(t_data *data)
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

void init_player_struct(t_data *data)
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
    data->player.pitch = 0.0;
    data->player.is_firing = 0;
    data->player.fire_frame = 0;
}

t_color *init_color_struct(t_data *data)
{
    t_color *color;

    color = malloc(sizeof(t_color));
    if (!color)
        ft_error(ERR_ALLOC, data);
    color->r = NULL;
    color->g = NULL;
    color->b = NULL;
    color->color = 0;
    return color;
}

void init_minimap_struct(t_data *data)
{
    data->minimap = malloc(sizeof(t_minimap));
    if (!data->minimap)
        ft_error(ERR_ALLOC, data);
    data->minimap->start_x = 440;
    data->minimap->start_y = (HEIGHT - MINIMAP_SIZE) / 2;
    data->minimap->wall_thick = 0;
    data->minimap->cell_width = MINIMAP_SIZE / data->file.map_width;
    data->minimap->cell_height = MINIMAP_SIZE / data->file.map_height;
}

void init_key_struct(t_data *data)
{
    data->key.m_forward = KEY_W;    
    data->key.m_backward = KEY_S;    
    data->key.m_right = KEY_D;    
    data->key.m_left = KEY_A;    
    data->key.r_right = KEY_RIGHT_ARROW;    
    data->key.r_left = KEY_LEFT_ARROW;    
}

void init_data(t_data *data)
{
    data->img = NULL;
    data->minimap = NULL;
    data->mlx_connection = NULL;
    data->mlx_window = NULL;
    data->menu.menu = 1;
    data->menu.pause = 0;
    data->menu.mouse = 1;
    data->menu.controls = 0;
    data->menu.change = 0;
    data->nb_ennemy = 0;
    data->ennemy = NULL;
    init_key_struct(data);
}