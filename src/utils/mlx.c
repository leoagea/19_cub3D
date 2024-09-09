/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:18:38 by lagea             #+#    #+#             */
/*   Updated: 2024/09/09 18:21:01 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void img_to_win(t_data *data, void *img, int x, int y)
{
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, img, x, y);
}