#include "../../include/minishell.h"

t_global_data data;
/* gcc main_exit.c exit.c ../libft/libft.a ../environ_control/select_env.c ../utils/hash.c ../libft/ft_strcmp.c calc_exit_status.c ../libft/ft_atoi.c */
int	main (void)
{
	// echo
	t_words *words;
	t_words *top;

	data.error_number = 0;
	words = calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("exit");
	words->next = calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("--");
	words->next = calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("456");
	my_exit(top->next, 1);
	return (0);
}
