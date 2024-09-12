/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:22:01 by lagea             #+#    #+#             */
/*   Updated: 2024/09/12 12:44:28 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_door_pos(t_data *data)
{
	int	i;
	int	j;
	int	k;

	if (data->nb_door == 0)
		return ;
	data->door = malloc(sizeof(t_door) * data->nb_door);
	if (!data->door)
		ft_error(ERR_ALLOC, data);
	k = data->nb_door;
	i = -1;
	while (data->file.map[++i])
	{
		j = -1;
		while (data->file.map[i][++j])
		{
			if (data->file.map[i][j] == 'D')
			{
				k--;
				extract_pos(data, i, j, k);
			}
		}
	}
	init_doors(data);
}

void	init_doors(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (data->file.map[y])
	{
		x = 0;
		while (data->file.map[y][x])
		{
			if (data->file.map[y][x] == 'D')
			{
				data->door[i].x = x;
				data->door[i].y = y;
				data->door[i].is_open = 0;
				i++;
			}
			x++;
		}
		y++;
	}
}
