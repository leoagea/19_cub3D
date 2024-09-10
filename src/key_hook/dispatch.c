/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:18:59 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 13:46:21 by lagea            ###   ########.fr       */
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
	ft_putstr_fd("YOU WON !\n", 2);
	ft_error(NULL, data);
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
	if (data->player.is_firing == 0)
		not_firing(data);
	else
		render_weapon(data);
}

int	player_movement(t_data *data)
{
	if (data->menu.menu == 1 && data->menu.pause == 0 && !data->menu.controls
		&& !data->menu.change)
		create_menu(data);
	else if (data->menu.controls && !data->menu.pause && data->menu.menu
		&& !data->menu.change)
		menu_controls(data);
	else if (!data->menu.menu && data->menu.pause && !data->menu.controls
		&& !data->menu.change)
		menu_pause(data);
	else if (!data->menu.menu && data->menu.pause && data->menu.controls
		&& !data->menu.change)
		menu_controls(data);
	else if (data->menu.controls && data->menu.change && (data->menu.menu
			|| data->menu.pause))
		menu_change_controls(data);
	else if (!data->menu.menu && !data->menu.pause && !data->menu.controls)
		dispatch_movement(data);
	return (0);
}
