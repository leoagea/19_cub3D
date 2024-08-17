/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:11:38 by lagea             #+#    #+#             */
/*   Updated: 2024/08/18 00:51:07 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int skip_whitespace(char *str, int i)
{
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    return (i); 
}

int get_len(char *str, int i)
{
    int j;

    j = 0;
    while (str[i] && (!(str[i] >= 9 && str[i] <= 13) && str[i] != 32))
    {
        j++;
        i++;
    }
    return (j); 
}

void check_key(t_data *data, char *key)
{
    if(ft_strncmp(key, "NO", INT_MAX) != 0 && ft_strncmp(key, "SO", INT_MAX) != 0 && ft_strncmp(key, "WE", INT_MAX) != 0 && ft_strncmp(key, "EA", INT_MAX) != 0 && ft_strncmp(key, "F", INT_MAX) != 0 && ft_strncmp(key, "C", INT_MAX) != 0)
    {
        free(key);
        ft_error(ERR_ID, data);
    }
}