/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:26:17 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 12:52:39 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	display_others(t_data *data, t_player *player)
{
	enemy_calculation(data, player, data->enemy);
	draw_crosshair(data);
	draw_hp_bar(data);
	create_minimap(data);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		(data)->img->img_ptr, 0, 0);
	mlx_string_put(data->mlx_connection, data->mlx_window, 35, 600, 16777215,
		"Speed :");
	mlx_string_put(data->mlx_connection, data->mlx_window, 90, 600, 16777215,
		ft_itoa(data->player.speed * 100));
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->letters[KEY_H], 25, 675);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
		data->letters[KEY_P], 50, 675);
}

void	raycasting(t_player *player, t_data *data)
{
	int			i;
	uint32_t	color;

	i = 0;
	player->column = 0;
	data->img->img_ptr = mlx_new_image(data->mlx_connection, WIDTH, HEIGHT);
	data->img->img_pixels_ptr = mlx_get_data_addr(data->img->img_ptr,
			&(data->img->bits_per_pixel), &(data->img->size_line),
			&(data->img->endian));
	draw_floor(data, player, &data->floor);
	while (i < WIDTH)
	{
		ray_direction(i, player);
		delta_distance(player);
		init_dda(player);
		dda_algorithm(player, data);
		wall_height(player);
		// draw(data, player);
		wall_texture(data, player, i);
		player->z_buffer[i] = player->perp_wall_dist;
		i++;
	}
	display_others(data, player);
}

void	ray_direction(int i, t_player *player) // Calculation of Ray vector
{
	int	w;

	w = WIDTH;
	player->camera_x = 2.0 * (i / (double)w) - 1.0;
	player->ray_dir_x = player->dir_x + player->plane_x * player->camera_x;
	player->ray_dir_y = player->dir_y + player->plane_y * player->camera_x;
}
