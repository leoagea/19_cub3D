/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:18:59 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:39:48 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	not_firing(t_data *data)
{
	reset_shot(data, data->enemy);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->player.weapon[data->player.anim.current_frame].img_ptr, ((WIDTH
				- data->player.weapon[SIMPLE].width) / 2) + 100, 400);
}

static void	win_screen(t_data *data)
{
	if (!data->menu.victory && !data->menu.check_win)
	{
		ft_putstr_fd("YOU WON !\n", 2);
		data->menu.victory = 1;
	}
}

static void	dispatch_movement(t_data *data)
{
	mlx_mouse_hide(data->mlx_window);
	if (data->player.key_left)
		rotate_left(data);
	if (data->player.key_right)
		rotate_right(data);
	if (data->player.key_forward)
		move_forward(data);
	if (data->player.key_backward)
		move_backward(data);
	if (data->player.key_move_left)
		move_left(data);
	if (data->player.key_move_right)
		move_right(data);
	if (data->player.minimap)
		create_minimap(data);
	if (verif_all_dead(data, data->enemy))
		win_screen(data);
	mouse_rotation(data);
	mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	raycasting(&data->player, data);
	check_near_door(data, &data->player, data->door);
	if (data->player.is_firing == 0)
		not_firing(data);
	else
		render_weapon(data);
}

static int	end_screen(t_data *data)
{
	if (!data->menu.menu && !data->menu.pause && !data->menu.controls
		&& data->menu.dead && !data->menu.playing && !data->menu.victory)
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.dead, 445, 175);
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.escape, 425, 600);
	}
	else if (!data->menu.menu && !data->menu.pause && !data->menu.controls
		&& !data->menu.dead && !data->menu.playing && data->menu.victory)
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.victory, 440, 275);
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.waiting_victory, 375, 500);
		data->menu.playing = 1;
	}
	return (0);
}

int	player_movement(t_data *data)
{
	if (data->menu.menu == 1 && data->menu.pause == 0 && !data->menu.controls
		&& !data->menu.change && !data->menu.dead && !data->menu.playing
		&& !data->menu.victory)
		create_menu(data);
	else if (data->menu.controls && !data->menu.pause && data->menu.menu
		&& !data->menu.change && !data->menu.dead && !data->menu.playing
		&& !data->menu.victory)
		menu_controls(data);
	else if (!data->menu.menu && data->menu.pause && !data->menu.controls
		&& !data->menu.change && !data->menu.dead && !data->menu.playing
		&& !data->menu.victory)
		menu_pause(data);
	else if (!data->menu.menu && data->menu.pause && data->menu.controls
		&& !data->menu.change && !data->menu.dead && !data->menu.playing
		&& !data->menu.victory)
		menu_controls(data);
	else if (data->menu.controls && data->menu.change && (data->menu.menu
			|| data->menu.pause) && !data->menu.dead && !data->menu.playing
		&& !data->menu.victory)
		menu_change_controls(data);
	else if (!data->menu.menu && !data->menu.pause && !data->menu.controls
		&& !data->menu.dead && !data->menu.playing && !data->menu.victory)
		dispatch_movement(data);
	return (end_screen(data), 0);
}
