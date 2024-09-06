/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:05:23 by lagea             #+#    #+#             */
/*   Updated: 2024/09/06 17:42:28 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	data->file.count++;
}
