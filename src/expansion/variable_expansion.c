#include "../../include/minishell.h"

char	*replace_dallor_str_to_env(char *word, char *target, t_data *data)
{
	t_env *env;

	env = select_env(data->env_map, target);
	if (*target == '?')
		return (replace(word, target, ft_itoa(data->err_code)));
	else if (env == NULL)
		return (replace(word, target, ""));
	else
		return (replace(word, target, env->value));
}

char	*replace_all_env(char *str, t_data *data)
{
	char	*target;

	target= strdup_env(str, &data->err_flag);
	while (target != NULL && data->err_flag == false)
	{
		str = replace_dallor_str_to_env(str, target, data);
		target = strdup_env(str, &data->err_flag);
	}
	if (data->err_flag)
		return (free_str(str));
	return (str);
}

void	variable_expansion(t_words *words, t_data *data)
{
	int		quote_mode;
	char	*target;

	quote_mode = NOT_Q_MODE;
	if (words == NULL)
		data->err_flag = true;
	while (data->err_flag == false && words != NULL)
	{
		target = strdup_env(words->word, &data->err_flag);
		if (is_token_type_quotation(words->token_type))
		{
			change_quote_mode(&quote_mode, words->token_type);
			words = words->next;
		}
		else if (quote_mode == SINGLE_Q_MODE || target == NULL)
			words = words->next;
		else
		{
			words->word = replace_dallor_str_to_env(words->word, target, data);
			if (words->word == NULL)
				data->err_flag = true;
		}
	}
}
