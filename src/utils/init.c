/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:40:53 by lagea             #+#    #+#             */
/*   Updated: 2024/08/27 17:12:11 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_struct_file(t_data *data)
{
    data->file = malloc(sizeof(t_file));
    if (!data->file)
        ft_error(ERR_ALLOC, data);
    data->file->map_width = 0;
    data->file->map_height = 0;
    data->file->flag_no = 0;
    data->file->flag_so = 0;
    data->file->flag_ea = 0;
    data->file->flag_we = 0;
    data->file->flag_c = 0;
    data->file->flag_f = 0;
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
    data->player->minimap = 0;
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

void init_minimap_struct(t_data *data)
{
    data->minimap = malloc(sizeof(t_minimap));
    if (!data->minimap)
        ft_error(ERR_ALLOC, data);
    data->minimap->start_x = 440;
    data->minimap->start_y = (HEIGHT - MINIMAP_SIZE) / 2;
    data->minimap->wall_thick = 0;
    data->minimap->cell_width = MINIMAP_SIZE / data->file->map_width;
    data->minimap->cell_height = MINIMAP_SIZE / data->file->map_height;
}

void init_data(t_data *data)
{
    data->file = NULL;
    data->img = NULL;
    data->minimap = NULL;
    data->mlx_connection = NULL;
    data->mlx_window = NULL;
    data->player = NULL;
    data->menu = 0;
}

void init_xpm(t_data *data)
{
    data->xpm.wall_no = NULL;
    data->xpm.wall_so = NULL;
    data->xpm.wall_ea = NULL;
    data->xpm.wall_we = NULL;
    data->xpm.floor = NULL;
    data->xpm.ceiling = NULL;
    data->xpm.menu = NULL;
    data->xpm.start = NULL;
    data->xpm.start_select = NULL;
    data->xpm.exit = NULL;
    data->xpm.exit_select = NULL;
}