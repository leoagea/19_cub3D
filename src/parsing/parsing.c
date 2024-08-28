/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:20:15 by lagea             #+#    #+#             */
/*   Updated: 2024/08/28 13:37:35 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int    get_data(t_data *data)
{
    int i;
    i = 0;
    
    while (i < data->file.line)
    {
        if (data->file.count == 6)
            return i;
        get_data_line(data, data->file.file[i]);
        i++;
    }
    return i;
}

static int skip_null_line(t_data *data, int i)
{
    int j;
    int len;
    
    while (i < data->file.line && data->file.file[i])
    {
        j = 0;
        j = skip_whitespace(data->file.file[i], j);
        len = get_len(data->file.file[i], j);
        if (len != 0)
            return i;
        i++;
    }
    return i;
} 

void    parsing(int ac, char **av, t_data *data)
{
    int i;
    
    if (ac != 2)
        ft_error(ERR_ARG, data);
    check_file_extension(av[1], data);
    init_struct_file(data);
    init_player_struct(data);
    open_file(data, av[1]);
    i = get_data(data);
    get_color(data);
    check_color(data);
    i = skip_null_line(data, i);
    get_map(data, i);
    get_player_pos(data);
    // get_textures(data);
    checking_map(data);
}

    // printf("data->file.wall_no : %s\n", data->file.wall_no);
    // printf("data->file.wall_so : %s\n", data->file.wall_so);
    // printf("data->file.wall_we : %s\n", data->file.wall_we);
    // printf("data->file.wall_ea : %s\n", data->file.wall_ea);
    // printf("data->file.color_floor : %s\n", data->file.color_floor);
    // printf("data->file.color_ceiling : %s\n", data->file.color_ceiling);
    // printf("int color floor : %d\n", data->file.c_floor->color);
    // printf("int color ceiling : %d\n", data->file.c_ceiling->color);
    // int j = 0;
    // while(data->file.map[j])
    // {
    //     printf("%s\n", data->file.map[j]);
    //     j++;
    // }
    // printf("data->file->wall_no : %s\n", data->file->wall_no);
    // printf("data->file->wall_so : %s\n", data->file->wall_so);
    // printf("data->file->wall_we : %s\n", data->file->wall_we);
    // printf("data->file->wall_ea : %s\n", data->file->wall_ea);
    // printf("data->file->color_floor : %s\n", data->file->color_floor);
    // printf("data->file->color_ceiling : %s\n", data->file->color_ceiling);
    // printf("int color floor : %d\n", data->file->c_floor->color);
    // printf("int color ceiling : %d\n", data->file->c_ceiling->color);
    // int j = 0;
