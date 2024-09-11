/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:18:38 by lagea             #+#    #+#             */
/*   Updated: 2024/09/10 15:16:14 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	img_to_win(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, img, x, y);
}

void	letters_to_img(t_data *data, int key, char *img)
{
	int	x;
	int	y;

	data->letters[key] = mlx_xpm_file_to_image(data->mlx_connection, img, &x,
			&y);
}

void	highlight_to_img(t_data *data, int key, char *img)
{
	int	x;
	int	y;

	data->highlight[key] = mlx_xpm_file_to_image(data->mlx_connection, img, &x,
			&y);
}
