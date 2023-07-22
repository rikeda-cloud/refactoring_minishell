NAME		=	builtin.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
ENV_DIR		=	../environ_control
SRCS		=	calc_exit_status.c \
				cd.c \
				echo.c \
				exit.c \
				export.c \
				pwd.c \
				unset.c \
				fmt.c \
				print_env.c \
				is_option_n.c
OBJS		= 	$(SRCS:%.c=%.o)

LIBFT_DIR	=	../libft
LIBFT_A 	= 	libft.a
LIBFT 		= 	$(LIBFT_DIR)/$(LIBFT_A)

UTILS_DIR	=	../utils
UTILS_A 	= 	utils.a
UTILS		= 	$(UTILS_DIR)/$(UTILS_A)

ENV_CTRL_DIR	=	../environ_control
ENV_CTRL_A		=	environ_control.a
ENV_CTRL		= 	$(ENV_CTRL_DIR)/$(ENV_CTRL_A)

$(NAME): $(OBJS) $(PARSER) $(UTILS) $(ENV_CTRL)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(ENV_CTRL):
	$(MAKE) -C $(ENV_CTRL_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

all: $(NAME)

clean:	
		$(RM) $(OBJS) $(ENV_CTRL_DIR)/*.[oa] $(LIBFT_DIR)/*.[oa] $(UTILS_DIR)/*.[oa]

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
