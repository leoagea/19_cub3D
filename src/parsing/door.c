/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:22:01 by lagea             #+#    #+#             */
/*   Updated: 2024/09/09 14:08:02 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	extract_pos(t_data *data, int i, int j, int k)
{
	if (data->file.map[i - 1][j] == 'D' || data->file.map[i + 1][j] == 'D'
		|| data->file.map[i][j - 1] == 'D' || data->file.map[i][j + 1] == 'D')
		ft_error(ERR_DOOR_2, data);
	if (data->file.map[i - 1] && data->file.map[i + 1] && \
	data->file.map[i - 1][j] == '1' && data->file.map[i + 1][j] == '1')
	{
		if ((data->file.map[i][j - 1] && data->file.map[i][j - 1] == '1')
			|| (data->file.map[i][j + 1] && data->file.map[i][j + 1] == '1'))
			ft_error(ERR_DOOR_3_WALL, data);
		data->door[k].dir = HORIZONTAL;
		data->door[k].pos_x = (double)j;
		data->door[k].pos_y = (double)i;
	}
	else if (data->file.map[i][j - 1] && data->file.map[i][j + 1]
		&& data->file.map[i][j - 1] == '1' && data->file.map[i][j + 1] == '1')
	{
		if ((data->file.map[i - 1][j] && data->file.map[i - 1][j] == '1')
			|| (data->file.map[i + 1][j] && data->file.map[i + 1][j] == '1'))
			ft_error(ERR_DOOR_3_WALL, data);
		data->door[k].dir = VERTICAL;
		data->door[k].pos_x = (double)j;
		data->door[k].pos_y = (double)i;
	}
	else
		ft_error(ERR_DOOR, data);
}

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
}
