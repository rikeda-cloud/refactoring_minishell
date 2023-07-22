NAME		=	expansion.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
UTILS_DIR	=	../utils
LIBFT_DIR	=	../libft
ENV_DIR		=	../environ_control
SRCS		=	$(ENV_DIR)/insert_env_to_map.c \
				$(ENV_DIR)/insert_new_env.c \
				$(ENV_DIR)/change_env_to_hash_map.c \
				$(ENV_DIR)/select_env.c \
				$(ENV_DIR)/update_env.c \
				$(ENV_DIR)/delete_env.c \
				$(LIBFT_DIR)/ft_strncmp.c \
				$(LIBFT_DIR)/ft_strcat.c \
				$(UTILS_DIR)/hash.c \
				$(UTILS_DIR)/utils_strdup.c \
				$(UTILS_DIR)/utils_count.c \
				$(UTILS_DIR)/utils_get.c \
				$(UTILS_DIR)/utils_is.c \
				$(UTILS_DIR)/utils_free_tree.c \
				$(UTILS_DIR)/utils_free_word_list.c \
				$(UTILS_DIR)/utils_new.c \
				$(UTILS_DIR)/reverse_flag.c \
				ifs_func.c \
				change_quote_mode.c \
				get_env_position.c \
				expansion.c \
				expansion_tree.c \
				split_word_list_by_ifs.c \
				split_word_list_by_quote.c \
				trim_quote_and_cat.c \
				variable_expansion.c \
				replace.c
OBJS		= 	$(SRCS:%.c=%.o)

LIBFT_A 	= 	libft.a
LIBFT 		= 	$(LIBFT_DIR)/$(LIBFT_A)

LEXER_DIR	=	../lexer
LEXER_A		=	lexer.a
LEXER		= 	$(LEXER_DIR)/$(LEXER_A)

PARSER_DIR	=	../parser
PARSER_A	=	parser.a
PARSER		= 	$(PARSER_DIR)/$(PARSER_A)

# $(NAME): $(OBJS) $(LIBFT) $(LEXER) $(PARSER)
$(NAME): $(OBJS) $(PARSER)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# $(LEXER):
# 	$(MAKE) -C $(LEXER_DIR)

$(PARSER):
	$(MAKE) -C $(PARSER_DIR)

all: $(NAME)

clean:	
		$(RM) $(OBJS) $(PARSER_DIR)/*.o 
		# $(RM) $(OBJS) $(LIBFT_DIR)/*.o $(PARSER_DIR)/*.o $(LEXER_DIR)/*.o

fclean:	clean
		$(RM) $(NAME) $(PARSER) 
		# $(RM) $(NAME) $(LIBFT) $(LEXER) $(PARSER) 

re:		fclean all

.PHONY:	all clean fclean re
