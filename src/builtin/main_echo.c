#include "../../include/minishell.h"
#include <unistd.h>

/* gcc main_echo.c echo.c ../libft/libft.a is_option_n.c */
int	main (void)
{
	// echo
	t_words *words;
	t_words *top;
	t_data	data;

	words = ft_calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("echo");
	words->next = ft_calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("-n");
	words->next = ft_calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("");
	words->next = ft_calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("");
	my_echo(top->next, STDOUT_FILENO, &data);
	return (0);
}
