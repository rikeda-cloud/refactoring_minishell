#include "../../include/minishell.h"

/* gcc main_echo.c echo.c ../libft/libft.a is_option_n.c */
int	main (void)
{
	// echo
	t_words *words;
	t_words *top;

	words = calloc(sizeof(t_words), 1);
	top = words;
	words->word = strdup("echo");
	words->next = calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("nnnnnnn");
	words->next = calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("abc");
	words->next = calloc(sizeof(t_words), 1);
	words = words->next;
	words->word = strdup("123");
	my_echo(top->next, 1);
	return (0);
}
