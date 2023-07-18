#include "../../include/minishell.h"


bool	is_token_type_quotation(t_token_type type)
{
	if (type == TMP_SINGLE_QUOTE)
		return (true);
	if (type == TMP_DOUBLE_QUOTE)
		return (true);
	return (false);
}

void	change_quote_mode(int *mode, t_token_type type)
{
	if (*mode == SINGLE_Q_MODE || *mode == DOUBLE_Q_MODE)
		*mode = NOT_Q_MODE;
	else if (type == TMP_SINGLE_QUOTE)
		*mode = SINGLE_Q_MODE;
	else
		*mode = DOUBLE_Q_MODE;
}

char	*replace_dallor_str_to_env(char *word, char *target)
{
	t_env *env;

	env = select_env(data.env_map, target);
	if (*target == '?')
		return (replace(word, target, ft_itoa(data.error_number)));
	else if (env == NULL)
		return (replace(word, target, ""));
	else
		return (replace(word, target, env->value));
}

void	variable_expansion(t_words *words)
{
	int		quote_mode;
	char	*target;

	quote_mode = NOT_Q_MODE;
	while (words != NULL)
	{
		target = strdup_env(words->word);
		if (is_token_type_quotation(words->token_type))
		{
			change_quote_mode(&quote_mode, words->token_type);
			words = words->next;
		}
		else if (quote_mode == SINGLE_Q_MODE || target == NULL)
			words = words->next;
		else
			words->word = replace_dallor_str_to_env(words->word, target);
	}
}
