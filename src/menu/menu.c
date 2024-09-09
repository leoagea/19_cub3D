/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:18:50 by lagea             #+#    #+#             */
/*   Updated: 2024/09/09 18:16:35 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	menu_pause(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_show(data->mlx_window);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm.menu, 0, 0);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm._continue, 445, 150);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm.controls, 465, 312);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm.exit, 550, 500);
	mlx_mouse_get_pos(data->mlx_window, &x, &y);
	if ((x > 375 && x < 900) && (y > 140 && y < 230))
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm._continue_highlight, 445, 150);
	else if ((x > 450 && x < 830) && (y > 300 && y < 400))
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.controls_highlight, 465, 312);
	else if ((x > 540 && x < 730) && (y > 490 && y < 580))
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.exit_highlight, 550, 500);
	return (0);
}

int	create_menu(t_data *data)
{
	int	x;
	int	y;

	init_letters(data);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm.menu, 0, 0);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm.start, 395, 150);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm.controls, 465, 312);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->xpm.exit, 555, 500);
	mlx_mouse_get_pos(data->mlx_window, &x, &y);
	if ((x > 375 && x < 900) && (y > 140 && y < 230))
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.start_highlight, 395, 150);
	else if ((x > 450 && x < 830) && (y > 300 && y < 400))
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.controls_highlight, 465, 312);
	else if ((x > 540 && x < 730) && (y > 490 && y < 580))
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
			data->xpm.exit_highlight, 555, 500);
	return (0);
}
