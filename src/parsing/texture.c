/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:44:18 by lagea             #+#    #+#             */
/*   Updated: 2024/08/26 16:02:13 by lagea            ###   ########.fr       */
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
        return (ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file->wall_so, O_RDONLY);
    if (fd == -1)
        return (ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file->wall_ea, O_RDONLY);
    if (fd == -1)
        return (ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file->wall_we, O_RDONLY);
    if (fd == -1)
        return (ft_error(strerror(errno), data), 1);
    close(fd);
    return 0; 
}

void get_textures(t_data *data)
{
    check_xpm(data);
    load_xpm(data);
    if (!data->file->c_floor)
        get_texture_floor(data, data->file->color_floor);
    if (!data->file->c_ceiling)
        get_texture_floor(data, data->file->color_ceiling);
}
