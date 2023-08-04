#include "../../include/minishell.h"

char	*replace_dallor_str_to_env(char *word, char *target, t_data *data)
{
	t_env	*env;
	char	*str_err_code;
	char	*new_str;

	env = select_env(data->env_map, target);
	new_str = NULL;
	if (*target == '?')
	{
		str_err_code = ft_itoa(data->err_code);
		if (str_err_code != NULL)
			new_str = replace(word, target, str_err_code);
		else
			free_double_str(word, target);
		free_str(str_err_code);
	}
	else if (env == NULL)
		new_str = replace(word, target, "");
	else
		new_str = replace(word, target, env->value);
	if (new_str == NULL)
		data->err_flag = true;
	return (new_str);
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
	delete_last_dallor(words, data);
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
		else if (target == NULL || quote_mode == SINGLE_Q_MODE)
		{
			free_str(target);
			words = words->next;
		}
		else
			words->word = replace_dallor_str_to_env(words->word, target, data);
	}
}
