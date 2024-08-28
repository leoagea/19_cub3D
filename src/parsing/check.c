/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:42:36 by lagea             #+#    #+#             */
/*   Updated: 2024/08/28 13:53:05 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int get_number_token(char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        while(*str && ((*str >= 9 && *str <= 13) || *str == 32))
            str++;
        if(*str == '\0' || *str == '\n')
            break ;
        count ++;
        while (*str && ft_isascii((int)*str) && !((*str >= 9 && *str <= 13) || *str == 32))
            str++;
    }
    return count;
}

static void get_number_color_data(t_data *data, char *color)
{
    int count;

    count = 0;
    while(*color)
    {
        while(*color && !ft_isdigit((int)*color))
            color++;
        if(*color == '\0' || *color == '\n')
            break ;
        count++;
        while(*color && ft_isdigit((int)*color))
            color++;
    }
    if (count != 3)
        ft_error(ERR_TOK_COL, data);
}

static void check_coma(t_data *data, char *color)
{
    if(!ft_isdigit((int)*color))
        ft_error(ERR_TOK_COL, data);
    while(*color)
    {
        while(*color && ft_isdigit((int)*color))
            color++;
        if (*color == ',')
        {
            if (*(color + 1) == '\0')
                ft_error(ERR_TOK_COL, data);
            if (ft_isdigit((int)*(color + 1)))
                color++;
            else
                ft_error(ERR_TOK_COL, data);
        }
    }    
}

void check_color_textures(t_data *data, char *line)
{
    if (get_number_token(line) != 2)
        ft_error(ERR_TOK, data);
}

void check_color(t_data *data)
{
    if (data->file.c_floor)
    {
        get_number_color_data(data, data->file.color_floor);
        check_coma(data, data->file.color_floor);
    }
    if (data->file.c_ceiling)
    {
        get_number_color_data(data, data->file.color_ceiling);
        check_coma(data, data->file.color_ceiling);
    }
}
