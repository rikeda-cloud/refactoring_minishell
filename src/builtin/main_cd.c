#include "../../include/minishell.h"

t_global_data data;
/* gcc main_cd.c cd.c ../libft/libft.a ../environ_control/select_env.c ../utils/utils_hash.c ../libft/ft_strcmp.c */
int	main (void)
{
	// cd
	t_words *words;
	t_words *top;

	data.crr_dir = getcwd(NULL, 0);
	words = calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("cd");
	words->next = calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("../");
	my_cd(top->next, 1);
	printf("%s\n", data.crr_dir);
	return (0);
}
