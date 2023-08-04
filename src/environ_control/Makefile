NAME		=	environ_control.a
CC			=	cc
AR 			= 	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g
SRCS		=	change_environ_to_map.c \
				change_map_to_environ.c \
				delete_env.c \
				insert_env_to_map.c \
				insert_new_env.c \
				select_env.c \
				update_env.c
OBJS		= 	$(SRCS:%.c=%.o)

LIBFT_DIR	=	../libft
LIBFT_A		=	libft.a
LIBFT		= 	$(LIBFT_DIR)/$(LIBFT_A)

UTILS_DIR	=	../utils
UTILS_A		=	utils.a
UTILS		= 	$(UTILS_DIR)/$(UTILS_A)

$(NAME): $(OBJS) $(LIBFT) $(UTILS) 
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

all: $(NAME)

clean:	
		$(RM) $(OBJS) $(LIBFT_DIR)/*.[oa] $(UTILS_DIR)/*.[oa]

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
