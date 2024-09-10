/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:44:43 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 13:45:12 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	rotate_mouse(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = ((data->player.dir_x * cos(angle))
			- (data->player.dir_y * sin(angle)));
	data->player.dir_y = ((old_dir_x * sin(angle)) + (data->player.dir_y
				* cos(angle)));
	data->player.plane_x = ((data->player.plane_x * cos(angle))
			- (data->player.plane_y * sin(angle)));
	data->player.plane_y = ((old_plane_x * sin(angle)) + (data->player.plane_y
				* cos(angle)));
}

void	mouse_rotation(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx_window, &x, &y);
	if (x - WIDTH / 2 != 0)
	{
		rotate_mouse(data, ((double)x - (double)WIDTH / 2) * SENSI);
		mlx_mouse_move(data->mlx_window, WIDTH / 2, HEIGHT / 2);
	}
	if (y - HEIGHT / 2 != 0)
		mlx_mouse_move(data->mlx_window, WIDTH / 2, HEIGHT / 2);
}
