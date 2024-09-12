/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:18:07 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 15:28:58 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static	void	load_xpm_weapon(t_data *data)
{
	data->player.weapon[SIMPLE].img_ptr = mlx_xpm_file_to_image \
			(data->mlx_connection, "assets/weapon/gun1.xpm", \
			&data->player.weapon[SIMPLE].width, \
			&data->player.weapon[SIMPLE].width);
	data->player.weapon[SHOOT].img_ptr = mlx_xpm_file_to_image \
			(data->mlx_connection, "assets/weapon/gun2.xpm", \
			&data->player.weapon[SHOOT].width, \
			&data->player.weapon[SHOOT].width);
	data->player.weapon[RECOIL].img_ptr = mlx_xpm_file_to_image \
			(data->mlx_connection, "assets/weapon/gun3.xpm", \
			&data->player.weapon[RECOIL].width, \
			&data->player.weapon[RECOIL].width);
	data->player.weapon[REPLACE].img_ptr = mlx_xpm_file_to_image \
			(data->mlx_connection, "assets/weapon/gun4.xpm", \
			&data->player.weapon[REPLACE].width, \
			&data->player.weapon[REPLACE].width);
}

void	load_weapon(t_data *data)
{
	int	i;

	load_xpm_weapon(data);
	if (!data->player.weapon[SIMPLE].img_ptr
		|| !data->player.weapon[SHOOT].img_ptr
		|| !data->player.weapon[RECOIL].img_ptr
		|| !data->player.weapon[REPLACE].img_ptr)
		ft_error(ERR_XPM_WEAPON, data);
	i = -1;
	while (++i < 4)
		data->player.weapon[i].img_pixels_ptr = mlx_get_data_addr(
				data->player.weapon[i].img_ptr,
				&data->player.weapon[i].bits_per_pixel,
				&data->player.weapon[i].size_line,
				&data->player.weapon[i].endian);
}
