# -------------------------------- VARIABLES -----------------------------------

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf
AR = ar -rcs
MKDIR_P = mkdir -p
OBJS_DIR = .objs

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
		printf/ft_print_c.c printf/ft_printf.c printf/ft_print_n.c \
		printf/ft_print_p.c printf/ft_print_s.c printf/ft_print_u.c \
		printf/ft_print_x.c \
		gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c \
		ft_swap.c ft_strcmp.c ft_isspace.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# ---------------------------------- RULES -------------------------------------

all: $(NAME)

$(OBJS_DIR)/%.o: %.c | $(dir $@)
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR):
	@$(MKDIR_P) $(OBJS_DIR)

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
