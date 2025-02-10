NAME = cub3D
CFLAGS = -Wextra -Wall -Werror -g
SRCS_DIR = srcs
BONUS_DIR = bonus
OBJS_DIR = objs

# Library paths
LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	./srcs/main.c \
		./srcs/render.c \
		./srcs/parse_map_1.c \
		./srcs/parse_map_2.c \
		./srcs/check_map.c \
		./srcs/map_helpers.c \
		./srcs/movements.c \
		./srcs/rotate.c \
		./srcs/raycasting.c \
		./srcs/raycast_helpers.c \
		./srcs/free.c \
		./srcs/free_helpers.c \
		./srcs/error.c \
		./srcs/config_parser_1.c \
		./srcs/config_parser_2.c \
		./srcs/check_file.c \
		./srcs/texture_mapping.c \
		./srcs/pixel_put.c \
		./srcs/draw_walls.c \
		./srcs/valid_map_elem.c \
		./srcs/valid_plyr_pos.c

BONUS = ./bonus/main_bonus.c \
    	./bonus/render_bonus.c \
		./bonus/parse_map_1.c \
		./bonus/parse_map_2.c \
		./bonus/check_map.c \
		./bonus/map_helpers.c \
		./bonus/movements.c \
		./bonus/rotate.c \
		./bonus/raycasting.c \
		./bonus/raycast_helpers.c \
		./bonus/free.c \
		./bonus/free_helpers.c \
		./bonus/error.c \
		./bonus/config_parser_1.c \
		./bonus/config_parser_2.c \
		./bonus/check_file.c \
		./bonus/texture_mapping.c \
		./bonus/pixel_put.c \
		./bonus/draw_walls.c \
		./bonus/valid_map_elem.c \
		./bonus/valid_plyr_pos.c \
		./bonus/minimap.c

GETNEXTLINE := includes/GETNEXTLINE/*.c
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))
BONUS_OBJS = $(BONUS:./bonus/%.c=$(OBJS_DIR)/bonus/%.o)

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(LIBFT) $(MLX_LIB) $(OBJS_DIR) $(NAME)

bonus: $(LIBFT) $(MLX_LIB) $(BONUS_OBJS)
	@echo "$(YELLOW)Compiling Cub3D Bonus$(DEF_COLOR)"
	@$(CC) $(BONUS_OBJS) $(GETNEXTLINE) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o cub3D_bonus
	@echo "$(GREEN)Cub3D Bonus Compiled$(DEF_COLOR)"

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(DEF_COLOR)"
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@echo "$(BLUE)Compiling MLX...$(DEF_COLOR)"
	@make -C $(MLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJS_DIR)/bonus/%.o: bonus/%.c
	@mkdir -p $(@D)
	@echo "Compiling bonus $< to $@"
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling Cub3D $(DEF_COLOR)"
	@$(CC) $(OBJS) $(GETNEXTLINE) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Cub3D Compiled $(DEF_COLOR)"

clean:
	@echo "$(RED)Cleaning object files...$(DEF_COLOR)"
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@echo "$(RED)Cleaning executables...$(DEF_COLOR)"
	@rm -f $(NAME) cub3D_bonus
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
