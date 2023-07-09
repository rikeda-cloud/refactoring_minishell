NAME	=	get_next_line.a
AR		=	ar rcs
CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	get_next_line.c \
			get_next_line_utils.c
OBJS	= 	$(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:	
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME) 

re:		fclean all

.PHONY:	all clean fclean re
