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
VALGRINDFLAGS          = -s --suppressions=$(READLINE_SUPP) \
			 --tool=memcheck -q --leak-check=full \
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

HELPDIR = src/00_help
INITDIR = src/00_init
OPERDIR = src/01_oper

HELPER =$(HELPDIR)/assert.c
INIT =	$(INITDIR)/main.c \
	$(INITDIR)/events.c	

OPER =	$(OPERDIR)/00_oper.c \
	$(OPERDIR)/01_matrix.c



SRCS =	$(HELPER) $(INIT) $(OPER)

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
	@make -C ./minilibx-linux -s
	@make -C $(PRINTDIR) -s
	@$(CC) $(CFLAGS) $(EFLAGS) $(OBJS) $(PRINTFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created[0m ✅"


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
	tmux send-keys 'valgrind -q --vgdb-error=0 ./minishell' C-m Escape
	tmux split-window -h
	tmux send-keys -t Gdb.2 'gdbtui ./minishell' C-m
	tmux select-pane -t vGdb.1


.PHONY: clean
clean:
	@ $(RM) -f $(OBJS)
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✅"


.PHONY: fclean
fclean: clean
	@ $(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✅"


.PHONY: re
re : fclean all

.SILENT: re all clean fclean

