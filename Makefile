TARGET			=	minishell
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

UTILS_DIR		=	$(SRC_DIR)/utils
UTILS_A			=	utils.a
UTILS			= 	$(UTILS_DIR)/$(UTILS_A)

LIBFT_DIR		=	$(SRC_DIR)/libft
LIBFT_A			=	libft.a
LIBFT			= 	$(LIBFT_DIR)/$(LIBFT_A)

$(TARGET): $(OBJS) $(BUILTIN) $(EXPANTION) $(PARSER) $(ENV_CTRL) $(UTILS) $(LIBFT)
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

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(TARGET)

clean:	
		$(RM) $(OBJS) $(BUILTIN_DIR)/*.[oa] $(ENV_CTRL_DIR)/*.[oa] $(EXPANTION)/*.[oa] $(LIBFT_DIR)/*.[oa] $(PARSER_DIR)/*.[oa] $(UTILS_DIR)/*.[oa]

fclean:	clean
		$(RM) $(TARGET)

re:		fclean all

.PHONY:	all clean fclean re
