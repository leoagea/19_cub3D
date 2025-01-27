/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:15:25 by lagea             #+#    #+#             */
/*   Updated: 2025/01/27 13:56:31 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# ifdef __linux__
#  include "../mlx-linux/mlx.h"
#  include <X11/keysym.h>
# endif

# ifdef __APPLE__
#  include "../mlx-mac/mlx.h"

typedef enum e_keys
{
	XK_a = 0,
	XK_s,
	XK_d,
	XK_f,
	XK_h,
	XK_g,
	XK_x,
	XK_z,
	XK_c,
	XK_v,
	XK_b = 11,
	XK_q,
	XK_w,
	XK_e,
	XK_r,
	XK_y,
	XK_t,
	XK_1,
	XK_2,
	XK_3,
	XK_4,
	XK_6,
	XK_5,
	XK_equal,
	XK_9,
	XK_7,
	XK_minus,
	XK_8,
	XK_0,
	XK_bracketright,
	XK_o,
	XK_u,
	XK_bracketleft,
	XK_i,
	XK_p,
	XK_Return,
	XK_l,
	XK_j,
	XK_QUOTE,
	XK_k,
	XK_semicolon,
	XK_backslash,
	XK_comma,
	XK_slash,
	XK_n,
	XK_m,
	XK_period,
	XK_Tab,
	XK_space,
	XK_Grave,
	XK_Delete,
	XK_Escape = 53,
	XK_Shift_L = 56,
	XK_Caps_Lock = 57,
	XK_Control_L = 59,
	XK_Shift_R = 60,
	XK_Control_R = 62,
	XK_Num_Lock = 71,
	XK_Return = 76,
	XK_KP_0 = 82,
	XK_KP_1 = 83,
	XK_KP_2 = 84,
	XK_KP_3 = 85,
	XK_KP_4 = 86,
	XK_KP_5 = 87,
	XK_KP_6 = 88,
	XK_KP_7 = 89,
	XK_KP_8 = 91,
	XK_KP_9 = 92,
	XK_Home = 115,
	XK_Page_Up = 116,
	XK_End = 119,
	XK_Page_Down = 121,
	XK_Left = 123,
	XK_Right,
	XK_Down,
	XK_Up
}					t_keys;
# endif

# define PI 3.14159265359
# define ONEDEG 0.0174533
# define SPEED 0.1
# define ROTATE_SPEED 2
# define WIDTH 1280
# define HEIGHT 720
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define ANIM 60000
# define ANIM_DIE 53000
# define SHOOT_DURATION 0.000001
# define STOP_DURATION 2
# define FOG_R 128
# define FOG_G 128
# define FOG_B 128
# define FOG_DIST 20.0
# define MINIMAP_NBR_CELL 7
# define MINIMAP_CELL_SIZE 20
# define MINIMAP_GAP 25
# define MINIMAP_BORDER_THICKNESS 2
# define SLIDERS_HEIGHT 8
# define SLIDERS_LEN 300
# define SLIDERS_FOV_X 480
# define ERR_ARG "Wrong number of arguments, expected only 2 arguments"
# define ERR_EXT "Wrong file extension, expected only .cub extension"
# define ERR_ALLOC "Malloc, allocation failed"
# define ERR_EMPTY "Empty file"
# define ERR_ARG "Wrong number of arguments, expected only 2 arguments"
# define ERR_EXT "Wrong file extension, expected only .cub extension"
# define ERR_ALLOC "Malloc, allocation failed"
# define ERR_EMPTY "Empty file"
# define ERR_ID "Wrong identifier in description file"
# define ERR_TOK "Wrong token in description file, expected 1 key and 1 value"
# define ERR_VAL "Wrong value in description file"
# define ERR_TOK_COL "Wrong color token in description file, expected r,g,b"
# define ERR_COL "Wrong color value in description file"
# define ERR_DUP "Duplicate key in description file"
# define ERR_PLAY "Wrong number of players, expected only 1 player"
# define ERR_MAP "Map not closed with walls"
# define ERR_XPM "Xpm file to image failed"
# define ERR_XPM_EXT "Wall: Xpm file, expected only .xpm extension"
# define ERR_XPM_WEAPON "Weapon: Xpm file to image failed"
# define ERR_XPM_MENU "Menu: Xpm file to image failed"
# define ERR_XPM_ENEMY "Enemy: Xpm file to image failed"
# define ERR_XPM_FLOOR "Floor: Xpm file to image failed"
# define ERR_MAP_CHAR "Wrong char in map"
# define ERR_DOOR "Door not between walls"
# define ERR_DOOR_2 "Door next to another door"
# define ERR_DOOR_3_WALL "Door surrounded by 3 walls"

enum
{
	NO = 0,
	SO,
	EA,
	WE,
	DOOR
};

enum
{
	SIMPLE = 0,
	SHOOT,
	RECOIL,
	REPLACE
};

enum
{
	HORIZONTAL = 0,
	VERTICAL
};

enum
{
	STAND = 0,
	ATTACK,
	DIE1,
	DIE2,
	DIE3,
	DEAD
};
typedef enum e_moves
{
	M_FORWARD = 1,
	M_BACKWARD,
	M_RIGHT,
	M_LEFT,
	R_RIGHT,
	R_LEFT,
	SPEED_UP,
	SPEED_DOWN
}					t_moves;

typedef struct s_color
{
	char			*r;
	char			*g;
	char			*b;
	int				color;
}					t_color;

typedef struct s_draw_enemy
{
	int				i;
	int				tex_x;
	int				tex_y;
	uint32_t		color;
	int				pix;
	int				l;
}					t_draw_enemy;

typedef struct s_file
{
	char			**file;
	char			*wall_no;
	char			*wall_so;
	char			*wall_we;
	char			*wall_ea;
	char			*color_floor;
	char			*color_ceiling;
	char			**map;
	char			**cpy;
	int				line;
	int				count;
	int				flag_no;
	int				flag_so;
	int				flag_ea;
	int				flag_we;
	int				flag_f;
	int				flag_c;
	int				map_height;
	int				map_width;
	t_color			*c_floor;
	t_color			*c_ceiling;
}					t_file;

typedef struct s_img
{
	void			*img_ptr;
	char			*img_pixels_ptr;
	int				*img_pixels_int;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
	int				height;
	int				width;
}					t_img;

typedef struct s_minimap
{
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				map_size;
	double			offset;
	int				nbr_cell;
}					t_minimap;

typedef struct s_anim
{
	int				current_frame;
	struct timeval	last_update;
}					t_anim;

typedef struct s_player
{
	int				map_x;
	int				map_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				wall_height;
	int				draw_start;
	int				draw_end;
	int				column;
	int				key_left;
	int				key_right;
	int				key_forward;
	int				key_backward;
	int				key_move_left;
	int				key_move_right;
	double			rotation_speed;
	int				side_view;
	double			speed;
	int				is_firing;
	int				fire_frame;
	int				counter;
	t_img			weapon[4];
	int				minimap;
	double			z_buffer[WIDTH];
	int				*sprite_order;
	double			*sprite_dist;
	int				col;
	int				hp;
	int				fov;
	double			sensibility;
	int				damage;
	t_anim			anim;
}					t_player;

typedef struct s_wall
{
	double			wall_coord;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
}					t_wall;

typedef struct s_xpm
{
	void			*dead;
	void			*exit;
	void			*menu;
	void			*start;
	void			*floor;
	void			*escape;
	void			*ceiling;
	void			*_return ;
	void			*victory;
	void			*controls;
	void			*speed_up;
	void			*cont_for;
	void			*_continue ;
	void			*cont_back;
	void			*cont_left;
	void			*cont_right;
	void			*cont_moves;
	void			*speed_down;
	void			*cont_vision;
	void			*exit_highlight;
	void			*start_highlight;
	void			*waiting_victory;
	void			*waitng_key_press;
	void			*cont_interations;
	void			*_return_highlight;
	void			*controls_highlight;
	void			*speed_up_highlight;
	void			*_continue_highlight;
	void			*speed_down_highlight;
}					t_xpm;

typedef struct s_floor
{
	double			floor_dir_x0;
	double			floor_dir_y0;
	double			floor_dir_x1;
	double			floor_dir_y1;
	int				p;
	float			pos_z;
	float			row_distance;
	float			floor_step_x;
	float			floor_step_y;
	float			floor_x;
	float			floor_y;
	int				cell_x;
	int				cell_y;
	int				tx;
	int				ty;
	uint32_t		color;
	t_img			floor_img;

}					t_floor;

typedef struct s_controls
{
	int				m_forward;
	int				m_backward;
	int				m_left;
	int				m_right;
	int				r_left;
	int				r_right;
	int				speed_up;
	int				speed_down;
	int				interact;
}					t_controls;

typedef struct s_door
{
	double			pos_x;
	double			pos_y;
	int				x;
	int				y;
	int				dir;
	int				is_open;
	t_img			door_img;
}					t_door;

typedef struct s_flag
{
	int				menu;
	int				pause;
	int				mouse;
	int				controls;
	int				change;
	int				key;
	int				dead;
	int				check_win;
	int				victory;
	int				playing;
}					t_flag;

typedef struct s_slider
{
	int				start_x;
	int				pos_slider;
}					t_slider;

typedef struct s_enemy
{
	int				current_frame;
	struct timeval	last_update;
	int				number_frames;
	int				width;
	int				height;
	double			pos_x;
	double			pos_y;
	double			inverse_matrix;
	double			transform_x;
	double			transform_y;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				sprite_screen_x;
	int				has_shot;
	int				was_shot;
	double			pos_x_cam;
	double			pos_y_cam;
	time_t			last_shoot_time;
	int				hp;
	int				died;
	int				cadavre;
	t_img			img_frames[6];
}					t_enemy;

typedef struct s_data
{
	void			*mlx_connection;
	void			*mlx_window;
	int				texture_index;
	t_minimap		minimap;
	t_img			*img;
	t_wall			wall;
	t_file			file;
	t_player		player;
	t_floor			floor;
	t_xpm			xpm;
	t_img			texture[6];
	t_controls		key;
	t_enemy			*enemy;
	t_door			*door;
	t_flag			menu;
	t_slider		slider[3];
	int				nb_enemy;
	int				enemy_alive;
	int				nb_door;
	void			*letters[65535];
	void			*highlight[65535];
}					t_data;

/*========================Window==========================*/
void				create_window(t_data *data);
void				error_window(t_data *data);
int					cross_event(t_data *data);

/*========================KeyHook=========================*/

void				handle_input(int keysym, t_data *data);

int					key_press(int keysym, t_data *data);
int					key_release(int keysym, t_data *data);
void				rotate_right(t_data *data);
void				rotate_left(t_data *data);
void				move_forward(t_data *data);
void				move_backward(t_data *data);
int					player_movement(t_data *data);

int					key_press(int keysym, t_data *data);
int					key_release(int keysym, t_data *data);
void				rotate_right(t_data *data);
void				rotate_left(t_data *data);
void				move_forward(t_data *data);
void				move_backward(t_data *data);
void				move_left(t_data *data);
void				move_right(t_data *data);
int					player_movement(t_data *data);
void				rotate_mouse(t_data *data, double angle);
void				mouse_rotation(t_data *data);
void				check_near_door(t_data *data, t_player *player,
						t_door *door);					
/*========================Minimap=========================*/
/*------------------------check---------------------------*/

int					is_wall(t_data *data, int x, int y);
int					is_in_map(t_data *data, int x, int y);

/*-------------------------draw---------------------------*/

void				draw_horizontal_minimap_border(t_data *data, int y,
						int size);
void				draw_vertical_minimap_border(t_data *data, int y, int size);
void				draw_player(t_data *data);
void				draw_tiles(t_data *data);
void				draw_enemies(t_data *data);
void				calc_map_enemies(t_data *data, int *enemy_x, int *enemy_y,
						int i);

/*-------------------------minimap------------------------*/

void				create_minimap(t_data *data);

/*==========================Menu==========================*/
/*---------------------change_controls--------------------*/

void				menu_change_controls(t_data *data);
void				change_controls(t_data *data, int keysim);

/*----------------------controls_menu---------------------*/

int					menu_controls(t_data *data);

/*---------------------create_sliders---------------------*/

void				create_cursor(t_data *data, int x, int y);
void				create_slider(t_data *data, int start_x, int start_y,
						int len);

/*------------------------hp_bar--------------------------*/

void				draw_hp_bar(t_data *data);

/*------------------------letters-------------------------*/

void				load_letters(t_data *data);

/*--------------------load_highlight----------------------*/

void				load_highlight_xpm(t_data *data);

/*---------------------load_letters-----------------------*/

void				load_letters_xpm(t_data *data);

/*--------------------------menu--------------------------*/

int					menu_controls(t_data *data);
int					menu_pause(t_data *data);
int					create_menu(t_data *data);

/*---------------------mouse_controls----------------------*/

int					handle_mouse_controls_menu(t_data *data, int keysim, int x,
						int y);

/*----------------------mouse_sliders----------------------*/

int					handle_mouse_slider(t_data *data, int keysim, int x, int y);

/*--------------------------sliders------------------------*/

void				set_sensibility(t_data *data);
void				draw_slider_sensi(t_data *data);
void				set_difficulty(t_data *data);
void				draw_slider_dmg(t_data *data, t_slider slider);

/*----------------------switch_menu-----------------------*/

int					handle_mouse_menu(int keysm, int x, int y, t_data *data);

/*========================Raycasting======================*/
/*--------------------------calcul------------------------*/
void				simple_color(t_data *data, int height, int *i, int color);
void				delta_distance(t_player *player);
void				init_dda(t_player *player);
void				dda_algorithm(t_player *player, t_data *data);
void				wall_height(t_player *player);
void				interact_door(t_data *data, t_player *player, t_door *door);

/*---------------------------draw-------------------------*/

void				draw(t_data *data, t_player *player);
void				draw_point(t_data *data, int x, int y, long color);
void				draw_crosshair(t_data *data);

/*-----------------------raycasting-----------------------*/

void				raycasting(t_player *player, t_data *data);
void				ray_direction(int i, t_player *player);

/*=========================Texture========================*/
/*---------------------------wall-------------------------*/

void				wall_texture(t_data *data, t_player *player, int i);
void				side_view(t_data *data, t_player *player);

/*=========================Weapon=========================*/
/*----------------------load_weapon-----------------------*/

void				load_weapon(t_data *data);

/*-------------------------shoot--------------------------*/

void				render_weapon(t_data *data);
void				check_if_enemy(t_data *data, t_player *player,
						t_enemy *enemy);
void				reset_shot(t_data *data, t_enemy *enemy);
void	transparency_linux(t_data *data, t_img *img, int start_x, int start_y);

/*========================Monster=========================*/
/*------------------------damage--------------------------*/

void				take_damage(t_data *data, t_player *player);
void				enemy_die(t_data *data, t_enemy *enemy,
						int i);
int					verif_all_dead(t_data *data, t_enemy *enemy);

/*-------------------------draw---------------------------*/

void				enemy_draw(t_data *data, t_player *player, t_enemy *enemy,
						int i);

/*-------------------------dying--------------------------*/

void				enemy_dying(t_data *data, t_player *player, t_enemy *enemy,
						int i);
void				enemy_draw_dying(t_data *data, t_player *player,
						t_enemy *enemy, int i);
void				enemy_draw_dead(t_data *data, t_player *player,
						t_enemy *enemy, int i);

/*------------------------monster-------------------------*/

void				enemy_raycast(t_player *player, t_enemy *enemy, int i);

void				enemy_calculation(t_data *data, t_player *player,
						t_enemy *enemy);
int					verif_all_dead(t_data *data, t_enemy *enemy);
void				draw_floor(t_data *data, t_player *player, t_floor *floor);
void				loop_verticaly(t_data *data, t_player *player,
						t_floor *floor, int i);
void				loop_horizontaly(t_data *data, t_floor *floor, int i,
						int j);
void				load_floor(t_data *data);
void				load_door(t_data *data);

/*========================Parsing=========================*/
/*----------------------assign_data-----------------------*/

void				assign_value(t_data *data, char *key, char *value);

/*-----------------------check_arg------------------------*/

void				check_file_extension(char *file, t_data *data);
void				check_text_extension(char *file, t_data *data);

/*----------------------check_map-------------------------*/

void				checking_map(t_data *data);

/*-------------------------check--------------------------*/

void				check_color_textures(t_data *data, char *line);
void				check_color(t_data *data);

/*-----------------------color_2--------------------------*/

int					check_is_rgb_color(char *line);
void				get_texture_floor(t_data *data, char *path);
void				get_texture_ceiling(t_data *data, char *path);

/*-------------------------color--------------------------*/

void				get_color(t_data *data);

/*-------------------------data---------------------------*/

void				get_data_line(t_data *data, char *line);

/*-----------------------door_2---------------------------*/

void				extract_pos(t_data *data, int i, int j, int k);

/*------------------------door----------------------------*/

void				get_door_pos(t_data *data);
void				init_doors(t_data *data);

/*-------------------------map----------------------------*/

void				get_map(t_data *data, int i);

/*----------------------load_xpm--------------------------*/

void				load_xpm_wall(t_data *data);
void				load_xpm_menu(t_data *data);
void				load_xpm_controls_menu(t_data *data);
void				load_xpm_controls_menu_2(t_data *data);

/*------------------------parsing-------------------------*/

void				parsing(int ac, char **av, t_data *data);

/*------------------------player--------------------------*/

void				get_player_pos(t_data *data);

/*-----------------------readfile-------------------------*/

void				open_file(t_data *data, char *file);

/*-----------------------readfile-------------------------*/

void				get_textures(t_data *data);

/*=========================Utils==========================*/
/*-----------------------clear_xpm------------------------*/

void				clear_xpm_menu_2(t_data *data);
void				clear_xpm_menu(t_data *data);
void				clear_xpm_letters(t_data *data);
void				clear_xpm_texture(t_data *data);
void				clear_xpm_enemy(t_data *data);

/*-------------------------Clear--------------------------*/

void				clear_file(t_data *data);
void				clear_color_struct(t_color *color);
void				clear_struct_file(t_data *data);

/*-----------------------Utils_exit-----------------------*/

void				clear_xpm(t_data *data);
void				clear_data(t_data *data);
void				ft_error(char *str, t_data *data);
void				exit_error(void);
void				exit_malloc(void);

/*-------------------------Init_2-------------------------*/

void				init_minimap_struct(t_data *data);
void				init_key_struct(t_data *data);
void				init_slider_struct(t_data *data);
void				init_xpm_struct(t_data *data);

/*-------------------------Init_3-------------------------*/

void				init_textures(t_data *data);
void				init_ennemy_textures(t_data *data);
void				init_weapon_textures(t_data *data);
void				init_menu_struct(t_data *data);

/*-----------------------init_enemy-----------------------*/

void				init_enemy(t_data *data, t_enemy *enemy);

/*--------------------------Init--------------------------*/

void				init_struct_file(t_data *data);
void				init_player_struct(t_data *data);
t_color				*init_color_struct(t_data *data);
void				init_data(t_data *data);

/*---------------------------mlx--------------------------*/

void				img_to_win(t_data *data, void *img, int x, int y);
void				letters_to_img(t_data *data, int key, char *img);
void				highlight_to_img(t_data *data, int key, char *img);

/*------------------------Parsing-------------------------*/

int					skip_whitespace(char *str, int i);
int					get_len(char *str, int i);
void				check_key(t_data *data, char *key);
void				error_color(t_data *data, char *r, char *g, char *b);
int					get_len_array(char **arr);

#endif
