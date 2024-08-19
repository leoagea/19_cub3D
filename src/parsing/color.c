/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:01:08 by lagea             #+#    #+#             */
/*   Updated: 2024/08/18 22:38:19 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int get_color_char(char *color, int i)
{
    while(ft_isdigit((int) color[i]) && color[i])
        i++;
    return (i);
}

void assign_color(t_data *data, t_color *color)
{
    int r;
    int g;
    int b;

    r = ft_atoi(color->r);
    g = ft_atoi(color->g);
    b = ft_atoi(color->b);
    if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
        error_color(data, color->r, color->g, color->b);
    color->color = (r << 16) | (g << 8) | b;
}

t_color *isolate_color_param(t_data *data, char *color)
{
    int i;
    int start;
    t_color *_color;
    
    _color = malloc(sizeof(t_color));
    if (!_color)
        ft_error(ERR_ALLOC, data);
    i = 0;
    start = i;
    i = get_color_char(color, i);
    if (start == i)
        error_color(data, _color->r, _color->g, _color->b);
    _color->r = ft_substr(color, start, i);
    start = ++i;
    i = get_color_char(color, i);
    if (start == i)
        error_color(data, _color->r, _color->g, _color->b);
    _color->g = ft_substr(color, start, i - start);
    start = ++i;
    i = get_color_char(color, i);
    if (start == i)
        error_color(data, _color->r, _color->g, _color->b);
    _color->b = ft_substr(color, start, i - start);
    // printf("r : '%s', g : '%s', b : '%s'\n", _color->r, _color->g, _color->b);
    assign_color(data, _color);
    return _color;
}

void get_color(t_data *data)
{
    t_color *color;
    
    color = isolate_color_param(data, data->file->color_floor);
    data->file->c_floor = color;
    color = isolate_color_param(data, data->file->color_ceiling);
    data->file->c_ceiling = color;
}