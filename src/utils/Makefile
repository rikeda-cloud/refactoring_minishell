NAME		=	utils.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
SRCS		=	get_env_position.c \
				hash.c \
				print_fmt_err_syntax.c \
				reverse_flag.c \
				utils_count.c \
				utils_free_hash_map.c \
				utils_free_tree.c \
				utils_free_word_list.c \
				utils_get.c \
				utils_ifs.c \
				utils_is.c \
				utils_new.c \
				utils_strdup.c
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
		$(RM) $(OBJS) $(LIBFT_DIR)/*.[oa] $(UTILS_DIR)/*.[oa]

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
