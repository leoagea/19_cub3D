/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:20:15 by lagea             #+#    #+#             */
/*   Updated: 2024/08/16 18:57:26 by lagea            ###   ########.fr       */
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
    while (i < data->file.line)
    {
        printf("%s", data->file.file[i]);
        i++;
    }
}