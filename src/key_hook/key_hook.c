/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:03:30 by vdarras           #+#    #+#             */
/*   Updated: 2024/08/18 18:09:22 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	handle_input(int keysym, t_data *data)
{
	mlx_destroy_image(data->mlx_connection, data->img->img_ptr);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	free(data->mlx_connection);
	free(data->img);
	free(data);
	write(1, "Window has been closed\n", 24);
	exit(1);
}

int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_ESCAPE)
		handle_input(keysym, data);
	return (0);
}
