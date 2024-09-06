/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:16:53 by lagea             #+#    #+#             */
/*   Updated: 2024/09/06 14:02:13 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static char *set_exter_border(char *map)
{
    int j;
    char *cpy;
    
    cpy = malloc(sizeof(char) * (ft_strlen(map) + 3));
    j = 0;
    cpy[0] = -1;
    while(map[j])
    {
        cpy[j + 1] = map[j];
        j++;
    }
    cpy[ft_strlen(map) + 1] = -1;
    cpy[ft_strlen(map) + 2] = '\0';
    return cpy;
}

static char **replace_char(char **cpy)
{
    int i;
    int j;
    char c;
    
    i = 0;
    while (cpy[i])
    {
        j = 0;
        while (cpy[i][j])
        {
            c = cpy[i][j];
            if (c != -1 && c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != 'X' && c != 'D')
                cpy[i][j] = -1;
            j++;
        }
        i++;
    }
    return cpy;
}

static void backtrack(t_data *data, char **map, int i, int j)
{   
    if (map[i][j])
    {
        if (map[i][j] == '1' || map[i][j] == 'V' || map[i][j] == 'X')
            return ;
        else if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
            map[i][j] = 'V';
        else if (map[i][j] == -1)
            ft_error(ERR_MAP, data);
        backtrack(data, map, i + 1, j);
        backtrack(data, map, i - 1, j);
        backtrack(data, map, i, j + 1);
        backtrack(data, map, i, j - 1);
    }
}
static char **cpy_map(char **map)
{
    int i;
    int len;
    char **cpy;

    len = get_len_array(map);
    cpy = malloc(sizeof(char *) * (len + 3));
    i = 1;
    cpy[0] = malloc(sizeof(char) * (ft_strlen(map[0]) + 3));
    ft_memset(cpy[0], -1, ft_strlen(map[0]) + 2);
    cpy[0][ft_strlen(map[0]) + 2] = '\0';
    while (i < len + 1)
    {
        cpy[i] = set_exter_border(map[i - 1]);
        i++;
    }
    cpy[len + 1] = malloc(sizeof(char) * (ft_strlen(map[len - 1]) + 3));
    ft_memset(cpy[len + 1], -1, ft_strlen(map[len - 1]) + 2);
    cpy[len + 1][ft_strlen(map[len - 1]) + 2] = '\0';
    cpy[len + 2] = NULL;
    return cpy;
}

void checking_map(t_data *data)
{
    data->file.cpy = cpy_map(data->file.map);
    data->file.cpy = replace_char(data->file.cpy);
    backtrack(data, data->file.cpy, data->player.pos_y + 1, data->player.pos_x + 1);
}
