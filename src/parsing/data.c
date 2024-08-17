/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:05:23 by lagea             #+#    #+#             */
/*   Updated: 2024/08/18 00:52:29 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static char *get_key(t_data *data, char *line)
{
    int i;
    int start;
    int len;
    char *key;

    i = 0;
    i = skip_whitespace(line, i);
    start = i;
    len = get_len(line, i);
    if (len == 0)
        return NULL;
    key = ft_substr(line, start, len);
    // printf("start : %d, len : %d, key : %s\n", start, len, key);
    check_key(data, key);
    return key;
}

void get_data_line(t_data *data, char *line)
{
    (void) data;
    char *str;
    
    str = get_key(data, line);
    if (!str)
        return ;
    data->file->count++;
    printf("key : %s\n", str);
}
