#include "../../include/minishell.h"

bool	is_only_null_char_node(t_words *word_list)
{
	while (word_list != NULL)
	{
		if (word_list->token_type != TMP_IFS && word_list->word[0] != '\0')
			return (false);
		word_list = word_list->next;
	}
	return (true);
}

bool	is_only_under_env(const char *str)
{
	if (ft_strncmp(str, "_=", 2) == 0)
		return (true);
	else if (ft_strcmp(str, "_") == 0)
		return (true);
	else
		return (false);
}
