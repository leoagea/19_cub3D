/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:05:23 by lagea             #+#    #+#             */
/*   Updated: 2024/08/21 18:11:36 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	assign_value_2(t_data *data, char *key, char *value)
{
	if (ft_strncmp(key, "F", INT_MAX) == 0 && data->file->flag_f == 0)
	{
		data->file->flag_f = 1;
		data->file->color_floor = value;
	}
	else if (ft_strncmp(key, "C", INT_MAX) == 0 && data->file->flag_c == 0)
	{
		data->file->flag_c = 1;
		data->file->color_ceiling = value;
	}
	else if ((ft_strncmp(key, "NO", INT_MAX) == 0 && data->file->flag_no == 1)
		|| (ft_strncmp(key, "SO", INT_MAX) == 0 && data->file->flag_so == 1)
		|| (ft_strncmp(key, "WE", INT_MAX) == 0 && data->file->flag_we == 1)
		|| (ft_strncmp(key, "EA", INT_MAX) == 0 && data->file->flag_ea == 1)
		|| (ft_strncmp(key, "F", INT_MAX) == 0 && data->file->flag_f == 1)
		|| (ft_strncmp(key, "C", INT_MAX) == 0 && data->file->flag_c == 1))
	{
		free(key);
		ft_error(ERR_DUP, data);
	}
	free(key);
}

static void	assign_value(t_data *data, char *key, char *value)
{
	if (ft_strncmp(key, "NO", INT_MAX) == 0 && data->file->flag_no == 0)
	{
		data->file->flag_no = 1;
		data->file->wall_no = value;
	}
	else if (ft_strncmp(key, "SO", INT_MAX) == 0 && data->file->flag_so == 0)
	{
		data->file->flag_so = 1;
		data->file->wall_so = value;
	}
	else if (ft_strncmp(key, "WE", INT_MAX) == 0 && data->file->flag_we == 0)
	{
		data->file->flag_we = 1;
		data->file->wall_we = value;
	}
	else if (ft_strncmp(key, "EA", INT_MAX) == 0 && data->file->flag_ea == 0)
	{
		data->file->flag_ea = 1;
		data->file->wall_ea = value;
	}
	else
	{
		assign_value_2(data, key, value);
	}
}

static void	get_value(t_data *data, char *line, char *key, int start)
{
	int		len;
	char	*value;

	start = skip_whitespace(line, start);
	len = get_len(line, start);
	if (len == 0)
	{
		free(key);
		ft_error(ERR_VAL, data);
	}
	value = ft_substr(line, start, len);
	if (!value)
	{
		free(key);
		ft_error(ERR_ALLOC, data);
	}
	assign_value(data, key, value);
}

static char	*get_key(t_data *data, char *line)
{
	int		len;
	int		start;
	char	*key;

	start = 0;
	start = skip_whitespace(line, start);
	len = get_len(line, start);
	if (len == 0)
		return (NULL);
	key = ft_substr(line, start, len);
	if (!key)
		ft_error(ERR_ALLOC, data);
	check_key(data, key);
	get_value(data, line, key, start + len);
	return (key);
}

void	get_data_line(t_data *data, char *line)
{
	char	*str;

	str = get_key(data, line);
	if (!str)
		return ;
    check_color_textures(data, line);
	data->file->count++;
}
