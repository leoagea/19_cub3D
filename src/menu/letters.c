/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:26:16 by lagea             #+#    #+#             */
/*   Updated: 2024/08/30 17:22:41 by lagea            ###   ########.fr       */
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
    i = -1;
    while (++i < 128)
        data->highlight[i] = NULL;
    data->letters[KEY_W] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/W.xpm",&x, &y);
    data->letters[KEY_S] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/S.xpm",&x, &y);
    data->letters[KEY_A] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/A.xpm",&x, &y);
    data->letters[KEY_D] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/D.xpm",&x, &y);
    data->letters[KEY_D] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/D.xpm",&x, &y);
    data->letters[KEY_K] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/K.xpm",&x, &y);

    data->highlight[KEY_W] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/W_high.xpm",&x, &y);
    data->highlight[KEY_S] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/S_high.xpm",&x, &y);
    data->highlight[KEY_A] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/A_high.xpm",&x, &y);
    data->highlight[KEY_D] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/D_high.xpm",&x, &y);
    data->highlight[KEY_K] = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/letters/K_high.xpm",&x, &y);
}