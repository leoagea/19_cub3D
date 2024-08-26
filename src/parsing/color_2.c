/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:55:24 by lagea             #+#    #+#             */
/*   Updated: 2024/08/26 16:03:49 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_is_rgb_color(char *line)
{
    while(*line)
    {
        if (!ft_isdigit((int)*line) && !ft_isalpha((int)*line) && *line != ' ' && *line != ',')
        {
            return 0;
        }
        line++;
    }
    return 1;
}

void get_texture_floor(t_data *data, char *path)
{
    int x;
    int y;
    int fd;
    
    printf("Test\n");
    fd = open(path, O_RDONLY);
    if (fd == -1)
        ft_error(strerror(errno), data);
    close(fd);
    data->xpm.floor = mlx_xpm_file_to_image(data->mlx_connection, data->file->color_floor, &x, &y);
    if (!data->xpm.floor)
        ft_error(ERR_XPM, data);
}

void get_texture_ceiling(t_data *data, char *path)
{
    int x;
    int y;
    int fd;
    
    fd = open(path, O_RDONLY);
    if (fd == -1)
        ft_error(strerror(errno), data);
    close(fd);
    data->xpm.ceiling = mlx_xpm_file_to_image(data->mlx_connection, data->file->color_ceiling, &x, &y);
    if (!data->xpm.ceiling)
        ft_error(ERR_XPM, data);
}