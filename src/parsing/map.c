/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:16:53 by lagea             #+#    #+#             */
/*   Updated: 2024/08/20 13:36:14 by lagea            ###   ########.fr       */
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

static void cpy_map(char **map)
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
    i = 0;
    while (cpy[i])
    {
        printf("cpy[%d] : %s\n", i, cpy[i]);
        i++;
    }
}

void checking_map(t_data *data)
{
    cpy_map(data->file->map);    
}
