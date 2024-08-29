/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:26:16 by lagea             #+#    #+#             */
/*   Updated: 2024/08/29 18:18:06 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_letters(t_data *data)
{
    int x;
    int y;
    int i = -1;
    
    while (++i < 128)
        data->letters[i] = NULL;
    data->letters[KEY_W] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/W.xpm",&x, &y);
}