/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:15:25 by lagea             #+#    #+#             */
/*   Updated: 2024/09/11 18:07:07 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <limits.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# include <stdbool.h>

# ifdef __linux__
#  include "../mlx_linux/mlx.h"
#  include <X11/keysym.h>
#  define KEY_A 113
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_G 103
#  define KEY_M 109
#  define KEY_Q 97
#  define KEY_R 114
#  define KEY_S 115
#  define KEY_W 122
#  define KEY_ESC 65307
#  define KEY_PLUS 61
#  define KEY_MINUS 45
#  define KEY_UP 65362
#  define KEY_RIGHT 65363
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_SHIFT 65505
#  define KEY_SPACE 32
# endif

# ifdef __APPLE__
#  include "../mlx/mlx.h"

typedef enum e_keys
{
	KEY_A = 0,
	KEY_S,
	KEY_D,
	KEY_F,
	KEY_H,
	KEY_G,
	KEY_X,
	KEY_Z,
	KEY_C,
	KEY_V,
	KEY_B = 11,
	KEY_Q,
	KEY_W,
	KEY_E,
	KEY_R,
	KEY_Y,
	KEY_T,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_6,
	KEY_5,
	KEY_EQUAL,
	KEY_9,
	KEY_7,
	KEY_MINUS,
	KEY_8,
	KEY_0,
	KEY_RIGHT_BRACKET,
	KEY_O,
	KEY_U,
	KEY_LEFT_BRACKET,
	KEY_I,
	KEY_P,
	KEY_RETURN,
	KEY_L,
	KEY_J,
	KEY_QUOTE,
	KEY_K,
	KEY_SEMICOLON,
	KEY_BACKSLASH,
	KEY_COMMA,
	KEY_SLASH,
	KEY_N,
	KEY_M,
	KEY_PERIOD,
	KEY_TAB,
	KEY_SPACE,
	KEY_GRAVE,
	KEY_DELETE,
	KEY_ESCAPE = 53,
	KEY_COMMAND = 55,
	KEY_SHIFT = 56,
	KEY_CAPSLOCK = 57,
	KEY_OPTION = 58,
	KEY_CONTROL = 59,
	KEY_SHIFT_RIGHT = 60,
	KEY_OPTION_RIGHT = 61,
	KEY_CONTROL_RIGHT = 62,
	KEY_FN = 63,
	KEY_NUM_LOCK = 71,
	KEY_ENTER = 76,
	KEY_NUM_0 = 82,
	KEY_NUM_1 = 83,
	KEY_NUM_2 = 84,
	KEY_NUM_3 = 85,
	KEY_NUM_4 = 86,
	KEY_NUM_5 = 87,
	KEY_NUM_6 = 88,
	KEY_NUM_7 = 89,
	KEY_NUM_8 = 91,
	KEY_NUM_9 = 92,
	KEY_HOME = 115,
	KEY_PAGE_UP = 116,
	KEY_FORWARD_DELETE = 117,
	KEY_END = 119,
	KEY_PAGE_DOWN = 121,
	KEY_LEFT_ARROW = 123,
	KEY_RIGHT_ARROW,
	KEY_DOWN_ARROW,
	KEY_UP_ARROW
}				t_keys;
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
# define ERR_XPM "Wall: Xpm file to image failed"
# define ERR_XPM_WEAPON "Weapon: Xpm file to image failed"
# define ERR_XPM_MENU "Menu: Xpm file to image failed"
# define ERR_XPM_ENEMY "Enemy: Xpm file to image failed"
# define ERR_MAP_CHAR "Wrong char in map"
# define ERR_DOOR "Door not between walls"
# define ERR_DOOR_2 "Door next to another door"
# define ERR_DOOR_3_WALL "Door surrounded by 3 walls"
enum
{
	NO = 0,
	SO,
	EA,
	WE
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
}				t_moves;

typedef struct s_color
{
	char		*r;
	char		*g;
	char		*b;
	int			color;
}				t_color;

typedef struct s_draw_enemy
{
	int 		i;
	int			tex_x;
	int			tex_y;
	uint32_t	color;
	int			pix;
	int			l;
}				t_draw_enemy;

typedef struct s_file
{
	char		**file;
	char		*wall_no;
	char		*wall_so;
	char		*wall_we;
	char		*wall_ea;
	char		*color_floor;
	char		*color_ceiling;
	char		**map;
	char		**cpy;
	int			line;
	int			count;
	int			flag_no;
	int			flag_so;
	int			flag_ea;
	int			flag_we;
	int			flag_f;
	int			flag_c;
	int			map_height;
	int			map_width;
	t_color		*c_floor;
	t_color		*c_ceiling;
}				t_file;

typedef struct s_img
{
	void		*img_ptr;
	char		*img_pixels_ptr;
	int			bits_per_pixel;
	int			endian;
	int			size_line;
	int			height;
	int			width;
}				t_img;

typedef struct s_minimap
{
	int			start_x;
	int			start_y;
    int         end_x;
    int         end_y;
    int         map_size;
	double 		offset;
	int			nbr_cell;
}				t_minimap;

typedef struct s_anim
{
    int current_frame;
    struct timeval last_update;
}               t_anim;

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
    int    key_move_left;
    int    key_move_right;
    double rotation_speed;
    int    side_view;
    double speed;
    int     is_firing;
    int     fire_frame;
    int     counter;
    t_img    weapon[4];
    int     minimap;
    double  z_buffer[WIDTH];
    int     *sprite_order;
    double  *sprite_dist;
    int     col;
    int     hp;
    int     fov;
	double	sensibility;
	int		damage;
    t_anim  anim;
}               t_player;

typedef struct s_wall
{
	double		wall_coord;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_wall;

typedef struct s_xpm
{
	void		*dead;
	void		*exit;
	void		*menu;
	void		*start;
	void		*floor;
	void		*escape;
	void		*ceiling;
	void 		*_return;
	void		*victory;
	void		*controls;
	void		*speed_up;
	void		*cont_for;
	void 		*_continue;
	void		*cont_back;
	void		*cont_left;
	void		*cont_right;
	void		*cont_moves;
	void		*speed_down;
	void		*cont_vision;
	void		*exit_highlight;
	void		*start_highlight;
	void		*waiting_victory;
	void		*waitng_key_press;
	void		*cont_interations;
	void		*_return_highlight;
	void		*controls_highlight;
	void		*speed_up_highlight;
	void		*_continue_highlight;
	void		*speed_down_highlight;
}				t_xpm;

typedef struct s_floor
{
    double floor_dir_x0;
    double floor_dir_y0;
    double floor_dir_x1;
    double floor_dir_y1;
    int     p;
    float   pos_z;
    float   row_distance;
    float   floor_step_x;
    float   floor_step_y;
    float   floor_x;
    float   floor_y;
    int     cell_x;
    int     cell_y;
    int     tx;
    int     ty;
	uint32_t color;
    t_img   floor_img;

}	t_floor;

typedef struct s_controls
{
	int			m_forward;
	int			m_backward;
	int			m_left;
	int			m_right;
	int			r_left;
	int			r_right;
	int			speed_up;
	int			speed_down;
}				t_controls;

typedef struct s_door
{
	double		pos_x;
	double		pos_y;
	int			dir;
}				t_door;

typedef struct s_flag
{
	int			menu;
	int			pause;
	int			mouse;
	int			controls;
	int			change;
	int			key;
	int			dead;
	int			check_win;
	int			victory;
	int			playing;
}				t_flag;

typedef struct s_slider
{
	int start_x;
	int pos_slider;
}				t_slider;

typedef struct  s_enemy
{
    int     current_frame;
    struct timeval last_update;
    int     number_frames;
    int     width;
    int     height;
    double  pos_x;
    double  pos_y;
    double  inverse_matrix;
    double  transform_x;
    double  transform_y;
    int     draw_start_x;
    int     draw_start_y;
    int     draw_end_x;
    int     draw_end_y;
    int     sprite_screen_x;
    int     has_shot;
    int     was_shot;
    double pos_x_cam;
    double pos_y_cam;
    time_t  last_shoot_time;
    int     hp;
    int     died;
    int     cadavre;
    t_img   img_frames[6];
}   t_enemy;

typedef struct s_data
{
	void		*mlx_connection;
	void		*mlx_window;
	t_minimap	minimap;
	t_img		*img;
	t_wall		wall;
	t_file		file;
	t_player	player;
	t_floor		floor;
	t_xpm		xpm;
	t_img		texture[4];
	t_controls	key;
	t_enemy	    *enemy;
	t_door		*door;
	t_flag		menu;
	t_slider	slider[3];
	int			nb_enemy;
	int			nb_door;
	void		*letters[128];
	void		*highlight[128];
}				t_data;

/*========================Window==========================*/
void			create_window(t_data *data);
void			error_window(t_data *data);
int				cross_event(t_data *data);

/*========================KeyHook=========================*/

void			handle_input(int keysym, t_data *data);

int				key_press(int keysym, t_data *data);
int				key_release(int keysym, t_data *data);
void			rotate_right(t_data *data);
void			rotate_left(t_data *data);
void			move_forward(t_data *data);
void			move_backward(t_data *data);
int				player_movement(t_data *data);

int				key_press(int keysym, t_data *data);
int				key_release(int keysym, t_data *data);
void			rotate_right(t_data *data);
void			rotate_left(t_data *data);
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
int				player_movement(t_data *data);
void			rotate_mouse(t_data *data, double angle);
void			mouse_rotation(t_data *data);

/*========================Minimap=========================*/
/*------------------------check---------------------------*/

int is_wall(t_data *data, int x, int y);
int is_in_map(t_data *data, int x, int y);

/*-------------------------draw---------------------------*/

void draw_horizontal_minimap_border(t_data *data, int y, int size);
void draw_vertical_minimap_border(t_data *data, int y, int size);
void  draw_player(t_data *data);
void draw_tiles(t_data *data);

/*-------------------------minimap------------------------*/

void create_minimap(t_data *data);

/*==========================Menu==========================*/
/*---------------------change_controls--------------------*/

void			menu_change_controls(t_data *data);
void			change_controls(t_data *data, int keysim);

/*----------------------controls_menu---------------------*/

int	menu_controls(t_data *data);

/*---------------------create_sliders---------------------*/

void create_cursor(t_data *data, int x, int y);
void create_slider(t_data *data, int start_x, int start_y, int len);

/*------------------------hp_bar--------------------------*/

void			draw_hp_bar(t_data *data);

/*------------------------letters-------------------------*/

void			init_letters(t_data *data);

/*--------------------load_highlight----------------------*/

void	load_highlight_xpm(t_data *data);

/*---------------------load_letters-----------------------*/

void	load_letters_xpm(t_data *data);

/*--------------------------menu--------------------------*/

int				menu_controls(t_data *data);
int				menu_pause(t_data *data);
int				create_menu(t_data *data);

/*---------------------mouse_controls----------------------*/

int handle_mouse_controls_menu(t_data *data, int keysim, int x, int y);

/*----------------------mouse_sliders----------------------*/

int handle_mouse_slider(t_data *data, int keysim, int x, int y);

/*-------------------------sliders---0---------------------*/

void	set_sensibility(t_data *data);
void	draw_slider_sensi(t_data *data);
void	set_difficulty(t_data *data);
void	draw_slider_dmg(t_data *data, t_slider slider);
void	set_map_zoom(t_data *data);
void	draw_slider_map(t_data *data, t_slider slider);

/*----------------------switch_menu-----------------------*/

int	handle_mouse_menu(int keysm, int x, int y, t_data *data);

/*========================Raycasting======================*/
/*--------------------------calcul------------------------*/

void	delta_distance(t_player *player);
void	init_dda(t_player *player);
void	dda_algorithm(t_player *player, t_data *data);
void	wall_height(t_player *player);

/*---------------------------draw-------------------------*/

void	draw(t_data *data, t_player *player);
void	draw_point(t_data *data, int x, int y, long color);
void	draw_crosshair(t_data *data);

/*---------------------------fog--------------------------*/

float    calculate_fog(float distance, float max_fog_dist);
uint32_t apply_fog(uint32_t color, float fog_factor);
void    draw_with_fog(t_data *data, int x, int y, uint32_t color, float distance);

/*-----------------------raycasting-----------------------*/

void	raycasting(t_player *player, t_data *data);
void	ray_direction(int i, t_player *player);

/*=========================Texture========================*/
/*---------------------------wall-------------------------*/

void	wall_texture(t_data *data, t_player *player, int i);
void	side_view(t_player *player);

/*=========================Weapon=========================*/
/*----------------------load_weapon-----------------------*/

void	load_weapon(t_data *data);

/*-------------------------shoot--------------------------*/

void	render_weapon(t_data *data);
void	check_if_enemy(t_data *data, t_player *player, t_enemy *enemy);
void	reset_shot(t_data *data, t_enemy *enemy);

void	draw_weapon(t_data *data, int weapon_pos);
int	    shoot_event(int keysym, int x, int y, t_data *data);
double	enemy_distance(t_player *player, t_enemy *enemy);

/*========================Monster=========================*/
/*------------------------damage--------------------------*/

void	take_damage(t_data *data, t_player *player);
void	enemy_die(t_data *data, t_player *player, t_enemy *enemy, int i);
int	    verif_all_dead(t_data *data, t_enemy *enemy);

/*-------------------------draw---------------------------*/

void	enemy_draw(t_data *data, t_player *player, t_enemy *enemy, int i);

/*-------------------------dying--------------------------*/

void	enemy_dying(t_data *data, t_player *player, t_enemy *enemy, int i);
void	enemy_draw_dying(t_data *data, t_player *player, t_enemy *enemy, int i);
void	enemy_draw_dead(t_data *data, t_player *player, t_enemy *enemy, int i);

/*------------------------monster-------------------------*/

void	enemy_raycast(t_player *player, t_enemy *enemy, int i);

void	enemy_calculation(t_data *data, t_player *player, t_enemy *enemy);
int	    verif_all_dead(t_data *data, t_enemy *enemy);
float    calculate_fog(float distance, float max_fog_dist);
uint32_t apply_fog(uint32_t color, float fog_factor);
void    draw_with_fog(t_data *data, int x, int y, uint32_t color, float distance);
void	draw_floor(t_data *data, t_player *player, t_floor *floor);
void	loop_verticaly(t_data *data, t_player *player, t_floor *floor, int i);
void	loop_horizontaly(t_data *data, t_floor *floor, int i, int j);
void	load_floor(t_data *data);



/*========================Parsing=========================*/
/*----------------------assign_data-----------------------*/

void	assign_value(t_data *data, char *key, char *value);

/*-----------------------check_arg------------------------*/

void			check_file_extension(char *file, t_data *data);

/*----------------------check_map-------------------------*/

void			checking_map(t_data *data);

/*-------------------------check--------------------------*/

void			check_color_textures(t_data *data, char *line);
void			check_color(t_data *data);

/*-----------------------color_2--------------------------*/

int				check_is_rgb_color(char *line);
void			get_texture_floor(t_data *data, char *path);
void			get_texture_ceiling(t_data *data, char *path);

/*-------------------------color--------------------------*/

void			get_color(t_data *data);

/*-------------------------data---------------------------*/

void			get_data_line(t_data *data, char *line);

/*------------------------door----------------------------*/

void			get_door_pos(t_data *data);

/*-------------------------map----------------------------*/

void			get_map(t_data *data, int i);

/*----------------------load_xpm--------------------------*/

void	load_xpm_wall(t_data *data);
void	load_xpm_menu(t_data *data);
void	load_xpm_controls_menu(t_data *data);
void	load_xpm_controls_menu_2(t_data *data);

/*------------------------parsing-------------------------*/

void			parsing(int ac, char **av, t_data *data);

/*------------------------player--------------------------*/

void			get_player_pos(t_data *data);

/*-----------------------readfile-------------------------*/

void			open_file(t_data *data, char *file);

/*-----------------------readfile-------------------------*/

void			get_textures(t_data *data);

/*=========================Utils==========================*/
/*-----------------------clear_xpm------------------------*/

void	clear_xpm_menu_2(t_data *data);
void	clear_xpm_menu(t_data *data);
void	clear_xpm_letters(t_data *data);
void	clear_xpm_texture(t_data *data);
void	clear_xpm_enemy(t_data *data);

/*-------------------------Clear--------------------------*/

void			clear_file(t_data *data);
void			clear_color_struct(t_color *color);
void			clear_struct_file(t_data *data);

/*-----------------------Utils_exit-----------------------*/

void			clear_xpm(t_data *data);
void			clear_data(t_data *data);
void			ft_error(char *str, t_data *data);
void			exit_error(void);
void			exit_malloc(void);

/*-------------------------Init_2-------------------------*/

void			init_minimap_struct(t_data *data);
void	init_key_struct(t_data *data);
void	init_slider_struct(t_data *data);
void	init_xpm_struct(t_data *data);

/*-----------------------init_enemy-----------------------*/

void	init_enemy(t_data *data, t_enemy *enemy);

/*--------------------------Init--------------------------*/

void			init_struct_file(t_data *data);
void			init_player_struct(t_data *data);
t_color			*init_color_struct(t_data *data);
void			init_data(t_data *data);

/*---------------------------mlx--------------------------*/

void img_to_win(t_data *data, void *img, int x, int y);
void	letters_to_img(t_data *data, int key, char *img);
void	highlight_to_img(t_data *data, int key, char *img);

/*------------------------Parsing-------------------------*/

int				skip_whitespace(char *str, int i);
int				get_len(char *str, int i);
void			check_key(t_data *data, char *key);
void			error_color(t_data *data, char *r, char *g, char *b);
int				get_len_array(char **arr);

#endif
