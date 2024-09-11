/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:12 by vdarras           #+#    #+#             */
/*   Updated: 2024/09/11 18:38:23 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	load_floor(t_data *data)
{
	data->floor.floor_img.img_ptr = mlx_xpm_file_to_image(data->mlx_connection,
			"assets/floor/floor.xpm", &data->floor.floor_img.width,
			&data->floor.floor_img.height);
	data->floor.floor_img.img_pixels_ptr = mlx_get_data_addr(\
	data->floor.floor_img.img_ptr,
			&(data->floor.floor_img.bits_per_pixel),
			&(data->floor.floor_img.size_line),
			&(data->floor.floor_img.endian));
	if (!data->floor.floor_img.img_ptr)
		ft_error(ERR_XPM_FLOOR, data);
}

void	draw_floor(t_data *data, t_player *player, t_floor *floor)
{
	int	i;

	i = HEIGHT / 2;
	while (i < HEIGHT)
	{
		loop_verticaly(data, player, floor, i);
		i++;
	}
}

void	loop_verticaly(t_data *data, t_player *player, t_floor *floor, int i)
{
	int	j;

	j = 0;
	floor->floor_dir_x0 = player->dir_x - player->plane_x;
	floor->floor_dir_y0 = player->dir_y - player->plane_y;
	floor->floor_dir_x1 = player->dir_x + player->plane_x;
	floor->floor_dir_y1 = player->dir_y + player->plane_y;
	floor->p = i - HEIGHT / 2;
	if (floor->p == 0)
		floor->p = 1;
	floor->pos_z = HEIGHT / 2;
	floor->row_distance = floor->pos_z / floor->p;
	floor->floor_step_x = floor->row_distance * (floor->floor_dir_x1
			- floor->floor_dir_x0) / WIDTH;
	floor->floor_step_y = floor->row_distance * (floor->floor_dir_y1
			- floor->floor_dir_y0) / WIDTH;
	floor->floor_x = player->pos_x + floor->row_distance * floor->floor_dir_x0;
	floor->floor_y = player->pos_y + floor->row_distance * floor->floor_dir_y0;
	while (j < WIDTH)
	{
		loop_horizontaly(data, floor, i, j);
		j++;
	}
}

void	loop_horizontaly(t_data *data, t_floor *floor, int i, int j)
{
	int	pixel;
	int	pixel_index;

	floor->cell_x = (int)floor->floor_x;
	floor->cell_y = (int)floor->floor_y;
	floor->tx = (int)(TEXWIDTH * (floor->floor_x - floor->cell_x)) & (TEXWIDTH
			- 1);
	floor->ty = (int)(TEXHEIGHT * (floor->floor_y - floor->cell_y)) & (TEXHEIGHT
			- 1);
	floor->floor_x += floor->floor_step_x;
	floor->floor_y += floor->floor_step_y;
	pixel_index = (floor->ty * floor->floor_img.size_line) + (floor->tx
			* (floor->floor_img.bits_per_pixel / 8));
	floor->color = *(uint32_t *)(floor->floor_img.img_pixels_ptr + pixel_index);
	floor->color = (floor->color >> 1) & 8355711;
	draw_point(data, j, i, floor->color);
}
