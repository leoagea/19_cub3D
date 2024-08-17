/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:39:55 by lagea             #+#    #+#             */
/*   Updated: 2024/08/17 22:55:08 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void clear_data(t_data *data)
{
    int i;

    i = 0;
    if (data->file->file)
    {
        while (data->file->file[i])
        {
            free(data->file->file[i]);
            i++;
        }
        free(data->file->file);   
    }
    if (data->file)
        free(data->file);
}

void ft_error(char *str, t_data *data)
{
    printf("%s\n", str);
    clear_data(data);
    exit(1);
}
