RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m

NAME = cub3d

DEBUG = debug

LIBFT = libft/lib/libft.a

ifeq ($(shell uname), Linux)
	MLX_DIR = ./mlx_linux
	MLX_PATH = mlx_linux/libmlx.a
	MLX =  -L /usr/lib -lXext -lX11 -lm 
	MLX_OBJ = -I/usr/include -Imlx_linux -O3
else
	MLX_DIR = ./mlx
	MLX_PATH = mlx/libmlx.a
	MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit
	MLX_OBJ = -Imlx -c
endif

MLX_LIB = -L $(MLX_DIR) -lmlx 

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -g3 -finline-functions -fvectorize -fslp-vectorize -ffast-math -falign-functions -funroll-loops -fstrict-aliasing \
	 -fomit-frame-pointer -flto -Ofast -O1 -O2 -Os -O3 

RM = rm -rf

SRCS_DIR = src/
OBJS_DIR = obj/
DEBUG_DIR = debug/

SRCS =	src/main.c \
		src/window/create_window.c \
		src/key_hook/key_hook.c src/key_hook/rotate.c src/key_hook/movement.c src/key_hook/mouse.c src/key_hook/key_press.c src/key_hook/dispatch.c \
		src/raycasting/raycasting.c src/raycasting/draw.c src/raycasting/calcul.c \
		src/utils/clear_xpm.c src/utils/clear.c src/utils/exit.c src/utils/init.c src/utils/parsing.c src/utils/init_2.c src/utils/init_enemy.c src/utils/mlx.c src/utils/init_3.c \
		src/texture/wall.c \
		src/weapon/load_weapon.c src/weapon/shoot.c \
		src/monster/monster.c src/monster/damage.c src/monster/dying.c src/monster/draw.c \
		src/floor/floor.c \
		src/minimap/draw.c src/minimap/minimap.c src/minimap/check.c \
		src/parsing/check_arg.c src/parsing/check_map.c src/parsing/check.c src/parsing/color_2.c src/parsing/color.c src/parsing/data.c src/parsing/map.c src/parsing/parsing.c src/parsing/player.c src/parsing/readfile.c src/parsing/texture.c src/parsing/door.c src/parsing/assign_data.c src/parsing/load_xpm.c src/parsing/door_2.c \
		src/door/door.c \
		src/menu/menu.c src/menu/letters.c src/menu/change_control.c src/menu/hp_bar.c src/menu/create_sliders.c src/menu/mouse_controls.c src/menu/switch_menu.c src/menu/controls_menu.c src/menu/load_letters.c src/menu/load_highlight.c src/menu/sliders.c src/menu/mouse_sliders.c

OBJ = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

OBJD = $(SRCS:$(SRCS_DIR)%.c=$(DEBUG_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJ) Makefile
	#@make -C $(MLX_DIR)
	@export DYLD_LIBRARY_PATH=./mlx:$DYLD_LIBRARY_PATH
	@make -C libft
	@printf "                                              							   \r"
	@echo "\033[0;34m 														"
	@echo "\033[0;34m	██████╗  ██╗   ██╗ ██████╗    ██████╗  ██████╗ 		"
	@echo "\033[0;34m 	██╔════╝ ██║   ██║ ██╔══██╗   ╚════██╗ ██╔══██╗		"
	@echo "\033[0;34m	██║      ██║   ██║ ██████╔╝    █████╔╝ ██║  ██║		"
	@echo "\033[0;34m 	██║      ██║   ██║ ██╔══██╗    ╚═══██╗ ██║  ██║		"
	@echo "\033[0;34m 	╚██████╗ ╚██████╔╝ ██████╔╝   ██████╔╝ ██████╔╝		"
	@echo "\033[0;34m 	 ╚═════╝  ╚═════╝  ╚═════╝     ╚═════╝  ╚═════╝ 		"
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(LINK) -g $(MLX_LIB) $(MLX) -o $(NAME)
	@echo "$(BLUE)Cub3D executable created!$(NC)"

$(DEBUG) : $(OBJD)
	@make -C libft
	@$(CC) $(OBJD) $(CFLAGS) $(LIBFT) $(LINK) -fsanitize=address -g -o $(DEBUG)
	@echo "\033[0;34m	██████╗ ██╗   ██╗██████╗     ██████╗ ██████╗ 		"
	@echo "\033[0;34m 	██╔════╝██║   ██║██╔══██╗    ╚════██╗██╔══██╗		"
	@echo "\033[0;34m	██║     ██║   ██║██████╔╝     █████╔╝██║  ██║		"
	@echo "\033[0;34m 	██║     ██║   ██║██╔══██╗     ╚═══██╗██║  ██║		"
	@echo "\033[0;34m 	╚██████╗╚██████╔╝██████╔╝    ██████╔╝██████╔╝		"
	@echo "\033[0;34m 	╚═════╝ ╚═════╝ ╚═════╝     ╚═════╝ ╚═════╝ 		"
	@$(CC) $(OBJD) $(CFLAGS) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)Cub3D executable created!$(NC)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/parsing
	@mkdir -p $(OBJS_DIR)/utils
	@mkdir -p $(OBJS_DIR)/window
	@mkdir -p $(OBJS_DIR)/key_hook
	@mkdir -p $(OBJS_DIR)/menu
	@mkdir -p $(OBJS_DIR)/minimap
	@mkdir -p $(OBJS_DIR)/raycasting
	@mkdir -p $(OBJS_DIR)/draw
	@mkdir -p $(OBJS_DIR)/texture
	@mkdir -p $(OBJS_DIR)/weapon
	@mkdir -p $(OBJS_DIR)/monster
	@mkdir -p $(OBJS_DIR)/floor
	@mkdir -p $(OBJS_DIR)/door
	$(PROGRESS_BAR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(DEBUG_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(DEBUG_DIR)
	@mkdir -p $(DEBUG_DIR)/parsing
	@mkdir -p $(DEBUG_DIR)/utils
	@mkdir -p $(DEBUG_DIR)/window
	@mkdir -p $(DEBUG_DIR)/key_hook
	@mkdir -p $(DEBUG_DIR)/menu
	@mkdir -p $(DEBUG_DIR)/minimap
	@mkdir -p $(DEBUG_DIR)/raycasting
	@mkdir -p $(DEBUG_DIR)/draw
	@mkdir -p $(DEBUG_DIR)/texture
	@mkdir -p $(DEBUG_DIR)/weapon
	@mkdir -p $(DEBUG_DIR)/monster
	@$(CC) -g -fsanitize=address -o $@ -c $<

clean :
	@$(RM) obj/**/*.o
	@$(RM) obj_debug/**/*.o
	@$(RM) obj/main.o
	@$(RM) obj_debug/main.o
	@$(RM) -r obj
	@$(RM) -r obj_debug

fclean : clean
	@$(RM) lib/
	@$(RM) $(NAME)

re : fclean all
	@$(RM) $(DEBUG)