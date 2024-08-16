RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m

NAME = cub3d

LIBFT = libft/lib/libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS_DIR = src/
OBJS_DIR = obj/

SRCS =	src/main.c \
		src/parsing/check_arg.c src/parsing/parsing.c src/parsing/readfile.c \
		src/utils/utils_exit.c src/utils/init.c

OBJ = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

OBJD = $(SRCS:$(SRCS_DIR)%.c=$(DEBUG_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@printf "                                              							   \r"
	@echo "\033[0;34m 														"
	@echo "\033[0;34m	██████╗ ██╗   ██╗██████╗     ██████╗ ██████╗ 		"
	@echo "\033[0;34m 	██╔════╝██║   ██║██╔══██╗    ╚════██╗██╔══██╗		"
	@echo "\033[0;34m	██║     ██║   ██║██████╔╝     █████╔╝██║  ██║		"
	@echo "\033[0;34m 	██║     ██║   ██║██╔══██╗     ╚═══██╗██║  ██║		"
	@echo "\033[0;34m 	╚██████╗╚██████╔╝██████╔╝    ██████╔╝██████╔╝		"
	@echo "\033[0;34m 	╚═════╝ ╚═════╝ ╚═════╝     ╚═════╝ ╚═════╝ 		"
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(LINK) -o $(NAME)
	@echo "$(BLUE)Cub3D executable created!$(NC)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/parsing
	@mkdir -p $(OBJS_DIR)/utils
	$(PROGRESS_BAR)
	@$(CC) $(CFLAGS) -o $@ -c $<

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