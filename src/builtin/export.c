#include "../../include/minishell.h"

void	insert_or_update_env(char *word, t_data *data)
{
	char	*env_name;
	char	*env_value;
	t_env	*env;

	env_name = strdup_n(word, count_to_front_of_c(word, '='));
	if (env_name == NULL)
		return ;
	env = select_env(data->env_map, env_name);
	if (env == NULL)
		insert_env_to_env_map(data->env_map, ft_strdup(word));
	else
	{
		while (*word != '\0' && *word != '=')
			word++;
		if (*word++ != '\0')
		{
			env_value = strdup_n(word, count_to_front_of_c(word, '\0'));
			update_env(data->env_map, env_name, env_value);
			free_str(env_value);
		}
	}
	free_str(env_name);
}

void	export_have_arg_pattern(t_words *word_list, t_data *data)
{
	while (word_list != NULL)
	{
		if (is_only_under_env(word_list->word))
			;
		else if (is_not_a_valid_identifier(word_list->word))
			err_export_valid(word_list->word, &data->err_code);
		else
			insert_or_update_env(word_list->word, data);
		word_list = word_list->next;
	}
}

void	my_export(t_words *word_list, int fd, t_data *data)
{
	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (word_list != NULL && ft_strcmp(word_list->word, "--") == 0)
		word_list = word_list->next;
	if (word_list == NULL)
	{
		print_all_env(fmt_export, STDOUT_FILENO, data);
		data->err_code = 0;
	}
	else
	{
		data->err_code = 0;
		export_have_arg_pattern(word_list, data);
	}
}
