/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:14:57 by lagea             #+#    #+#             */
/*   Updated: 2024/08/20 19:58:43 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    t_data data;
    parsing(ac, av, &data);
    create_window(&data);
    raycasting(data.player, &data);

    
    mlx_hook(data.mlx_window, 17, 0, &cross_event, &data);
    mlx_key_hook(data.mlx_window, &handle_key, &data);
    mlx_loop(data.mlx_connection);
    return 0;
}