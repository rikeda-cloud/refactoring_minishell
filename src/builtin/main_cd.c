#include "../../include/minishell.h"

/* gcc main_cd.c cd.c ../environ_control/select_env.c ../libft/libft.a ../utils/hash.c */
int	main (void)
{
	// cd
	t_words *words;
	t_words *top;
	t_data	data;

	data.crr_dir = getcwd(NULL, 0);
	data.env_map = change_environ_to_map();
	words = ft_calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("cd");
	/* words->next = calloc(sizeof(t_words), 1); */
	/* words = words->next; */
	/* words->word = strdup(""); */
	my_cd(top->next, STDOUT_FILENO, &data);
	printf("%s\n", data.crr_dir);
	free_hash_map(data.env_map);
	free_str(data.crr_dir);
	free_all_word_list(top);
	return (0);
}
