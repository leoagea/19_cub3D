/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:14:57 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:41:43 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	parsing(ac, av, &data);
	create_window(&data);
	get_textures(&data);
	load_floor(&data);
	init_enemy(&data, data.enemy);
	create_menu(&data);
	if (data.menu.menu == 0)
	{
		mlx_mouse_hide(data.mlx_window);
		mlx_mouse_move(data.mlx_window, WIDTH / 2, HEIGHT / 2);
		raycasting(&data.player, &data);
	}
	mlx_hook(data.mlx_window, 17, 0, &cross_event, &data);
	mlx_hook(data.mlx_window, 2, 1L << 0, &key_press, &data);
	mlx_hook(data.mlx_window, 3, 1L << 1, &key_release, &data);
	mlx_hook(data.mlx_window, 4, 1L << 2, &handle_mouse_menu, &data);
	mlx_loop_hook(data.mlx_connection, &player_movement, &data);
	mlx_loop(data.mlx_connection);
	return (0);
}


//OTHER LETTER THAN IN MAP RESULT TO SEGV