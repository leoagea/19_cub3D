/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:44:18 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 17:46:44 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_load_xpm(t_data *data)
{
	if (!data->texture[NO].img_ptr || !data->texture[SO].img_ptr
		|| !data->texture[EA].img_ptr || !data->texture[WE].img_ptr)
		ft_error(ERR_XPM, data);
	if (!data->xpm.dead || !data->xpm.escape || !data->xpm.menu 
		|| !data->xpm.start || !data->xpm.start_highlight
		|| !data->xpm.exit || !data->xpm.exit_highlight || !data->xpm._continue
		|| !data->xpm._continue_highlight || !data->xpm.controls
		|| !data->xpm.controls_highlight || !data->xpm.cont_moves
		|| !data->xpm.cont_vision || !data->xpm.cont_interations
		|| !data->xpm.cont_for || !data->xpm.cont_back || !data->xpm.cont_left
		|| !data->xpm.cont_right || !data->xpm.waitng_key_press
		|| !data->xpm._return || !data->xpm._return_highlight
		|| !data->xpm.speed_up || !data->xpm.speed_down)
		ft_error(ERR_XPM_MENU, data);
}

static int	check_xpm(t_data *data)
{
	int	fd;

	fd = open(data->file.wall_no, O_RDONLY);
	if (fd == -1)
		return (ft_error(strerror(errno), data), 1);
	close(fd);
	fd = open(data->file.wall_so, O_RDONLY);
	if (fd == -1)
		return (ft_error(strerror(errno), data), 1);
	close(fd);
	fd = open(data->file.wall_ea, O_RDONLY);
	if (fd == -1)
		return (ft_error(strerror(errno), data), 1);
	close(fd);
	fd = open(data->file.wall_we, O_RDONLY);
	if (fd == -1)
		return (ft_error(strerror(errno), data), 1);
	close(fd);
	return (0);
}

void	get_textures(t_data *data)
{
	check_xpm(data);
	load_weapon(data);
	load_xpm_wall(data);
	load_xpm_menu(data);
	load_xpm_controls_menu(data);
	load_xpm_controls_menu_2(data);
	check_load_xpm(data);
	if (!data->file.c_floor)
		get_texture_floor(data, data->file.color_floor);
	if (!data->file.c_ceiling)
		get_texture_floor(data, data->file.color_ceiling);
}
