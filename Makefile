NAME			=	minishell
CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g
READLINE		=	-lreadline
SRCS			=	main.c
OBJS			= 	$(SRCS:%.c=%.o)

SRC_DIR			=	src

BUILTIN_DIR		=	$(SRC_DIR)/builtin
BUILTIN_A		=	builtin.a
BUILTIN			= 	$(BUILTIN_DIR)/$(BUILTIN_A)

ENV_CTRL_DIR	=	$(SRC_DIR)/environ_control
ENV_CTRL_A		=	environ_control.a
ENV_CTRL		= 	$(ENV_CTRL_DIR)/$(ENV_CTRL_A)

EXPANTION_DIR	=	$(SRC_DIR)/expansion
EXPANTION_A		=	expansion.a
EXPANTION		= 	$(EXPANTION_DIR)/$(EXPANTION_A)

PARSER_DIR		=	$(SRC_DIR)/parser
PARSER_A		=	parser.a
PARSER			= 	$(PARSER_DIR)/$(PARSER_A)

PIPEX_DIR		=	$(SRC_DIR)/pipex
PIPEX_A			=	pipex.a
PIPEX			= 	$(PIPEX_DIR)/$(PIPEX_A)

UTILS_DIR		=	$(SRC_DIR)/utils
UTILS_A			=	utils.a
UTILS			= 	$(UTILS_DIR)/$(UTILS_A)

GNL_DIR			=	$(SRC_DIR)/get_next_line
GNL_A			=	get_next_line.a
GNL				= 	$(GNL_DIR)/$(GNL_A)

LIBFT_DIR		=	$(SRC_DIR)/libft
LIBFT_A			=	libft.a
LIBFT			= 	$(LIBFT_DIR)/$(LIBFT_A)

$(NAME): $(OBJS) $(BUILTIN) $(EXPANTION) $(PARSER) $(PIPEX) $(ENV_CTRL) $(UTILS) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ $(READLINE)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(READLINE)

$(BUILTIN):
	$(MAKE) -C $(BUILTIN_DIR)

$(ENV_CTRL):
	$(MAKE) -C $(ENV_CTRL_DIR)

$(EXPANTION):
	$(MAKE) -C $(EXPANTION_DIR)

$(PARSER):
	$(MAKE) -C $(PARSER_DIR)

$(PIPEX):
	$(MAKE) -C $(PIPEX_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:	
		$(RM) $(OBJS) $(BUILTIN_DIR)/*.[oa] $(ENV_CTRL_DIR)/*.[oa] $(EXPANTION)/*.[oa] $(LIBFT_DIR)/*.[oa] $(PARSER_DIR)/*.[oa] $(UTILS_DIR)/*.[oa] $(GNL_DIR)/*.[oa] $(PIPEX_DIR)/*.[oa]

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
