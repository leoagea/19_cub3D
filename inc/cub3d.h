/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:15:25 by lagea             #+#    #+#             */
/*   Updated: 2024/08/18 17:32:16 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
#  include <X11/keysym.h>
# endif

# ifdef __APPLE__
#  include "../mlx/mlx.h"
# endif

# define WIDTH 1920
# define HEIGHT 1080
# define ERR_ARG "Error: Wrong number of arguments, expected only 2 arguments"
# define ERR_EXT "Error: Wrong file extension, expected only .cub extension"
# define ERR_ALLOC "Error: Malloc, allocation failed"
# define ERR_EMPTY "Error: Empty file"

typedef enum    e_enumdata
{
    NORTH = 0,
    SOUTH,
    WEST,
    EST,
    
}   t_enumdata;   

typedef struct s_file
{
    char **file;
    char *wall_no;
    char *wall_so;
    char *wall_we;
    char *wall_ea;
    char *color_floor;
    char *color_ceiling;
    int c_ceiling;
    int c_floor;
    char **map;
    int line;
}               t_file;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
}			t_img;

typedef struct s_data
{
    void	*mlx_connection;
	void	*mlx_window;
    t_img	*img;
    t_file  *file;   
}               t_data;
/*========================Window==========================*/
t_data  *create_window(void);
/*========================Parsing=========================*/
/*-----------------------check_arg------------------------*/

void        check_file_extension(char *file, t_data *data);

/*------------------------parsing-------------------------*/

void        parsing(int ac, char **av, t_data *data);

/*-----------------------readfile-------------------------*/

void        open_file(t_data *data, char *file);

/*=========================Utils==========================*/
/*-----------------------Utils_exit-----------------------*/

void        ft_error(char *str, t_data *data);
void        clear_data(t_data *data);
void        exit_error(t_data *data);
void        exit_malloc(t_data *data);

/*--------------------------Init--------------------------*/

void        init_struct_file(t_data *data);


#endif