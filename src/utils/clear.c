/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:17:55 by lagea             #+#    #+#             */
/*   Updated: 2024/08/19 16:22:58 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void clear_arr(char **arr)
{
    int i;
    int len;

    i = 0;
    if (!arr)
        return ;
    len = get_len_array(arr);
    while (i < len)
    {
        if(arr[i])
            free(arr[i]);
        i++;
    }
    free(arr);
}

void clear_file(t_data *data)
{
    int i;
   
    i = 0;
    if (data->file->file)
    {
        while (i < data->file->line + 1 && data->file->file[i])
        {
            if (data->file->file[i])
                free(data->file->file[i]);
            i++;
        }
        free(data->file->file);   
    }
}

void clear_color_struct(t_color *color)
{
    if (color->r)
        free(color->r);
    if (color->g)
        free(color->g);
    if (color->b)
        free(color->b);
    free(color);
}

void clear_struct_file(t_data *data)
{
    t_file *file;

    if (!data->file)
        return ;
    file = data->file;
    if (file->wall_no)
        free(file->wall_no);
    if (file->wall_so)
        free(file->wall_so);
    if (file->wall_we)
        free(file->wall_we);
    if (file->wall_ea)
        free(file->wall_ea);
    if (file->color_floor)
        free(file->color_floor);
    if (file->color_ceiling)
        free(file->color_ceiling);
    clear_color_struct(data->file->c_floor);
    clear_color_struct(data->file->c_ceiling);
    clear_file(data);
    clear_arr(data->file->map);
    free(data->file);
}

void clear_player_struct(t_data *data)
{
    if (!data->player)
        return ;
    free(data->player);
}
