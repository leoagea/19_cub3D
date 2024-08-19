/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:15:25 by lagea             #+#    #+#             */
/*   Updated: 2024/08/19 17:25:33 by vdarras          ###   ########.fr       */
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
#  define XK_ESCAPE 53
# endif

# define WIDTH 1280
# define HEIGHT 720
# define ERR_ARG "Error: Wrong number of arguments, expected only 2 arguments"
# define ERR_EXT "Error: Wrong file extension, expected only .cub extension"
# define ERR_ALLOC "Error: Malloc, allocation failed"
# define ERR_EMPTY "Error: Empty file" 
#define ERR_ARG "Error: Wrong number of arguments, expected only 2 arguments"
#define ERR_EXT "Error: Wrong file extension, expected only .cub extension"
#define ERR_ALLOC "Error: Malloc, allocation failed"
#define ERR_EMPTY "Error: Empty file"
#define ERR_ID "Error: Wrong identifier in description file"
#define ERR_VAL "Error: Wrong value in description file"
#define ERR_COL "Error: Wrong color value in description file"
#define ERR_PLAY "Error: Wrong number of players, expected only 1 player"

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
    char **map;
    int line;
    int count;
    t_color *c_floor;
    t_color *c_ceiling;
}               t_file;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
}			t_img;
   
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
    void	*mlx_connection;
	void	*mlx_window;
    t_img	*img;
    t_file  *file;
    t_player *player;   
}               t_data;

/*========================Window==========================*/
void	    create_window(t_data *data);
void	    error_window(t_data *data);
int	        cross_event(t_data *data);
/*========================KeyHook=========================*/
void	    handle_input(int keysym, t_data *data);
int	        handle_key(int keysym, t_data *data);
/*========================Parsing=========================*/
/*-----------------------check_arg------------------------*/

void        check_file_extension(char *file, t_data *data);

/*-------------------------color--------------------------*/

void get_color(t_data *data);

/*------------------------parsing-------------------------*/

void get_data_line(t_data *data, char *line);

/*------------------------parsing-------------------------*/

void    parsing(int ac, char **av, t_data *data);

/*------------------------player--------------------------*/

void get_player_pos(t_data *data);

/*-----------------------readfile-------------------------*/

void        open_file(t_data *data, char *file);

/*=========================Utils==========================*/
/*-------------------------Clear--------------------------*/

void clear_file(t_data *data);
void clear_color_struct(t_color *color);
void clear_struct_file(t_data *data);
void clear_player_struct(t_data *data);

/*-----------------------Utils_exit-----------------------*/

void        ft_error(char *str, t_data *data);
void        clear_data(t_data *data);
void	    exit_error(void);
void        exit_malloc(void);

/*--------------------------Init--------------------------*/

void init_struct_file(t_data *data);
void init_player_struct(t_data *data);

/*------------------------Parsing-------------------------*/

int skip_whitespace(char *str, int i);
int get_len(char *str, int i);
void check_key(t_data *data, char *key);
void    error_color(t_data *data, char *r, char *g, char *b);
int get_len_array(char **arr);

#endif