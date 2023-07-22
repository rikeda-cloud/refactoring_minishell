#include "../../include/minishell.h"
#include <unistd.h>

/* gcc main_cd.c cd.c ../environ_control/select_env.c ../libft/libft.a ../utils/hash.c */
int	main (void)
{
	// cd
	t_words *words;
	t_words *top;
	t_data	data;

	data.crr_dir = getcwd(NULL, 0);
	words = calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("cd");
	words->next = calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("..........");
	my_cd(top->next, STDOUT_FILENO, &data);
	printf("%s\n", data.crr_dir);
	return (0);
}
