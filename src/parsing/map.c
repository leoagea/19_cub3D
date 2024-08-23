/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:09:00 by lagea             #+#    #+#             */
/*   Updated: 2024/08/23 19:10:51 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_line(char *line)
{
	while(*line)
	{
		if (*line != '1' && *line != '0' && *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W' && *line != ' ' && *line != '\n')
			return 0;
		line++;
	}
	return 1;
}

static void set_to_NULL(char **arr, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        arr[j] = NULL;
        j++;
    }
}

static void get_max_len_map(t_data *data, int j)
{
    int i;
    int len;
    int max_len;

    max_len = 0;
    data->file->map_height = j;
    i = -1;
    while (data->file->map[++i])
    {
        len = ft_strlen(data->file->map[i]);
        if (len > max_len)
            max_len = len;
    }
    data->file->map_width = max_len;    
}

void get_map(t_data *data, int i)
{
    int j;
   
    data->file->map = malloc(sizeof(char *) * data->file->line - i + 1);
    if(!data->file->map)
        ft_error(ERR_ALLOC, data);
    set_to_NULL(data->file->map, data->file->line - i + 1);
    j = 0;
    while (i < data->file->line)
    {
        if (!check_line(data->file->file[i]))
            ft_error(ERR_MAP_CHAR, data);
        data->file->map[j] = ft_strtrim(data->file->file[i], "\n");
        i++;
        j++;
    }
    data->file->map[j] = NULL;
}
