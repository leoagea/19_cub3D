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
	MLX =  -L /usr/lib -lXext -lX11 -lm -lz 
	MLX_OBJ = -I/usr/include -Imlx_linux -O3
else
	MLX_DIR = ./mlx
	MLX_PATH = mlx/libmlx.a	
	MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit
	MLX_OBJ = -Imlx -c
endif

MLX_LIB = -L $(MLX_DIR) -lmlx

CC = cc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS_DIR = src/
OBJS_DIR = obj/
DEBUG_DIR = debug/

SRCS =	src/main.c \
		src/parsing/check_arg.c src/parsing/parsing.c src/parsing/readfile.c \
		src/utils/utils_exit.c src/utils/init.c \
		src/window/create_window.c \

OBJ = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

OBJD = $(SRCS:$(SRCS_DIR)%.c=$(DEBUG_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(MLX_DIR)
	@make -C libft
	@printf "                                              							   \r"
	@echo "\033[0;34m 														"
	@echo "\033[0;34m	██████╗  ██╗   ██╗ ██████╗    ██████╗  ██████╗ 		"
	@echo "\033[0;34m 	██╔════╝ ██║   ██║ ██╔══██╗   ╚════██╗ ██╔══██╗		"
	@echo "\033[0;34m	██║      ██║   ██║ ██████╔╝    █████╔╝ ██║  ██║		"
	@echo "\033[0;34m 	██║      ██║   ██║ ██╔══██╗    ╚═══██╗ ██║  ██║		"
	@echo "\033[0;34m 	╚██████╗ ╚██████╔╝ ██████╔╝   ██████╔╝ ██████╔╝		"
	@echo "\033[0;34m 	 ╚═════╝  ╚═════╝  ╚═════╝     ╚═════╝  ╚═════╝ 		"
	@$(CC) -O3 $(OBJ) $(CFLAGS) $(LIBFT) $(LINK) -g $(MLX_LIB) $(MLX) -o $(NAME)
	@echo "$(BLUE)Cub3D executable created!$(NC)"

$(DEBUG) : $(OBJ)
	@make -C libft
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(LINK) -fsanitize=address -g -o $(DEBUG)
	@echo "$(BLUE)Cub3D executable created!$(NC)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/parsing
	@mkdir -p $(OBJS_DIR)/utils
	@mkdir -p $(OBJS_DIR)/window
	$(PROGRESS_BAR)
	@$(CC) -O3 $(CFLAGS) -o $@ -c $<

$(DEBUG_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(DEBUG_DIR)
	@mkdir -p $(DEBUG_DIR)/parsing
	@mkdir -p $(DEBUG_DIR)/utils
	@$(CC) -g -fsanitize=address -o $@ -c $<

clean :
	@make clean -C libft
	@$(RM) obj/**/*.o
	@$(RM) obj_debug/**/*.o
	@$(RM) obj/main.o
	@$(RM) -r obj

fclean : clean
	@make fclean -C libft
	@$(RM) lib/
	@$(RM) $(NAME)

re : fclean all
	@$(RM) $(DEBUG)