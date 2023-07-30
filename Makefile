NAME			=	minishell
CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g
READLINE		=	-lreadline
SRC_DIR			=	src
BUILTIN_DIR		=	$(SRC_DIR)/builtin/
ENV_CTRL_DIR	=	$(SRC_DIR)/environ_control/
EXPANTION_DIR	=	$(SRC_DIR)/expansion/
PARSER_DIR		=	$(SRC_DIR)/parser/
PIPEX_DIR		=	$(SRC_DIR)/pipex/
UTILS_DIR		=	$(SRC_DIR)/utils/
GNL_DIR			=	$(SRC_DIR)/get_next_line/
LIBFT_DIR		=	$(SRC_DIR)/libft/
SRCS			=	main.c \
					$(BUILTIN_DIR)calc_exit_status.c \
					$(BUILTIN_DIR)cd.c \
					$(BUILTIN_DIR)echo.c \
					$(BUILTIN_DIR)exit.c \
					$(BUILTIN_DIR)export.c \
					$(BUILTIN_DIR)pwd.c \
					$(BUILTIN_DIR)unset.c \
					$(BUILTIN_DIR)fmt.c \
					$(BUILTIN_DIR)print_env.c \
					$(BUILTIN_DIR)utils_option.c \
					$(ENV_CTRL_DIR)change_environ_to_map.c \
					$(ENV_CTRL_DIR)change_map_to_environ.c \
					$(ENV_CTRL_DIR)delete_env.c \
					$(ENV_CTRL_DIR)insert_env_to_map.c \
					$(ENV_CTRL_DIR)insert_new_env.c \
					$(ENV_CTRL_DIR)select_env.c \
					$(ENV_CTRL_DIR)update_env.c \
					$(EXPANTION_DIR)change_quote_mode.c \
					$(EXPANTION_DIR)expansion.c \
					$(EXPANTION_DIR)expansion_node.c \
					$(EXPANTION_DIR)split_word_list_by_ifs.c \
					$(EXPANTION_DIR)split_word_list_by_quote.c \
					$(EXPANTION_DIR)trim_quote_and_cat.c \
					$(EXPANTION_DIR)variable_expansion.c \
					$(EXPANTION_DIR)utils_ifs.c \
					$(EXPANTION_DIR)del_null_word_node.c \
					$(EXPANTION_DIR)replace.c \
					$(GNL_DIR)get_next_line.c \
					$(GNL_DIR)get_next_line_utils.c \
					$(LIBFT_DIR)ft_atoi.c \
					$(LIBFT_DIR)ft_bzero.c \
					$(LIBFT_DIR)ft_calloc.c \
					$(LIBFT_DIR)ft_isalnum.c \
					$(LIBFT_DIR)ft_isalpha.c \
					$(LIBFT_DIR)ft_isalunder.c \
					$(LIBFT_DIR)ft_isascii.c \
					$(LIBFT_DIR)ft_isdigit.c \
					$(LIBFT_DIR)ft_islower.c \
					$(LIBFT_DIR)ft_isprint.c \
					$(LIBFT_DIR)ft_isupper.c \
					$(LIBFT_DIR)ft_itoa.c  \
					$(LIBFT_DIR)ft_memchr.c \
					$(LIBFT_DIR)ft_memcmp.c \
					$(LIBFT_DIR)ft_memcpy.c \
					$(LIBFT_DIR)ft_memmove.c \
					$(LIBFT_DIR)ft_memset.c \
					$(LIBFT_DIR)ft_putchar_fd.c \
					$(LIBFT_DIR)ft_putendl_fd.c \
					$(LIBFT_DIR)ft_putnbr_fd.c \
					$(LIBFT_DIR)ft_putstr_fd.c \
					$(LIBFT_DIR)ft_split.c \
					$(LIBFT_DIR)ft_strcat.c \
					$(LIBFT_DIR)ft_strchr.c \
					$(LIBFT_DIR)ft_strcmp.c \
					$(LIBFT_DIR)ft_strdup.c \
					$(LIBFT_DIR)ft_striteri.c \
					$(LIBFT_DIR)ft_strjoin.c \
					$(LIBFT_DIR)ft_strlcat.c \
					$(LIBFT_DIR)ft_strlcpy.c \
					$(LIBFT_DIR)ft_strlen.c \
					$(LIBFT_DIR)ft_strncmp.c \
					$(LIBFT_DIR)ft_strnstr.c \
					$(LIBFT_DIR)ft_strrchr.c \
					$(LIBFT_DIR)ft_strtrim.c \
					$(LIBFT_DIR)ft_substr.c \
					$(LIBFT_DIR)ft_tolower.c \
					$(LIBFT_DIR)ft_toupper.c \
					$(PARSER_DIR)change_str_to_word_list.c \
					$(PARSER_DIR)lexer.c \
					$(PARSER_DIR)parser.c \
					$(PARSER_DIR)create_tree.c \
					$(PARSER_DIR)add_type.c \
					$(PARSER_DIR)check_syntax_err_tree.c \
					$(PARSER_DIR)check_syntax_err_words.c \
					$(PARSER_DIR)check_not_close_quotation.c \
					$(UTILS_DIR)hash.c \
					$(UTILS_DIR)signal.c \
					$(UTILS_DIR)print_err.c \
					$(UTILS_DIR)reverse_flag.c \
					$(UTILS_DIR)get_env_position.c \
					$(UTILS_DIR)utils_count.c \
					$(UTILS_DIR)utils_free_char_list.c \
					$(UTILS_DIR)utils_free_hash_map.c \
					$(UTILS_DIR)utils_free_tree.c \
					$(UTILS_DIR)utils_free_word_list.c \
					$(UTILS_DIR)utils_free_all_data.c \
					$(UTILS_DIR)utils_get.c \
					$(UTILS_DIR)utils_is_assignment.c \
					$(UTILS_DIR)utils_is_do_not_word_split_pattern.c \
					$(UTILS_DIR)utils_is_only.c \
					$(UTILS_DIR)utils_is_other.c \
					$(UTILS_DIR)utils_is_quote.c \
					$(UTILS_DIR)utils_is_space.c \
					$(UTILS_DIR)utils_is_type.c \
					$(UTILS_DIR)utils_new.c \
					$(UTILS_DIR)utils_append.c \
					$(UTILS_DIR)utils_strdup.c \
					$(PIPEX_DIR)child.c \
					$(PIPEX_DIR)function_error.c \
					$(PIPEX_DIR)heredoc.c \
					$(PIPEX_DIR)libft_error.c \
					$(PIPEX_DIR)no_pipe.c \
					$(PIPEX_DIR)parents.c \
					$(PIPEX_DIR)path_check.c \
					$(PIPEX_DIR)pipex.c
OBJS			= 	$(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(READLINE)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(READLINE)

all: $(NAME)

clean:	
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
