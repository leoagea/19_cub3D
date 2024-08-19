/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:40:53 by lagea             #+#    #+#             */
/*   Updated: 2024/08/19 17:18:11 by vdarras          ###   ########.fr       */
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
    data->file->file = NULL;
    data->file->wall_no = NULL;
    data->file->wall_so = NULL;
    data->file->wall_we = NULL;
    data->file->wall_ea = NULL;
    data->file->color_floor = NULL;
    data->file->color_ceiling = NULL;
}
