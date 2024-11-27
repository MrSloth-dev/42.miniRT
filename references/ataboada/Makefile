# ---------------------------------- COLORS ------------------------------------

RED = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[1;35m
RESET = \033[0m

# --------------------------------- VARIABLES ----------------------------------

M_NAME		= miniRT
B_NAME		= miniRT_bonus

CC			= cc

CFLAGS		= -Werror -Wextra -Wall -O3 -pthread -g #-pg
MLX_FLAGS	= -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

RM			= rm -rf
MAKE		= make -s -C
MKDIR_P		= mkdir -p

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a

SRCS_DIR	= srcs
OBJS_DIR	= .objs

SRCS		= math/vector_operations_1 \
				math/vector_operations_2 \
				math/matrix_operations \
				math/matrix_transformations \
				math/matrix_aux \
				render/render \
				render/world_intersections \
				render/computations \
				render/shade_hit \
				render/lighting \
				render/optics \
				shapes/shapes \
				shapes/sphere \
				shapes/plane \
				shapes/cylinder \
				shapes/cone \
				shapes/cube \
				shapes/triangle \
				textures/xpm_textures \
				textures/pattern \
				textures/pattern_functions \
				utils/mlx_utils \
				utils/create_camera \
				utils/create_canvas \
				utils/create_intersection \
				utils/create_ray \
				utils/lst_utils \

MANDATORY	= main \
				parser/parser \
				parser/get_elements \
				parser/get_objects \
				parser/get_objects_utils \
				parser/parser_utils \
				mlx/mlx \
				mlx/mlx_update \
				$(SRCS)
				
BONUS		= main_bonus \
				parser_bonus/parser \
				parser_bonus/get_elements \
				parser_bonus/get_objects \
				parser_bonus/get_objects_utils \
				parser_bonus/parser_utils \
				render/render_bonus \
				mlx_bonus/ui_init_0 \
				mlx_bonus/ui_init_1 \
				mlx_bonus/ui_interactions_0 \
				mlx_bonus/ui_interactions_1 \
				mlx_bonus/mlx \
				mlx_bonus/mlx_hooks \
				mlx_bonus/mlx_update \
				mlx_bonus/mlx_update_elements \
				$(SRCS)

MANDATORY	:= $(MANDATORY:%=$(SRCS_DIR)/%.c)
M_OBJS		:= $(MANDATORY:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

BONUS		:= $(BONUS:%=$(SRCS_DIR)/%.c)
B_OBJS		:= $(BONUS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

INCLUDES	= -I/usr/include -Imlx -I ./includes

# ---------------------------------- RULES -------------------------------------

all: $(M_NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(dir $@)
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(M_NAME): $(M_OBJS)
	@printf "$(PURPLE) Compiling Libft\n$(RESET)"
	@$(MAKE) $(LIBFT_DIR)
	@printf "$(GREEN) Libft has been compiled\n"
	@printf "$(PURPLE) Compiling MiniLibX\n$(RESET)"
	@$(MAKE) $(MLX_DIR) > /dev/null 2>&1
	@printf "$(GREEN) MiniLibX has been compiled\n"
	@printf "$(PURPLE) Compiling miniRT\n$(RESET)"
	@$(CC) $(CFLAGS) $(M_OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(M_NAME) $(MLX_FLAGS)
	@printf "$(GREEN) miniRT has been compiled\n$(RESET)"

$(OBJS_DIR):
	@$(MKDIR_P) $(OBJS_DIR)

bonus: $(B_NAME)

$(B_NAME) : $(B_OBJS)
	@printf "$(PURPLE) Compiling Libft\n$(RESET)"
	@$(MAKE) $(LIBFT_DIR)
	@printf "$(GREEN) Libft has been compiled\n"
	@printf "$(PURPLE) Compiling MiniLibX\n$(RESET)"
	@$(MAKE) $(MLX_DIR) > /dev/null 2>&1
	@printf "$(GREEN) MiniLibX has been compiled\n"
	@printf "$(PURPLE) Compiling miniRT\n$(RESET)"
	@$(CC) $(CFLAGS) $(B_OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(B_NAME) $(MLX_FLAGS)
	@printf "$(GREEN) miniRT has been compiled\n$(RESET)"

clean:
	@$(MAKE) $(LIBFT_DIR) clean
	@$(MAKE) $(MLX_DIR) clean > /dev/null 2>&1
	@$(RM) $(OBJS_DIR)
	@printf "$(RED) Object files were deleted\n$(RESET)"

fclean: clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(RM) $(M_NAME)
	@$(RM) $(B_NAME)
	@printf "$(RED) miniRT was deleted\n$(RESET)"

re: fclean all

re_bonus: fclean bonus


.PHONY: all bonus clean fclean re re_bonus download mgmon bgmon valgrind

# --------------------------------- ADDITIONAL ---------------------------------

download:
	wget https://cdn.intra.42.fr/document/document/22621/minilibx-linux.tgz && \
	tar -xf minilibx-linux.tgz && rm -rf minilibx-linux.tgz

mgmon: all
	./$(M_NAME) scenes/mandatory/cylinders.rt
	gprof $(M_NAME) gmon.out > analysis.txt

bgmon: bonus
	./$(B_NAME) scenes/bonus/all.rt
	gprof $(B_NAME) gmon.out > analysis.txt

valgrind: bonus
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(B_NAME) scenes/all.rt
