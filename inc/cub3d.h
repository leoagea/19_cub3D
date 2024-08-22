/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:15:25 by lagea             #+#    #+#             */
/*   Updated: 2024/08/22 18:10:10 by vdarras          ###   ########.fr       */
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
# include <time.h>
# include <sys/time.h>

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
#  include <X11/keysym.h>
# endif

# ifdef __APPLE__
    # include "../mlx/mlx.h"
	# define KEY_A 0
	# define KEY_D 2
	# define KEY_E 14
	# define KEY_G 5
	# define KEY_M 46
	# define KEY_Q 12
	# define KEY_R 15
	# define KEY_S 1
	# define KEY_W 13
	# define KEY_ESC 53
	# define KEY_PLUS 24
	# define KEY_MINUS 27
	# define KEY_UP 126
	# define KEY_RIGHT 124
	# define KEY_DOWN 125
	# define KEY_LEFT 123
	# define KEY_SHIFT 257
	# define KEY_SPACE 49
	# define KEY_0 82
	# define KEY_1 83
	# define KEY_2 84
	# define KEY_3 85
	# define KEY_4 86
	# define KEY_5 87
	# define KEY_6 88
	# define KEY_7 89
	# define KEY_8 91
	# define KEY_9 92
# endif

# define K 1 // Constante de proportionnalite pour modifier la distance de la camera
# define PLANE 77
# define PI 3.14159265359
# define ONEDEG 0.0174533
# define ROTATE_SPEED 2.6
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
#define ERR_MAP "Error: Map not closed with walls"
#define ERR_XPM "Error: Xpm to image failed"

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
    char **cpy;
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

typedef struct s_fps
{
    struct timeval start;
    struct timeval end;
    double delta_time;
    int    fps;
}           t_fps;

typedef struct s_player
{
    int    map_x;
    int    map_y;
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
    double camera_x; // Position horizontale sur le plan de la camera
    double ray_dir_x;
    double ray_dir_y;
    double delta_dist_x;
    double delta_dist_y;
    double side_dist_x;
    double side_dist_y;
    double perp_wall_dist;
    int    step_x; // Direction of the Ray in X
    int    step_y; // Direction of the Ray in Y
    int    hit; // Flag hit wall
    int    side;
    int    wall_height;
    int    draw_start;
    int    draw_end;
    int    column;
    int    key_left;
    int    key_right;
    int    key_forward;
    int    key_backward;
    t_fps  *fps;
}               t_player;

typedef struct s_xpm
{
    t_img    *wall_no;
    t_img    *wall_so;
    t_img    *wall_ea;
    t_img    *wall_we;
}               t_xpm;

typedef struct s_data
{
    void	*mlx_connection;
	void	*mlx_window;
    t_img	*img;
    t_xpm   xpm;
    t_file  *file;
    t_player *player;   
}               t_data;

/*========================Window==========================*/
void	    create_window(t_data *data);
void	    error_window(t_data *data);
int	        cross_event(t_data *data);
void	    get_fps(t_player *player);
/*========================KeyHook=========================*/
void	    init_key(t_player *player);
void	    handle_input(int keysym, t_data *data);
int	        handle_key(int keysym, t_data *data);
int         key_press(int keysym, t_data *data);
int	        key_release(int keysym, t_data *data);
void	    rotate_right(t_data *data);
void	    rotate_left(t_data *data);
void	    move_forward(t_data *data);
void	    move_backward(t_data *data);
int	        player_movement(t_data *data);

/*========================Raycasting======================*/
void	raycasting(t_player *player, t_data *data);
void	ray_direction(int i, t_player *player);
void	delta_distance(t_player *player);
void	init_dda(t_player *player);
void	dda_algorithm(t_player *player, t_data *data);
void	wall_height(t_player *player);
void	draw(t_data *data, t_player *player);
void	draw_point(t_data *data, int x, int y, int color);
/*========================Parsing=========================*/
/*-----------------------check_arg------------------------*/

void        check_file_extension(char *file, t_data *data);

/*-------------------------color--------------------------*/

void get_color(t_data *data);

/*-------------------------data---------------------------*/

void get_data_line(t_data *data, char *line);

/*--------------------------map---------------------------*/

void checking_map(t_data *data);

/*------------------------parsing-------------------------*/

void    parsing(int ac, char **av, t_data *data);

/*------------------------player--------------------------*/

void get_player_pos(t_data *data);

/*-----------------------readfile-------------------------*/

void        open_file(t_data *data, char *file);

/*-----------------------readfile-------------------------*/

void get_textures(t_data *data);

/*=========================Utils==========================*/
/*------------------------Clear_2-------------------------*/

void clear_xpm(t_data *data);

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
void init_fps_struct(t_data *data);
t_color *init_color_struct(t_data *data);

/*------------------------Parsing-------------------------*/

int skip_whitespace(char *str, int i);
int get_len(char *str, int i);
void check_key(t_data *data, char *key);
void    error_color(t_data *data, char *r, char *g, char *b);
int get_len_array(char **arr);

#endif
