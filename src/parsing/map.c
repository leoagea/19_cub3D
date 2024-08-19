/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:16:53 by lagea             #+#    #+#             */
/*   Updated: 2024/08/19 19:22:39 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void cpy_map(char **map)
{
    int i;
    int len;
    char **cpy;

    i = 0;
    printf("test\n");
    len = get_len_array(map);
    printf("test 1\n");
    cpy = malloc(sizeof(char *) * len + 1);
    printf("test 2\n");
    while (map[i])
    {
        if (map[i])
            ft_memcpy(cpy[i], map[i], ft_strlen(map[i]));
        // cpy[i] = ft_strdup(map[i]);
        i++;
    }
    cpy[i] = NULL;
    // i = 0;
    // while (cpy[i])
    // {
    //     printf("cpy [%d] : %s\n", i, cpy[i]);
    //     i++;
    // }
}
