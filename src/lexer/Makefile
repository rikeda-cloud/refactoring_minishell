NAME		=	lexer.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
UTILS		=	../utils
SRCS		=	change_str_to_words.c \
				lexical_analysis.c \
				add_token_type.c \
				$(UTILS)/utils_strdup.c \
				$(UTILS)/utils_count.c \
				$(UTILS)/utils_is.c \
				$(UTILS)/utils_del.c \
				check_not_close_quotation.c
OBJS		= 	$(SRCS:%.c=%.o)

LIBFT_DIR	=	../libft
LIBFT_A		=	libft.a
LIBFT		= 	$(LIBFT_DIR)/$(LIBFT_A)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:	
		$(RM) $(OBJS) $(LIBFT_DIR)/*.o

fclean:	clean
		$(RM) $(NAME) $(LIBFT)

re:		fclean all

.PHONY:	all clean fclean re
