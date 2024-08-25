/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:30 by vdarras           #+#    #+#             */
/*   Updated: 2024/08/22 18:09:32 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	cross_event(t_data *data)
{
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	free(data->img);
	write(1, "Window has been closed\n", 24);
	exit(1);
	return (0);
}

void	handle_input(int keysym, t_data *data)
{
	(void) keysym;
	// mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	free(data->img);
	write(1, "Window has been closed\n", 24);
	exit(1);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == KEY_LEFT)
		data->player->key_left = 1;
	if (keysym == KEY_RIGHT)
		data->player->key_right = 1;
	if (keysym == KEY_W)
		data->player->key_forward = 1;
	if (keysym == KEY_S)
		data->player->key_backward = 1;
	if (keysym == KEY_A)
		data->player->key_move_left = 1;
	if (keysym == KEY_D)
		data->player->key_move_right = 1;
	if (keysym == KEY_ESC)
		handle_input(keysym, data);
	return (0);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == KEY_LEFT)
		data->player->key_left = 0;
	if (keysym == KEY_RIGHT)
		data->player->key_right = 0;
	if (keysym == KEY_W)
		data->player->key_forward = 0;
	if (keysym == KEY_S)
		data->player->key_backward = 0;
	if (keysym == KEY_A)
		data->player->key_move_left = 0;
	if (keysym == KEY_D)
		data->player->key_move_right = 0;
	return (0);
}