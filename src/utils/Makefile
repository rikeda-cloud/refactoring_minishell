NAME		=	utils.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
SRCS		=	hash.c \
				signal.c \
				print_err.c \
				reverse_flag.c \
				get_env_position.c \
				utils_count.c \
				utils_free_char_list.c \
				utils_free_hash_map.c \
				utils_free_tree.c \
				utils_free_word_list.c \
				utils_free_all_data.c \
				utils_get.c \
				utils_is_assignment.c \
				utils_is_do_not_word_split_pattern.c \
				utils_is_only.c \
				utils_is_other.c \
				utils_is_quote.c \
				utils_is_space.c \
				utils_is_type.c \
				utils_new.c \
				utils_append.c \
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
