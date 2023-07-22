#include "../../include/minishell.h"

/* gcc main_pwd.c pwd.c ../libft/libft.a ../environ_control/select_env.c ../utils/hash.c ../libft/ft_strcmp.c ../utils/utils_free_word_list.c */
int	main (void)
{
	// pwd
	t_words *words;
	t_words *top;
	t_data	data;

	data.crr_dir = getcwd(NULL, 0);
	words = (t_words *)calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("pwd");
	words->next = calloc(sizeof(t_words), 1);
	/* words = words->next; */
	/* words->word = strdup(""); */
	my_pwd(top->next, STDOUT_FILENO, &data);
	printf("%s\n", data.crr_dir);
	return (0);
}
