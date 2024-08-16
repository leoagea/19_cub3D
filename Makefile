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

SRCS =	src/main.c

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
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(LINK) -g -fsanitize=address  -o $(NAME)
	@echo "$(BLUE)Cub3D executable created!$(NC)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/builtins
	@mkdir -p $(OBJS_DIR)/builtins/export
	@mkdir -p $(OBJS_DIR)/builtins/cd
	@mkdir -p $(OBJS_DIR)/signals
	@mkdir -p $(OBJS_DIR)/lexer
	@mkdir -p $(OBJS_DIR)/exec
	@mkdir -p $(OBJS_DIR)/parser
	@mkdir -p $(OBJS_DIR)/expander
	@mkdir -p $(OBJS_DIR)/utils
	$(PROGRESS_BAR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(DEBUG_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(DEBUG_DIR)
	@mkdir -p $(DEBUG_DIR)/builtins
	@mkdir -p $(DEBUG_DIR)/builtins/export
	@mkdir -p $(DEBUG_DIR)/builtins/cd
	@mkdir -p $(DEBUG_DIR)/signals
	@mkdir -p $(DEBUG_DIR)/lexer
	@mkdir -p $(DEBUG_DIR)/exec
	@mkdir -p $(DEBUG_DIR)/parser
	@mkdir -p $(DEBUG_DIR)/expander
	@mkdir -p $(DEBUG_DIR)/utils
	@$(CC) -o $@ -c $<

clean :
	@make clean -C libft
	@$(RM) obj/**/*.o
	@$(RM) obj_debug/**/*.o
	@$(RM) obj/minishell.o
	@$(RM) -r obj

fclean : clean
	@make fclean -C libft
	@$(RM) lib/
	@$(RM) $(NAME)

re : fclean all
	@$(RM) $(DEBUG)