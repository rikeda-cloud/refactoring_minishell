#include "../../include/minishell.h"

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

void	variable_expansion(t_words *words, bool *err_flag)
{
	int		quote_mode;
	char	*target;

	quote_mode = NOT_Q_MODE;
	if (words == NULL)
		*err_flag = true;
	while (*err_flag == false && words != NULL)
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
		{
			words->word = replace_dallor_str_to_env(words->word, target);
			if (words->word == NULL)
				*err_flag = true;
		}
	}
}
