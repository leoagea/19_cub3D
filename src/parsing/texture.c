/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:44:18 by lagea             #+#    #+#             */
/*   Updated: 2024/08/22 16:08:15 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void load_xpm(t_data *data)
{
    int x;
    int y;

    data->xpm.wall_no = mlx_xpm_file_to_image(data->mlx_connection, data->file->wall_no, &x, &y);
    data->xpm.wall_so = mlx_xpm_file_to_image(data->mlx_connection, data->file->wall_so, &x, &y);
    data->xpm.wall_ea = mlx_xpm_file_to_image(data->mlx_connection, data->file->wall_ea, &x, &y);
    data->xpm.wall_we = mlx_xpm_file_to_image(data->mlx_connection, data->file->wall_we, &x, &y);
    if (!data->xpm.wall_no || !data->xpm.wall_so || !data->xpm.wall_ea || !data->xpm.wall_we)
        ft_error(ERR_XPM, data);
}

static int check_xpm(t_data *data)
{
    int fd;
    
    fd = open(data->file->wall_no, O_RDONLY);
    if (fd == -1)
        return (printf("Error 0: "), ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file->wall_so, O_RDONLY);
    if (fd == -1)
        return (printf("Error 1: "), ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file->wall_ea, O_RDONLY);
    if (fd == -1)
        return (printf("Error 2: "), ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file->wall_we, O_RDONLY);
    if (fd == -1)
        return (printf("Error 3: "), ft_error(strerror(errno), data), 1);
    close(fd);
    return 0; 
}

void get_textures(t_data *data)
{
    check_xpm(data);
    load_xpm(data);
}
