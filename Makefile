################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = miniRT
CC = cc
CFLAGS = -Iincludes -g
EFLAGS = -Wall -Wextra -Werror 
MLXFLAGS = -O3 -ffast-math -march=native -Lminilibx-linux -lm -lmlx -lX11 -lXext -g

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
PRINTDIR = ./includes/ft_printf/
PRINTFT = ./includes/ft_printf/libftprintf.a
GNLDIR = ./includes/get_next_line/
GNLFT = ./includes/get_next_line/get_next_line.c
GNLUFT = ./includes/get_next_line/get_next_line_utils.c
GNL  = $(GNLFT) $(GNLUFT)

HELPDIR = src/00_help
INITDIR = src/00_init
OPERDIR = src/01_oper
PARSEDIR = src/02_parse
MLXDIR = src/91_mlx

HELPER =$(HELPDIR)/assert.c \
	$(HELPDIR)/ft_free.c

INIT =	$(INITDIR)/main.c \
	$(INITDIR)/init.c \
	$(INITDIR)/init_objects.c

OPER =	$(wildcard $(OPERDIR)/*.c)

PARSE = $(PARSEDIR)/00_parse.c \
	$(PARSEDIR)/01_syntax.c \
	$(PARSEDIR)/02_syntax_helper.c \
	$(PARSEDIR)/03_create_objects.c

MLX = $(MLXDIR)/00_mlx_init.c \
	$(MLXDIR)/01_pixel_put.c \
	$(MLXDIR)/11_events.c \
	$(MLXDIR)/91_free_mlx.c \

# SRCS =	$(HELPER) $(INIT) $(OPER) $(PARSE) $(MLX)
SRCS =	$(wildcard src/**/**.c) $(wildcard src/**/**/**.c) 
INCLUDES = $(MLXFLAGS) $(GNL) $(PRINTFT)

OBJ_DIR = obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(EFLAGS) -c $< -o $@


################################################################################
#                                  Makefile  rules                             #
################################################################################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@printf "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)libft$(CLR_RMV)...\n"
	@printf "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)...\n"
	@make -C $(PRINTDIR) -s
	@make -C $(LIBX_DIR) -s
	@$(CC) $(MAIN) $(CFLAGS) $(EFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) -DDEBUG=0
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

p :
	./parser_testing/parser_testing.sh
.PHONY: norm
norm:
	@norminette | grep -E 'Error:|rror!'

.PHONY: gdb
gdb : re
	@tmux set-option remain-on-exit off
	@tmux new-window  -n Gdb
	@tmux send-keys 'gdbtui ./minirt' C-m Escape
	@tmux split-window -h -l 30
	@tmux send-keys -t Gdb.2 'nvim .gdbinit' C-m
	@tmux select-pane -t Gdb.1


.PHONY: vgdb
vgdb :
	@tmux new-window  -n vGdb
	@tmux send-keys 'valgrind -q --vgdb-error=0 ./minirt_te teste.rt' C-m Escape
	@tmux split-window -h
	@tmux send-keys -t Gdb.2 'gdbtui ./minirt' C-m
	@tmux select-pane -t vGdb.1

.PHONY: va
va : re
	valgrind $(VALGRINDFLAGS) ./$(NAME) teste.rt

.PHONY: clean
clean:
	@ $(RM) -f $(OBJS)
	@make clean -C $(PRINTDIR) -s
	@ printf "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✅\n"


.PHONY: fclean
fclean: clean
	@ $(RM) $(OBJ_DIR) $(NAME)
	@make fclean -C $(PRINTDIR) -s
	@printf "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✅\n"

.PHONY: re
re : fclean all

.PHONY: te
te : re
	./$(NAME) teste.rt

.SILENT: re all clean fclean

