/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:11:28 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 13:02:55 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	clear_xpm_menu_2(t_data *data)
{
	if (data->xpm.cont_vision)
		mlx_destroy_image(data->mlx_connection, data->xpm.cont_vision);
	if (data->xpm.cont_interations)
		mlx_destroy_image(data->mlx_connection, data->xpm.cont_interations);
	if (data->xpm.cont_for)
		mlx_destroy_image(data->mlx_connection, data->xpm.cont_for);
	if (data->xpm.cont_back)
		mlx_destroy_image(data->mlx_connection, data->xpm.cont_back);
	if (data->xpm.cont_left)
		mlx_destroy_image(data->mlx_connection, data->xpm.cont_left);
	if (data->xpm.cont_right)
		mlx_destroy_image(data->mlx_connection, data->xpm.cont_right);
	if (data->xpm.waitng_key_press)
		mlx_destroy_image(data->mlx_connection, data->xpm.waitng_key_press);
	if (data->xpm._return)
		mlx_destroy_image(data->mlx_connection, data->xpm._return);
	if (data->xpm._return_highlight)
		mlx_destroy_image(data->mlx_connection, data->xpm._return_highlight);
	if (data->xpm.speed_up)
		mlx_destroy_image(data->mlx_connection, data->xpm.speed_up);
	if (data->xpm.speed_down)
		mlx_destroy_image(data->mlx_connection, data->xpm.speed_down);
}

void	clear_xpm_menu(t_data *data)
{
	if (data->xpm.menu)
		mlx_destroy_image(data->mlx_connection, data->xpm.menu);
	if (data->xpm.start)
		mlx_destroy_image(data->mlx_connection, data->xpm.start);
	if (data->xpm.start_highlight)
		mlx_destroy_image(data->mlx_connection, data->xpm.start_highlight);
	if (data->xpm.exit)
		mlx_destroy_image(data->mlx_connection, data->xpm.exit);
	if (data->xpm.exit_highlight)
		mlx_destroy_image(data->mlx_connection, data->xpm.exit_highlight);
	if (data->xpm._continue)
		mlx_destroy_image(data->mlx_connection, data->xpm._continue);
	if (data->xpm._continue_highlight)
		mlx_destroy_image(data->mlx_connection, data->xpm._continue_highlight);
	if (data->xpm.controls)
		mlx_destroy_image(data->mlx_connection, data->xpm.controls);
	if (data->xpm.controls_highlight)
		mlx_destroy_image(data->mlx_connection, data->xpm.controls_highlight);
	if (data->xpm.cont_moves)
		mlx_destroy_image(data->mlx_connection, data->xpm.cont_moves);
}

void	clear_xpm_letters(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 128)
	{
		if (data->letters[i])
			mlx_destroy_image(data->mlx_connection, data->letters[i]);
		if (data->highlight[i])
			mlx_destroy_image(data->mlx_connection, data->highlight[i]);
	}
}

void	clear_xpm_texture(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!data->texture[i].img_ptr)
			mlx_destroy_image(data->mlx_connection, data->texture[i].img_ptr);
}

void	clear_xpm_enemy(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->nb_enemy)
	{
		i = -1;
		while (++i < 6)
			if (!data->enemy[j].img_frames[i].img_ptr)
				mlx_destroy_image(data->mlx_connection,
					data->enemy[j].img_frames[i].img_ptr);
	}
}
