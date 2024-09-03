/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:09:00 by lagea             #+#    #+#             */
/*   Updated: 2024/09/03 13:23:38 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_line(t_data *data, char *line)
{
	while(*line)
	{
        if (*line == 'X')
            data->nb_ennemy++;
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

static void get_ennemy_pos(t_data *data)
{
    int i;
    int j;
    int k;
    
    k = data->nb_ennemy;
    if (k == 0)
        return ;
    i = -1;
    data->ennemy = malloc(sizeof(t_ennemy) * data->nb_ennemy);
    if(!data->ennemy)
        ft_error(ERR_ALLOC, data);
    while(data->file.map[++i])
    {
       j = 0;
       while (data->file.map[i][j])
       {
            if(data->file.map[i][j] == 'X')
            {
                k--;
                data->ennemy[k].pos_x = (double)j;
                data->ennemy[k].pos_y = (double)i;
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
    get_ennemy_pos(data);
    get_door_pos(data);
    int k = 0;
    printf("nb_door : %d\n", data->nb_door);
    while(k < data->nb_door)
    {
        printf("data.door[%d].pos_x : %f\ndata.door[%d].pos_y : %f\n\n", k, data->door[k].pos_x, k, data->door[k].pos_y);
        k++;
    }
}
