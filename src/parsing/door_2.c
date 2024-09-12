/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:43:59 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 12:44:36 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_next_door(t_data *data, int i, int j)
{
	if (i - 1 >= 0 && data->file.map[i - 1] && data->file.map[i - 1][j])
		if (data->file.map[i - 1][j] == 'D')
			ft_error(ERR_DOOR_2, data);
	if (i + 1 < data->file.map_height && data->file.map[i + 1]
		&& data->file.map[i + 1][j])
		if (data->file.map[i + 1][j] == 'D')
			ft_error(ERR_DOOR_2, data);
	if (j - 1 >= 0 && data->file.map[i] && data->file.map[i][j - 1])
		if (data->file.map[i][j - 1] == 'D')
			ft_error(ERR_DOOR_2, data);
	if (j + 1 < data->file.map_width && data->file.map[i] && data->file.map[i][j
		+ 1])
		if (data->file.map[i][j + 1] == 'D')
			ft_error(ERR_DOOR_2, data);
}

static void	check_surrounding_hor(t_data *data, int i, int j, int k)
{
	if ((j - 1 >= 0 && data->file.map[i][j - 1]) || (j
			+ 1 < data->file.map_width && data->file.map[i][j + 1]))
	{
		if ((j - 1 >= 0 && data->file.map[i][j - 1] == '1') || (j
				+ 1 < data->file.map_width && data->file.map[i][j + 1] == '1'))
			ft_error(ERR_DOOR_3_WALL, data);
	}
	data->door[k].dir = HORIZONTAL;
	data->door[k].pos_x = (double)j;
	data->door[k].pos_y = (double)i;
}

static void	check_surrounding_ver(t_data *data, int i, int j, int k)
{
	if ((i - 1 >= 0 && data->file.map[i - 1][j]) || (i
			+ 1 < data->file.map_height && data->file.map[i + 1][j]))
	{
		if ((i - 1 >= 0 && data->file.map[i - 1][j] == '1') || (i
				+ 1 < data->file.map_height && data->file.map[i + 1][j] == '1'))
			ft_error(ERR_DOOR_3_WALL, data);
	}
	data->door[k].dir = VERTICAL;
	data->door[k].pos_x = (double)j;
	data->door[k].pos_y = (double)i;
}

void	extract_pos(t_data *data, int i, int j, int k)
{
	check_next_door(data, i, j);
	if (i - 1 >= 0 && i + 1 < data->file.map_height && data->file.map[i - 1]
		&& data->file.map[i + 1])
	{
		if (data->file.map[i - 1][j] == '1' && data->file.map[i + 1][j] == '1')
			check_surrounding_hor(data, i, j, k);
	}
	if (j - 1 >= 0 && j + 1 < data->file.map_width && data->file.map[i][j - 1]
		&& data->file.map[i][j + 1])
	{
		if (data->file.map[i][j - 1] == '1' && data->file.map[i][j + 1] == '1')
			check_surrounding_ver(data, i, j, k);
	}
	else
		ft_error(ERR_DOOR, data);
}
