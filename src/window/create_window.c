/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:02:17 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 11:03:53 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	create_window(t_data *data)
{
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		ft_error(ERR_ALLOC, data);
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		ft_error(ERR_ALLOC, data);
	data->mlx_window = mlx_new_window(data->mlx_connection, WIDTH, HEIGHT,
			"Cub3D");
	if (!data->mlx_window)
		error_window(data);
	data->img->img_ptr = mlx_new_image((data)->mlx_connection, WIDTH, HEIGHT);
	data->img->img_pixels_ptr = mlx_get_data_addr((data)->img->img_ptr,
			&((data)->img->bits_per_pixel), &((data)->img->size_line),
			&((data)->img->endian));
}

void	error_window(t_data *data)
{
	free(data->mlx_connection);
	free(data->img);
	free(data);
	write(2, "Error while creating new window\n", 33);
	mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	exit(1);
}
