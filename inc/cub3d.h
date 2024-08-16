/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:15:25 by lagea             #+#    #+#             */
/*   Updated: 2024/08/16 17:43:05 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"

#define ERR_ARG "Error: Wrong number of arguments, expected only 2 arguments"
#define ERR_EXT "Error: Wrong file extension, expected only .cub extension"
#define ERR_ALLOC "Error: Malloc map, allocation failed"
#define ERR_EMPTY "Error: Empty file"

typedef struct s_file
{
    char **file;
    char *wall_no;
    char *wall_so;
    char *wall_we;
    char *wall_ea;
    char *color_floor;
    char *color_ceiling;
}               t_file;

typedef struct s_data
{
    t_file  file;   
}               t_data;

/*========================Parsing=========================*/
/*-----------------------check_arg------------------------*/

void check_file_extension(char *file);

/*------------------------parsing-------------------------*/

void    parsing(int ac, char **av, t_data *data);

/*-----------------------readfile-------------------------*/

void open_file(t_data *data, char *file);

/*=========================Utils==========================*/
/*-----------------------Utils_exit-----------------------*/

void ft_error(char *str);

/*--------------------------Init--------------------------*/

void init_struct_file(t_data *data);

#endif