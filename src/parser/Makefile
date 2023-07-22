NAME		=	parser.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
UTILS		=	../utils
SRCS		=	change_str_to_word_list.c \
				lexer.c \
				parser.c \
				create_tree.c \
				add_type.c \
				check_syntax_err_tree.c \
				check_syntax_err_words.c \
				$(UTILS)/utils_strdup.c \
				$(UTILS)/utils_free_tree.c \
				$(UTILS)/utils_free_word_list.c \
				$(UTILS)/utils_count.c \
				$(UTILS)/utils_is.c \
				$(UTILS)/print_fmt_err_syntax.c \
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
