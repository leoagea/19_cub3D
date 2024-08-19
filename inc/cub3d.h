/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:15:25 by lagea             #+#    #+#             */
/*   Updated: 2024/08/19 15:20:04 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"

#define ERR_ARG "Error: Wrong number of arguments, expected only 2 arguments"
#define ERR_EXT "Error: Wrong file extension, expected only .cub extension"
#define ERR_ALLOC "Error: Malloc, allocation failed"
#define ERR_EMPTY "Error: Empty file"
#define ERR_ID "Error: Wrong identifier in description file"
#define ERR_VAL "Error: Wrong value in description file"
#define ERR_COL "Error: Wrong color value in description file"

typedef struct s_color
{
    char *r;
    char *g;
    char *b;
    int color;
}               t_color;

typedef struct s_file
{
    char **file;
    char *wall_no;
    char *wall_so;
    char *wall_we;
    char *wall_ea;
    char *color_floor;
    char *color_ceiling;
    int line;
    int count;
    char **map;
    t_color *c_floor;
    t_color *c_ceiling;
}               t_file;

typedef struct s_player
{
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
}               t_player;
    
typedef struct s_data
{
    t_file  *file;   
}               t_data;

/*========================Parsing=========================*/
/*-----------------------check_arg------------------------*/

void check_file_extension(char *file, t_data *data);

/*-------------------------color--------------------------*/

void get_color(t_data *data);

/*------------------------parsing-------------------------*/

void get_data_line(t_data *data, char *line);

/*------------------------parsing-------------------------*/

void    parsing(int ac, char **av, t_data *data);

/*-----------------------readfile-------------------------*/

void open_file(t_data *data, char *file);

/*=========================Utils==========================*/
/*-------------------------Clear--------------------------*/

void clear_file(t_data *data);
void clear_color_struct(t_color *color);
void clear_struct_file(t_data *data);

/*-----------------------Utils_exit-----------------------*/

void ft_error(char *str, t_data *data);
void clear_data(t_data *data);

/*--------------------------Init--------------------------*/

void init_struct_file(t_data *data);

/*------------------------Parsing-------------------------*/

int skip_whitespace(char *str, int i);
int get_len(char *str, int i);
void check_key(t_data *data, char *key);
void    error_color(t_data *data, char *r, char *g, char *b);

#endif