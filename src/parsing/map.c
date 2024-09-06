/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:09:00 by lagea             #+#    #+#             */
/*   Updated: 2024/09/06 14:02:50 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_line(t_data *data, char *line)
{
	while(*line)
	{
        if (*line == 'X')
            data->nb_enemy++;
        if (*line == 'D')
            data->nb_door++;
		if (*line != '1' && *line != '0' && *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W' && *line != ' ' && *line != '\n' && *line!= 'X' && *line != 'D')
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
    data->file.map_height = j;
    i = -1;
    while (data->file.map[++i])
    {
        len = ft_strlen(data->file.map[i]);
        if (len > max_len)
            max_len = len;
    }
    data->file.map_width = max_len;    
}

static void get_enemy_pos(t_data *data)
{
    int i;
    int j;
    int k;
    
    k = data->nb_enemy;
    if (k == 0)
        return ;
    i = -1;
    data->enemy = malloc(sizeof(t_enemy) * data->nb_enemy);
    if(!data->enemy)
        ft_error(ERR_ALLOC, data);
    while(data->file.map[++i])
    {
       j = 0;
       while (data->file.map[i][j])
       {
            if(data->file.map[i][j] == 'X')
            {
                k--;
                data->enemy[k].pos_x = (double)j + 0.5;
                data->enemy[k].pos_y = (double)i + 0.5;
            }
            j++;
       }
    }
}

void get_map(t_data *data, int i)
{
    int j;
   
    data->file.map = malloc(sizeof(char *) * data->file.line - i + 1);
    if(!data->file.map)
        ft_error(ERR_ALLOC, data);
    set_to_NULL(data->file.map, data->file.line - i + 1);
    j = 0;
    while (i < data->file.line)
    {
        if (!check_line(data, data->file.file[i]))
            ft_error(ERR_MAP_CHAR, data);
        data->file.map[j] = ft_strtrim(data->file.file[i], "\n");
        i++;
        j++;
    }
    data->file.map[j] = NULL;
    get_max_len_map(data, j);
    get_enemy_pos(data);
    get_door_pos(data);
}
