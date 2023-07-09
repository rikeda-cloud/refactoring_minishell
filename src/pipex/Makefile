NAME		=	pipex
CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	child.c \
				function_error.c \
				heredoc.c \
				libft_error.c \
				main.c \
				no_pipe.c \
				parents.c \
				path_check.c \
				pipex.c
OBJS		= 	$(SRCS:%.c=%.o)

LIBFT_DIR	=	../libft
LIBFT_A		=	libft.a
LIBFT		= 	$(LIBFT_DIR)/$(LIBFT_A)

GNL_DIR		=	../get_next_line
GNL_A		=	get_next_line.a
GNL			=	$(GNL_DIR)/$(GNL_A)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

all: $(NAME)

bonus: $(NAME)

clean:	
		$(RM) $(OBJS) $(LIBFT_DIR)/*.o $(GNL_DIR)/*.o

fclean:	clean
		$(RM) $(NAME) $(LIBFT) $(GNL)

re:		fclean all

.PHONY:	all clean fclean re
