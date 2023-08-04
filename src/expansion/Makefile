NAME		=	expansion.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
ENV_DIR		=	../environ_control
SRCS		=	change_quote_mode.c \
				expansion.c \
				expansion_node.c \
				split_word_list_by_ifs.c \
				split_word_list_by_quote.c \
				trim_quote_and_cat.c \
				variable_expansion.c \
				utils_ifs.c \
				is_assignment_pattern.c \
				delete_null_word_node.c \
				delete_last_dallor.c \
				replace.c
OBJS		= 	$(SRCS:%.c=%.o)

LIBFT_DIR	=	../libft
LIBFT_A 	= 	libft.a
LIBFT 		= 	$(LIBFT_DIR)/$(LIBFT_A)

UTILS_DIR	=	../utils
UTILS_A 	= 	utils.a
UTILS		= 	$(UTILS_DIR)/$(UTILS_A)

PARSER_DIR	=	../parser
PARSER_A	=	parser.a
PARSER		= 	$(PARSER_DIR)/$(PARSER_A)

ENV_CTRL_DIR	=	../environ_control
ENV_CTRL_A		=	environ_control.a
ENV_CTRL		= 	$(ENV_CTRL_DIR)/$(ENV_CTRL_A)

$(NAME): $(OBJS) $(PARSER) $(ENV_CTRL) $(UTILS) $(LIBFT)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PARSER):
	$(MAKE) -C $(PARSER_DIR)

$(ENV_CTRL):
	$(MAKE) -C $(ENV_CTRL_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

all: $(NAME)

clean:	
		$(RM) *.o

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
