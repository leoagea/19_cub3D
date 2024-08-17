/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:20:15 by lagea             #+#    #+#             */
/*   Updated: 2024/08/18 00:53:25 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    parsing(int ac, char **av, t_data *data)
{
    if (ac != 2)
        ft_error(ERR_ARG, data);
    check_file_extension(av[1], data);
    init_struct_file(data);
    open_file(data, av[1]);
    int i;
    i = 0;
    while (i < data->file->line)
    {
        // printf("%s", data->file->file[i]);
        if (data->file->count == 6)
            break;
        get_data_line(data, data->file->file[i]);
        i++;
    }
}