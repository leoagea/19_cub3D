/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:11:28 by lagea             #+#    #+#             */
/*   Updated: 2024/09/02 16:16:44 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void clear_xpm(t_data *data)
{
   int i = -1;

   while (++i < 128)
   {
        if(data->letters[i])
            mlx_destroy_image(data->mlx_connection, data->letters[i]);
        if(data->highlight[i])
            mlx_destroy_image(data->mlx_connection, data->highlight[i]);
   }
   
}
