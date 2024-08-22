/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:11:28 by lagea             #+#    #+#             */
/*   Updated: 2024/08/22 13:34:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void clear_xpm(t_data *data)
{
    if (data->xpm.wall_no)
        mlx_destroy_image(data->mlx_connection, data->xpm.wall_no);
    if (data->xpm.wall_so)
        mlx_destroy_image(data->mlx_connection, data->xpm.wall_so);
    if (data->xpm.wall_ea)
        mlx_destroy_image(data->mlx_connection, data->xpm.wall_ea);
    if (data->xpm.wall_we)
        mlx_destroy_image(data->mlx_connection, data->xpm.wall_we);
}

void clear_minimap_struct(t_data *data)
{
    if (data->minimap)
        free(data->minimap);
}