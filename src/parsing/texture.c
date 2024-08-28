/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:44:18 by lagea             #+#    #+#             */
/*   Updated: 2024/08/28 14:01:46 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void load_xpm(t_data *data)
{
    data->texture[NO].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, data->file.wall_no, &data->texture[NO].width, &data->texture[NO].height);
    data->texture[NO].img_pixels_ptr = mlx_get_data_addr(data->texture[NO].img_ptr, &(data->texture[NO].bits_per_pixel), &(data->texture[0].size_line), &(data->texture[NO].endian));
    data->texture[SO].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, data->file.wall_so, &data->texture[SO].width, &data->texture[SO].height);
    data->texture[SO].img_pixels_ptr = mlx_get_data_addr(data->texture[SO].img_ptr, &(data->texture[SO].bits_per_pixel), &(data->texture[0].size_line), &(data->texture[SO].endian));
    data->texture[EA].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, data->file.wall_ea, &data->texture[EA].width, &data->texture[EA].height);
    data->texture[EA].img_pixels_ptr = mlx_get_data_addr(data->texture[EA].img_ptr, &(data->texture[EA].bits_per_pixel), &(data->texture[0].size_line), &(data->texture[EA].endian));
    data->texture[WE].img_ptr = mlx_xpm_file_to_image(data->mlx_connection, data->file.wall_we, &data->texture[WE].width, &data->texture[WE].height);
    data->texture[WE].img_pixels_ptr = mlx_get_data_addr(data->texture[WE].img_ptr, &(data->texture[WE].bits_per_pixel), &(data->texture[0].size_line), &(data->texture[WE].endian));
    if (!data->texture[NO].img_ptr || !data->texture[SO].img_ptr || !data->texture[EA].img_ptr || !data->texture[WE].img_ptr)
        ft_error(ERR_XPM, data);
    int x;
    int y;
    data->xpm.menu = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/Menu.xpm", &x, &y);
    data->xpm.start = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/Start.xpm", &x, &y);
    data->xpm.start_select = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/Start_select.xpm", &x, &y);
    data->xpm.exit = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/Exit.xpm", &x, &y);
    data->xpm.exit_select = mlx_xpm_file_to_image(data->mlx_connection, "./assets/menu/Exit_select.xpm", &x, &y);
}
 
static int check_xpm(t_data *data)
{
    int fd;
    
    fd = open(data->file.wall_no, O_RDONLY);
    if (fd == -1)
        return (ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file.wall_so, O_RDONLY);
    if (fd == -1)
        return (ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file.wall_ea, O_RDONLY);
    if (fd == -1)
        return (ft_error(strerror(errno), data), 1);
    close(fd);
    fd = open(data->file.wall_we, O_RDONLY);
    if (fd == -1)
        return (ft_error(strerror(errno), data), 1);
    close(fd);
    // fd = open("./assets/menu.xpm", O_RDONLY);
    // if (fd == -1)
    //     return (ft_error(strerror(errno), data), 1);
    // close(fd);
    return 0; 
}

void get_textures(t_data *data)
{
    // check_xpm(data);
    load_weapon(data);
    load_xpm(data);
    if (!data->file.c_floor)
        get_texture_floor(data, data->file.color_floor);
    if (!data->file.c_ceiling)
        get_texture_floor(data, data->file.color_ceiling);
}
