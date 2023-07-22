#include "../../include/minishell.h"

t_global_data data;
/* gcc main_pwd.c pwd.c ../libft/libft.a ../environ_control/select_env.c ../utils/hash.c ../libft/ft_strcmp.c */
int	main (void)
{
	// echo
	t_words *words;
	t_words *top;

	data.crr_dir = getcwd(NULL, 0);
	words = (t_words *)calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("pwd");
	words->next = calloc(sizeof(t_words), 1);
	/* words = words->next; */
	/* words->word = strdup(""); */
	my_pwd(top->next, 1);
	printf("%s\n", data.crr_dir);
	return (0);
}
