/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:40:53 by lagea             #+#    #+#             */
/*   Updated: 2024/08/22 14:14:25 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_struct_file(t_data *data)
{
    data->file = malloc(sizeof(t_file));
    if (!data->file)
        ft_error(ERR_ALLOC, data);
    data->file->line = 0;
    data->file->count = 0;
    data->file->map = NULL;
    data->file->cpy = NULL;
    data->file->file = NULL;
    data->file->wall_no = NULL;
    data->file->wall_so = NULL;
    data->file->wall_we = NULL;
    data->file->wall_ea = NULL;
    data->file->c_floor = NULL;
    data->file->c_ceiling = NULL;
    data->file->color_floor = NULL;
    data->file->color_ceiling = NULL;
}

void init_player_struct(t_data *data)
{
    data->player = malloc(sizeof(t_player));
    if (!data->player)
        ft_error(ERR_ALLOC, data);
    data->player->pos_x = 0;
    data->player->pos_y = 0;
    data->player->dir_x = 0;
    data->player->dir_y = 0;
    data->player->plane_x = 0;
    data->player->plane_y = 0;
    data->player->key_backward = 0;
	data->player->key_forward = 0;
	data->player->key_left = 0;
	data->player->key_right = 0;
}

void init_fps_struct(t_data *data)
{
    data->player->fps->delta_time = 0.0;
    data->player->fps->fps = 0;
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