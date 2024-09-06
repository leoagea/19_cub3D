/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:42:06 by lagea             #+#    #+#             */
/*   Updated: 2024/09/06 17:42:42 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_value(t_data *data, char *key)
{
	if ((ft_strncmp(key, "NO", INT_MAX) == 0 && data->file.flag_no == 1)
		|| (ft_strncmp(key, "SO", INT_MAX) == 0 && data->file.flag_so == 1)
		|| (ft_strncmp(key, "WE", INT_MAX) == 0 && data->file.flag_we == 1)
		|| (ft_strncmp(key, "EA", INT_MAX) == 0 && data->file.flag_ea == 1)
		|| (ft_strncmp(key, "F", INT_MAX) == 0 && data->file.flag_f == 1)
		|| (ft_strncmp(key, "C", INT_MAX) == 0 && data->file.flag_c == 1))
	{
		free(key);
		return (0);
	}
	return (1);
}

static void	assign_value_2(t_data *data, char *key, char *value)
{
	if (ft_strncmp(key, "NO", INT_MAX) == 0)
		data->file.wall_no = value;
	else if (ft_strncmp(key, "SO", INT_MAX) == 0)
		data->file.wall_so = value;
	else if (ft_strncmp(key, "WE", INT_MAX) == 0)
		data->file.wall_we = value;
	else if (ft_strncmp(key, "EA", INT_MAX) == 0)
		data->file.wall_ea = value;
	else if (ft_strncmp(key, "F", INT_MAX) == 0)
		data->file.color_floor = value;
	else if (ft_strncmp(key, "C", INT_MAX) == 0)
		data->file.color_ceiling = value;
	if (ft_strncmp(key, "F", INT_MAX) == 0 && data->file.flag_f == 0)
	{
		data->file.flag_f = 1;
		data->file.color_floor = value;
	}
	else if (ft_strncmp(key, "C", INT_MAX) == 0 && data->file.flag_c == 0)
	{
		data->file.flag_c = 1;
		data->file.color_ceiling = value;
	}
	else if (!check_value(data, key))
		ft_error(ERR_DUP, data);
	free(key);
}

void	assign_value(t_data *data, char *key, char *value)
{
	if (ft_strncmp(key, "NO", INT_MAX) == 0 && data->file.flag_no == 0)
	{
		data->file.flag_no = 1;
		data->file.wall_no = value;
	}
	else if (ft_strncmp(key, "SO", INT_MAX) == 0 && data->file.flag_so == 0)
	{
		data->file.flag_so = 1;
		data->file.wall_so = value;
	}
	else if (ft_strncmp(key, "WE", INT_MAX) == 0 && data->file.flag_we == 0)
	{
		data->file.flag_we = 1;
		data->file.wall_we = value;
	}
	else if (ft_strncmp(key, "EA", INT_MAX) == 0 && data->file.flag_ea == 0)
	{
		data->file.flag_ea = 1;
		data->file.wall_ea = value;
	}
	else
	{
		assign_value_2(data, key, value);
	}
}
