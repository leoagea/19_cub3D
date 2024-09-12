/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:30 by vdarras           #+#    #+#             */
/*   Updated: 2024/09/12 12:39:58 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	cross_event(t_data *data)
{
	clear_data(data);
	if (data->img->img_ptr)
		mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
	if (data->mlx_connection)
		free(data->mlx_connection);
	if (data->img)
		free(data->img);
	write(1, "Window has been closed\n", 24);
	exit(1);
	return (0);
}

void	handle_input(int keysym, t_data *data)
{
	(void) keysym;
	if (data->img)
	{
		if (data->img->img_ptr)
			mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	}
	if (data->mlx_window)
	{
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		write(1, "Window has been closed\n", 24);
	}
	if (data->mlx_connection)
		free(data->mlx_connection);
	if (data->img)
		free(data->img);
	exit(1);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == data->key.r_left)
		data->player.key_left = 0;
	if (keysym == data->key.r_right)
		data->player.key_right = 0;
	if (keysym == data->key.m_forward)
		data->player.key_forward = 0;
	if (keysym == data->key.m_backward)
		data->player.key_backward = 0;
	if (keysym == data->key.m_left)
		data->player.key_move_left = 0;
	if (keysym == data->key.m_right)
		data->player.key_move_right = 0;
	return (0);
}
