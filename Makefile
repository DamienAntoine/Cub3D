NAME = Cub3D
CFLAGS = -Wextra -Wall -Werror
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =	./srcs/main.c
GETNEXTLINE := includes/get_next_line/*.c
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
MLX_LIB = mlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@echo Compiling $< to $@
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(MLX_LIB) $(OBJS)
	@echo "$(YELLOW)Compiling so_long $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(GETNEXTLINE) $(MLX_FLAGS) -L./includes -lftprintf -o $(NAME)
	@echo "$(GREEN)so_long Compiled $(DEF_COLOR)"

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	@if [ -d "mlx" ]; then \
	make clean -C mlx/; \
	rm -rf mlx/; \
	fi
#	@make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
