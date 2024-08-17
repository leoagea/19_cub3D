/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:20:15 by lagea             #+#    #+#             */
/*   Updated: 2024/08/18 01:46:18 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void    get_data(t_data *data)
{
    int i;
    i = 0;
    
    while (i < data->file->line)
    {
        if (data->file->count == 6)
            return ;
        get_data_line(data, data->file->file[i]);
        i++;
    }
}

void    parsing(int ac, char **av, t_data *data)
{
    if (ac != 2)
        ft_error(ERR_ARG, data);
    check_file_extension(av[1], data);
    init_struct_file(data);
    open_file(data, av[1]);
    get_data(data);
    printf("data->file->wall_no : %s\n", data->file->wall_no);
    printf("data->file->wall_so : %s\n", data->file->wall_so);
    printf("data->file->wall_we : %s\n", data->file->wall_we);
    printf("data->file->wall_ea : %s\n", data->file->wall_ea);
    printf("data->file->color_floor : %s\n", data->file->color_floor);
    printf("data->file->color_ceiling : %s\n", data->file->color_ceiling);
}