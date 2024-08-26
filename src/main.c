/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:14:57 by lagea             #+#    #+#             */
/*   Updated: 2024/08/26 16:49:22 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    t_data data;

    parsing(ac, av, &data);
    create_window(&data);
    mlx_mouse_hide(data.mlx_window);
    mlx_mouse_move(data.mlx_window, WIDTH / 2, HEIGHT / 2);
    get_textures(&data);
    raycasting(data.player, &data);
    
    mlx_hook(data.mlx_window, 17, 0, &cross_event, &data);
    mlx_hook(data.mlx_window, 2, 1L<<0, &key_press, &data);
    mlx_hook(data.mlx_window, 3, 1L<<1, &key_release, &data);
    mlx_loop_hook(data.mlx_connection, &player_movement, &data);
    mlx_loop(data.mlx_connection);
    return 0;
}