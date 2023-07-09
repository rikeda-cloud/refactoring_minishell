NAME		=	minishell
CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
READLINE	=	-lreadline
SRCS		=	main.c
OBJS		= 	$(SRCS:%.c=%.o)
OBJ_DIR		=	../../obj/

LIBFT_DIR	=	../libft
LIBFT_A		=	libft.a
LIBFT		= 	$(OBJ_DIR)$(LIBFT_A)

GNL_DIR		=	../get_next_line
GNL_A		=	get_next_line.a
GNL			=	$(OBJ_DIR)$(GNL_A)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $@ $(READLINE)
	mv $(OBJS) $(NAME) $(OBJ_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(READLINE) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

all: $(NAME)

clean:	
		$(RM) $(OBJ_DIR)*.o

fclean:	clean
		$(RM) $(OBJ_DIR)$(NAME) 

re:		fclean all

.PHONY:	all clean fclean re
