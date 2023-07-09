#include "../../include/minishell.h"

static bool	is_not_close_quotation(char *word)
{
	bool	quote_flag;
	int		quote_char;

	quote_flag = false;
	while (*word != '\0')
	{
		if (is_quotation(*word) && quote_flag == false)
		{
			quote_flag = true;
			quote_char = *word;
		}
		else if (is_quotation(*word) && quote_flag == true)
		{
			if (quote_char == *word)
				quote_flag = false;
		}
		word++;
	}
	return (quote_flag);
}

bool	check_not_close_quotation(t_words *words)
{
	while (words->word != NULL)
	{
		if (is_not_close_quotation(words->word))
			return (true);
		words = words->next;
	}
	return (false);
}

// bool	check_syntax(t_words *words)
// {
// 	if (check_not_close_quotation(words))
// 		return (false);
// 	return (true);
// }
