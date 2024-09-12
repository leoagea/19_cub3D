/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:45:20 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 12:09:29 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_wall(t_data *data, int x, int y)
{
	if (x < 0 || y < 0
		|| y >= data->file.map_height || x >= data->file.map_width)
		return (0);
	if (data->file.map[y][x] && data->file.map[y][x] == '1')
		return (0);
	return (1);
}

int	is_in_map(t_data *data, int x, int y)
{
	if (y < 0 || x < 0)
		return (0);
	if (x > data->file.map_width - 1 || y > data->file.map_height - 1)
		return (0);
	return (1);
}
