/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:01:08 by lagea             #+#    #+#             */
/*   Updated: 2024/08/18 21:57:21 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    error_color(t_data *data, char *r, char *g, char *b)
{
    if(r)
        free(r);
    if(g)
        free(g);
    if(b)
        free(b);
    ft_error(ERR_COL, data);
}

static int get_color_char(char *color, int i)
{
    while(ft_isdigit((int) color[i]) && color[i])
        i++;
    return (i);
}
void isolate_color_param(t_data *data, char *color)
{
    int i;
    int start;
    char *r = NULL;
    char *g = NULL;
    char *b = NULL;
    
    i = 0;
    start = i;
    i = get_color_char(color, i);
    if (start == i)
        error_color(data, r, g, b);
    r = ft_substr(color, start, i);
    start = ++i;
    i = get_color_char(color, i);
    if (start == i)
        error_color(data, r, g, b);
    g = ft_substr(color, start, i - start);
    start = ++i;
    i = get_color_char(color, i);
    b = ft_substr(color, start, i - start);
    if (start == i)
        error_color(data, r, g, b);
    printf("r : '%s', g : '%s', b : '%s'\n", r, g, b);
}

void get_color(t_data *data)
{
    isolate_color_param(data, data->file->color_floor);
    isolate_color_param(data, data->file->color_ceiling);
}