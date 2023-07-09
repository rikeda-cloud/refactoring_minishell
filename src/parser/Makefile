NAME		=	parser.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
LIBFT_DIR	=	../libft
UTILS		=	../utils
SRCS		=	$(UTILS)/utils_strdup.c \
				$(UTILS)/utils_count.c \
				$(UTILS)/utils_is.c \
				$(UTILS)/utils_is_2.c \
				$(UTILS)/utils_del.c \
				$(UTILS)/utils_check.c \
				create_tree.c
OBJS		= 	$(SRCS:%.c=%.o)

LIBFT_DIR	=	../libft
LIBFT_A		=	libft.a
LIBFT		= 	$(LIBFT_DIR)/$(LIBFT_A)

LEXER_DIR	=	../lexer
LEXER_A		=	lexer.a
LEXER		= 	$(LEXER_DIR)/$(LEXER_A)

$(NAME): $(OBJS) $(LIBFT) $(LEXER)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LEXER):
	$(MAKE) -C $(LEXER_DIR)

all: $(NAME)

clean:	
		$(RM) $(OBJS) $(LIBFT_DIR)/*.o $(LEXER_DIR)/*.o

fclean:	clean
		$(RM) $(NAME) $(LIBFT) $(LEXER)

re:		fclean all

.PHONY:	all clean fclean re
