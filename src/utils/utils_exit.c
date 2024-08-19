/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:39:55 by lagea             #+#    #+#             */
/*   Updated: 2024/08/19 17:18:16 by vdarras          ###   ########.fr       */
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

void	exit_error(void)
{
	perror("Error");
	exit(1);
}

void	exit_malloc(void)
{
	write(2, "Error memory allocation\n", 24);
	exit(1);
}