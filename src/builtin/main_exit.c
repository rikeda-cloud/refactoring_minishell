#include "../../include/minishell.h"

/* gcc main_exit.c exit.c ../libft/libft.a ../environ_control/select_env.c ../utils/hash.c ../libft/ft_strcmp.c calc_exit_status.c ../libft/ft_atoi.c */
int	main (void)
{
	// echo
	t_words *words;
	t_words *top;
	t_data  data;

	data.err_code = 0;
	data.crr_dir = NULL;
	data.env_map = NULL;
	data.line = NULL;
	data.root = NULL;
	words = ft_calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("exit");
	words->next = ft_calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("a");
	words->next = ft_calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("b");
	my_exit(top->next, STDOUT_FILENO, &data);
	write(STDOUT_FILENO, "NOT EXIT\n", 9);
	return (data.err_code);
}
