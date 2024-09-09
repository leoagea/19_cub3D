/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:38:19 by lagea             #+#    #+#             */
/*   Updated: 2024/09/09 17:20:41 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	load_xpm_wall(t_data *data)
{
	data->texture[NO].img_ptr = mlx_xpm_file_to_image(data->mlx_connection,
			data->file.wall_no, &data->texture[NO].width,
			&data->texture[NO].height);
	data->texture[NO].img_pixels_ptr = mlx_get_data_addr(\
			data->texture[NO].img_ptr, &(data->texture[NO].bits_per_pixel),
			&(data->texture[0].size_line), &(data->texture[NO].endian));
	data->texture[SO].img_ptr = mlx_xpm_file_to_image(\
			data->mlx_connection, data->file.wall_so, \
			&data->texture[SO].width, &data->texture[SO].height);
	data->texture[SO].img_pixels_ptr = mlx_get_data_addr(\
			data->texture[SO].img_ptr, &(data->texture[SO].bits_per_pixel),
			&(data->texture[0].size_line), &(data->texture[SO].endian));
	data->texture[EA].img_ptr = mlx_xpm_file_to_image(\
			data->mlx_connection, data->file.wall_ea, &data->texture[EA].width, \
			&data->texture[EA].height);
	data->texture[EA].img_pixels_ptr = mlx_get_data_addr(\
			data->texture[EA].img_ptr, &(data->texture[EA].bits_per_pixel), \
			&(data->texture[0].size_line), &(data->texture[EA].endian));
	data->texture[WE].img_ptr = mlx_xpm_file_to_image(\
			data->mlx_connection, data->file.wall_we, &data->texture[WE].width, \
			&data->texture[WE].height);
	data->texture[WE].img_pixels_ptr = mlx_get_data_addr(\
			data->texture[WE].img_ptr, &(data->texture[WE].bits_per_pixel), \
			&(data->texture[0].size_line), &(data->texture[WE].endian));
}

void	load_xpm_menu(t_data *data)
{
	int	x;
	int	y;

	data->xpm.menu = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/Menu.xpm", &x, &y);
	data->xpm.start = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/main/Start.xpm", &x, &y);
	data->xpm.start_highlight = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/main/Start_highlight.xpm", &x, &y);
	data->xpm.exit = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/Exit.xpm", &x, &y);
	data->xpm.exit_highlight = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/Exit_highlight.xpm", &x, &y);
	data->xpm._continue = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/pause/Continue.xpm", &x, &y);
	data->xpm._continue_highlight = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/pause/Continue_highlight.xpm", &x, &y);
}

void	load_xpm_controls_menu(t_data *data)
{
	int	x;
	int	y;

	data->xpm.controls = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/pause/Controls.xpm", &x, &y);
	data->xpm.controls_highlight = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/pause/Controls_highlight.xpm", &x, &y);
	data->xpm.cont_moves = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Controls_moves.xpm", &x, &y);
	data->xpm.cont_vision = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Controls_rotate.xpm", &x, &y);
	data->xpm.cont_interations = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Controls_interactions.xpm", &x, &y);
	data->xpm.cont_for = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Forward.xpm", &x, &y);
	data->xpm.cont_back = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Backward.xpm", &x, &y);
	data->xpm.cont_left = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Left.xpm", &x, &y);
}

void	load_xpm_controls_menu_2(t_data *data)
{
	int	x;
	int	y;

	data->xpm.cont_right = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Right.xpm", &x, &y);
	data->xpm.waitng_key_press = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Waiting_key_press.xpm", &x, &y);
	data->xpm._return = (mlx_xpm_file_to_image(data->mlx_connection,
				"./assets/menu/controls/Return.xpm", &x, &y));
	data->xpm._return_highlight = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Return_highlight.xpm", &x, &y);
	data->xpm.speed_up = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Speed_Up.xpm", &x, &y);
	data->xpm.speed_down = mlx_xpm_file_to_image(data->mlx_connection,
			"./assets/menu/controls/Speed_Down.xpm", &x, &y);
}
