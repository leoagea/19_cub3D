/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:11:28 by lagea             #+#    #+#             */
/*   Updated: 2024/08/28 13:07:14 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void clear_xpm(t_data *data)
{
    if (data->texture[NO].img_ptr)
        mlx_destroy_image(data->mlx_connection, data->texture[NO].img_ptr);
    // if (data->xpm.wall_so)
    //     mlx_destroy_image(data->mlx_connection, data->xpm.wall_so);
    // if (data->xpm.wall_ea)
    //     mlx_destroy_image(data->mlx_connection, data->xpm.wall_ea);
    // if (data->xpm.wall_we)
    //     mlx_destroy_image(data->mlx_connection, data->xpm.wall_we);
}