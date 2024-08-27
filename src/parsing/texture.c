/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:44:18 by lagea             #+#    #+#             */
/*   Updated: 2024/08/27 14:09:05 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void load_xpm(t_data *data)
{
    data->texture[NO].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, data->file->wall_no, &data->texture[NO].width, &data->texture[NO].height);
    data->texture[NO].img_pixels_ptr = mlx_get_data_addr(data->texture[NO].img_ptr, &(data->texture[NO].bits_per_pixel), &(data->texture[0].size_line), &(data->texture[NO].endian));
    data->texture[SO].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, data->file->wall_so, &data->texture[SO].width, &data->texture[SO].height);
    data->texture[SO].img_pixels_ptr = mlx_get_data_addr(data->texture[SO].img_ptr, &(data->texture[SO].bits_per_pixel), &(data->texture[0].size_line), &(data->texture[SO].endian));
    data->texture[EA].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, data->file->wall_ea, &data->texture[EA].width, &data->texture[EA].height);
    data->texture[EA].img_pixels_ptr = mlx_get_data_addr(data->texture[EA].img_ptr, &(data->texture[EA].bits_per_pixel), &(data->texture[0].size_line), &(data->texture[EA].endian));
    data->texture[WE].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, data->file->wall_we, &data->texture[WE].width, &data->texture[WE].height);
    data->texture[WE].img_pixels_ptr = mlx_get_data_addr(data->texture[WE].img_ptr, &(data->texture[WE].bits_per_pixel), &(data->texture[0].size_line), &(data->texture[WE].endian));
    if (!data->texture[NO].img_ptr || !data->texture[SO].img_ptr || !data->texture[EA].img_ptr || !data->texture[WE].img_ptr)
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
    // check_xpm(data);
    load_weapon(data);
    load_xpm(data);
}
