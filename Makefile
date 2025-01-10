################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = miniRT
NAME_BONUS = minirt
CC = cc
CFLAGS = -Iincludes -g
EFLAGS = -Wall -Wextra -Werror
MFLAGS = -fsanitize=undefined -fno-omit-frame-pointer -fsanitize=memory
MLXFLAGS = -O3 -ffast-math -march=native -Lminilibx-linux -lm -lmlx -lX11 -lXext -g
STEP ?= 2
DEBUG ?= 0

CLR_RMV = \033[0m
RED	    = \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
RM	    = rm -rf

################################################################################
#                                    VALGRIND                                  #
################################################################################
LEAKS_LOG              = ./leaks.log
READLINE_SUPP          = readline.supp
VALGRINDFLAGS          = --tool=memcheck -q --leak-check=full \
                         --show-leak-kinds=all --track-origins=yes \
                         --track-fds=yes --show-below-main=no \



################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

vpath %.h includes
vpath %.c src

HEADER = minirt.h ft_printf.h
MAIN = src/main.c
MAIN_BONUS = src/main_bonus.c
PRINTDIR = ./includes/ft_printf/
PRINTFT = ./includes/ft_printf/libftprintf.a
GNLDIR = ./includes/get_next_line/
GNLFT = ./includes/get_next_line/get_next_line.c
GNLUFT = ./includes/get_next_line/get_next_line_utils.c
GNL  = $(GNLFT) $(GNLUFT)

00_HELPDIR = src/00_help

00_HELP = $(00_HELPDIR)/ft_lstadd_front.c \
	$(00_HELPDIR)/ft_lstsize.c \
	$(00_HELPDIR)/ft_lstadd_back.c \
	$(00_HELPDIR)/ft_lstnew.c \
	$(00_HELPDIR)/assert.c \
	$(00_HELPDIR)/ft_free.c

00_INITDIR = src/00_init
00_INIT = $(00_INITDIR)/_06_085_1_create_material.c \
	$(00_INITDIR)/init_objects.c \
	$(00_INITDIR)/init_objects_fixed.c \
	$(00_INITDIR)/init.c

02_PARSEDIR = src/02_parse
02_PARSE = 	$(02_PARSEDIR)/02_syntax_helper.c \
	$(02_PARSEDIR)/06_value_checker.c \
	$(02_PARSEDIR)/01_syntax.c \
	$(02_PARSEDIR)/01_syntax_help.c \
	$(02_PARSEDIR)/04_create_objects.c \
	$(02_PARSEDIR)/03_create_objects.c \
	$(02_PARSEDIR)/05_value_getter.c \
	$(02_PARSEDIR)/00_parse.c

88_UTILSDIR = src/88_utils
88_UTILS = $(88_UTILSDIR)/00_set_tuple.c \
	$(88_UTILSDIR)/iter.c

91_MLXDIR = src/91_mlx
91_MLX = $(91_MLXDIR)/00_mlx_init.c \
	$(91_MLXDIR)/01_pixel_put.c \
	$(91_MLXDIR)/91_free_mlx.c

80_EVENTSDIR = src/80_events
80_EVENTS = $(80_EVENTSDIR)/03_key_release.c \
	$(80_EVENTSDIR)/05_mouse_handler_release.c \
	$(80_EVENTSDIR)/07_close_handler.c \
	$(80_EVENTSDIR)/11_make_disco.c \
	$(80_EVENTSDIR)/12_change_color_disco.c \
	$(80_EVENTSDIR)/21_light_transform.c \
	$(80_EVENTSDIR)/22_change_light_position.c \
	$(80_EVENTSDIR)/23_change_light_color.c \
	$(80_EVENTSDIR)/31_change_resolution.c \
	$(80_EVENTSDIR)/42_change_object_color.c \
	$(80_EVENTSDIR)/01_menu.c \
	$(80_EVENTSDIR)/02_key_handler.c \
	$(80_EVENTSDIR)/04_mouse_handler.c \
	$(80_EVENTSDIR)/06_mouse_motion.c \
	$(80_EVENTSDIR)/43_select_transform.c \
	$(80_EVENTSDIR)/52_transform_camera_key.c \
	$(80_EVENTSDIR)/41_change_obj_properties.c \
	$(80_EVENTSDIR)/61_select_object.c \
	$(80_EVENTSDIR)/62_clear_select.c \
	$(80_EVENTSDIR)/51_camera_transform.c

11_CAMERADIR = src/11_camera
11_CAMERA = $(11_CAMERADIR)/_07_101_create_world_camera.c \
	$(11_CAMERADIR)/_07_100_view_transformation.c

12_RENDERDIR = src/12_render
12_RENDER = $(12_RENDERDIR)/_07_104_ray_for_pixel.c \
	$(12_RENDERDIR)/_08_101_is_shadowed.c \
	$(12_RENDERDIR)/_02_000_color.c \
	$(12_RENDERDIR)/_06_088_lighting.c \
	$(12_RENDERDIR)/_07_093_intersect_world.c \
	$(12_RENDERDIR)/_07_097_color_at.c \
	$(12_RENDERDIR)/_09_112_normal_at.c \
	$(12_RENDERDIR)/98_draw_axis.c \
	$(12_RENDERDIR)/98_draw_axis_utils.c \
	$(12_RENDERDIR)/99_get_transf_obj.c \
	$(12_RENDERDIR)/_07_104_render.c \
	$(12_RENDERDIR)/_07_094_prepare_comp.c

13_INTERSECTIONSDIR = src/13_intersections
13_INTERSECTIONS = 	$(13_INTERSECTIONSDIR)/_09_119_intersection_plane.c \
	$(13_INTERSECTIONSDIR)/_05_062_intersection_sphere.c \
	$(13_INTERSECTIONSDIR)/_05_065_hit_inter.c \
	$(13_INTERSECTIONSDIR)/_05_065_lstadd_sort_inter_malloc.c \
	$(13_INTERSECTIONSDIR)/_13_177_intersection_cyl.c

71_TUPLE_OPERDIR = src/71_tuple_oper
71_TUPLE_OPER = 	$(71_TUPLE_OPERDIR)/_01_000_tuple_init.c \
	$(71_TUPLE_OPERDIR)/_01_005_add_tuple.c \
	$(71_TUPLE_OPERDIR)/_01_005_is_float_equal.c \
	$(71_TUPLE_OPERDIR)/_01_005_is_tuples_equal.c \
	$(71_TUPLE_OPERDIR)/_01_005_operator.c \
	$(71_TUPLE_OPERDIR)/_01_006_sub_tuple.c \
	$(71_TUPLE_OPERDIR)/_01_007_neg_tuple.c \
	$(71_TUPLE_OPERDIR)/_01_007_scalar_tuple.c \
	$(71_TUPLE_OPERDIR)/_01_008_magn_tuple.c \
	$(71_TUPLE_OPERDIR)/_01_010_norm_vector.c \
	$(71_TUPLE_OPERDIR)/_01_011_crossprod_vector.c \
	$(71_TUPLE_OPERDIR)/_01_010_dotprod_vector.c

72_MATRIX_TRANSFDIR = src/72_matrix_transf
72_MATRIX_TRANSF = 	$(72_MATRIX_TRANSFDIR)/_03_000_print_matrix.c \
	$(72_MATRIX_TRANSFDIR)/_03_026_create_matrix.c \
	$(72_MATRIX_TRANSFDIR)/_03_026_set_matrix_values.c \
	$(72_MATRIX_TRANSFDIR)/_03_027_are_matrixes_equal.c \
	$(72_MATRIX_TRANSFDIR)/_03_030_matrix_mult.c \
	$(72_MATRIX_TRANSFDIR)/_03_030_mult_matrix_tuple.c \
	$(72_MATRIX_TRANSFDIR)/_03_032_transpose_matrix.c \
	$(72_MATRIX_TRANSFDIR)/_03_034_determinant.c \
	$(72_MATRIX_TRANSFDIR)/_03_035_1_submatrix.c \
	$(72_MATRIX_TRANSFDIR)/_03_035_2_minor.c \
	$(72_MATRIX_TRANSFDIR)/_03_036_cofactor.c \
	$(72_MATRIX_TRANSFDIR)/_03_039_invert_matrix.c \
	$(72_MATRIX_TRANSFDIR)/_04_044_translation_matrix.c \
	$(72_MATRIX_TRANSFDIR)/_04_045_translate.c \
	$(72_MATRIX_TRANSFDIR)/_04_046_scale.c \
	$(72_MATRIX_TRANSFDIR)/_04_046_scale_matrix.c \
	$(72_MATRIX_TRANSFDIR)/_04_047_rotation.c \
	$(72_MATRIX_TRANSFDIR)/_04_047_rotation_matrix.c

73_RAYDIR = src/73_ray
73_RAY = 	$(73_RAYDIR)/_05_058_create_ray.c \
	$(73_RAYDIR)/_05_058_distance_ray.c \
	$(73_RAYDIR)/_05_069_1_translate_ray.c \
	$(73_RAYDIR)/_05_069_2_scale_ray.c \
	$(73_RAYDIR)/_05_069_3_set_transf_ray.c \
	$(73_RAYDIR)/_06_083_reflect.c

SRCS = $(00_HELP) $(00_INIT) $(01_OPER) $(02_PARSE) $(88_UTILS) $(91_MLX) \
       $(80_EVENTS) $(11_CAMERA) $(12_RENDER) $(13_INTERSECTIONS) \
       $(71_TUPLE_OPER) $(72_MATRIX_TRANSF) $(73_RAY)

SRCS_BONUS = src/99_bonus/_07_104_render_bonus.c

INCLUDES = $(MLXFLAGS) $(GNL) $(PRINTFT)

OBJ_DIR = obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

OBJS_BONUS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS) $(SRCS_BONUS))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(EFLAGS) -D STEP=$(STEP) -D DEBUG=$(DEBUG) -c $< -o $@


################################################################################
#                                  Makefile  rules                             #
################################################################################

.PHONY: all
all: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(HEADER)
	@printf "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)libft$(CLR_RMV)...\n"
	@printf "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)...\n"
	@make -C $(PRINTDIR) -s
	@make -C $(LIBX_DIR) -s
	@$(CC) $(MAIN_BONUS)  $(CFLAGS) $(EFLAGS) -D STEP=$(STEP) $(OBJS_BONUS) $(INCLUDES) -o $(NAME_BONUS)
	@printf "$(GREEN)$(NAME) created$(CLR_RMV) ✅\n"

.PHONY: mandatory
mandatory: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@printf "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)libft$(CLR_RMV)...\n"
	@printf "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)...\n"
	@make -C $(PRINTDIR) -s
	@make -C $(LIBX_DIR) -s
	@$(CC) $(MAIN)  $(CFLAGS) $(EFLAGS) -D STEP=$(STEP) $(OBJS) $(INCLUDES) -o $(NAME)
	@printf "$(GREEN)$(NAME) created$(CLR_RMV) ✅\n"


LIBX_DIR = minilibx-linux
LIBX_HEADER = $(LIBX_DIR)/mlx.h

.PHONY: libx
.SILENT: $(LIBX_DIR)
$(LIBX_DIR) :
	@wget -q https://cdn.intra.42.fr/document/document/29544/minilibx-linux.tgz && \
	tar xf minilibx-linux.tgz && \
	rm -fr minilibx-linux.tgz

libx : $(LIBX_DIR)

.PHONY: va
va : fclean $(OBJS) $(HEADER)
	@printf "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)libft$(CLR_RMV)...\n"
	@printf "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)...\n"
	@make -C $(PRINTDIR) -s
	@make -C $(LIBX_DIR) -s
	@$(CC) $(MAIN) $(CFLAGS) $(EFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) 
	@echo -n valgrind $(VALGRINDFLAGS) ./$(NAME) scenes/ ; read args; valgrind $(VALGRINDFLAGS) ./$(NAME) scenes/$$args

.PHONY: clean
clean:
	@ $(RM) -f $(OBJS) $(OBJS_BONUS)
	@make clean -C $(PRINTDIR) -s
	@ printf "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✅\n"

.PHONY: fclean
fclean: clean
	@ $(RM) $(OBJ_DIR) $(NAME) $(NAME_BONUS)
	@make fclean -C $(PRINTDIR) -s
	@make clean -C $(LIBX_DIR) -s
	@printf "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✅\n"

.PHONY: re
re : fclean all

.SILENT: re all clean fclean
