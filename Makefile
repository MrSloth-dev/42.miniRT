################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = minirt
CC = cc
CFLAGS = -Iincludes -g
EFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Ofast -Lminilibx-linux -lm -lmlx -lX11 -lXext

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

OPER =	$(OPERDIR)/00_oper.c \
	$(OPERDIR)/01_matrix.c

PARSE = $(PARSEDIR)/00_parse.c \
	$(PARSEDIR)/01_syntax.c \
	$(PARSEDIR)/02_syntax_helper.c \
	$(PARSEDIR)/03_create_objects.c

MLX = $(MLXDIR)/00_mlx_init.c \
	$(MLXDIR)/01_pixel_put.c \
	$(MLXDIR)/91_free_mlx.c \
	$(MLXDIR)/events.c

SRCS =	$(HELPER) $(INIT) $(OPER) $(PARSE) $(MLX)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(EFLAGS) -c $< -o $@

################################################################################
#                                  Makefile  rules                             #
################################################################################

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)libft$(CLR_RMV)..."
	@echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@make -C $(PRINTDIR) -s
	@make -C ./minilibx-linux -s
	@$(CC) $(CFLAGS) $(EFLAGS) $(OBJS) $(MLXFLAGS) $(GNL) $(PRINTFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) created[0m ✅"


LIBX_DIR = minilibx-linux
.PHONY: libx
$(LIBX_DIR) :
	wget https://cdn.intra.42.fr/document/document/22621/minilibx-linux.tgz
	tar xf minilibx-linux.tgz
	rm -fr minilibx-linux.tgz

libx : $(LIBX_DIR)

.PHONY: norm
norm:
	@norminette | grep -E 'Error:|rror!'

.PHONY: gdb
gdb : re
	tmux set-option remain-on-exit off
	tmux new-window  -n Gdb
	tmux send-keys 'gdbtui ./minirt' C-m Escape
	tmux split-window -h -l 30
	tmux send-keys -t Gdb.2 'nvim .gdbinit' C-m
	tmux select-pane -t Gdb.1


.PHONY: vgdb
vgdb : re
	tmux new-window  -n vGdb
	tmux send-keys 'valgrind -q --vgdb-error=0 ./minirt input.rt' C-m Escape
	tmux split-window -h
	tmux send-keys -t Gdb.2 'gdbtui ./minirt' C-m
	tmux select-pane -t vGdb.1

.PHONY: va
va : re
	valgrind $(VALGRINDFLAGS) ./$(NAME) input.rt

.PHONY: clean
clean:
	@ $(RM) -f $(OBJS)
	@make clean -C $(PRINTDIR) -s
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✅"


.PHONY: fclean
fclean: clean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C $(PRINTDIR) -s
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✅"


.PHONY: re
re : fclean all

.SILENT: re all clean fclean

