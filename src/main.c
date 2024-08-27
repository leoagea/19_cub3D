/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:14:57 by lagea             #+#    #+#             */
/*   Updated: 2024/08/27 15:48:40 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    t_data data;

    init_data(&data);
    parsing(ac, av, &data);
    create_window(&data);
    get_textures(&data);
    create_menu(&data);
    raycasting(data.player, &data);
    
    // mlx_key_hook(data.mlx_window, &handle_key, &data);
    mlx_hook(data.mlx_window, 17, 0, &cross_event, &data);
    mlx_hook(data.mlx_window, 2, 1L<<0, &key_press, &data);
    mlx_hook(data.mlx_window, 3, 1L<<1, &key_release, &data);
    mlx_loop_hook(data.mlx_connection, &player_movement, &data);
    mlx_loop(data.mlx_connection);
    return 0;
}

//voir bug video