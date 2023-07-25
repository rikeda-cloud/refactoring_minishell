#include "../../include/minishell.h"

void	insert_or_update_env(char *word, t_data *data)
{
	char	*env_name;
	char	*env_value;
	t_env	*env;

	env_name = strdup_n(word, count_to_front_of_c(word, '='));
	env = select_env(data->env_map, env_name);
	if (env == NULL)
		insert_env_to_env_map(data->env_map, word);
	else
	{
		while (*word != '=')
			word++;
		word++;
		env_value = strdup_n(word, count_to_front_of_c(word, '\0'));
		update_env(data->env_map, env_name, env_value);
		free(env_value);
	}
	free(env_name);
}

void	export_have_arg_pattern(t_words *word_list, t_data *data)
{
	while (word_list != NULL)
	{
		if (is_only_under_env(word_list->word))
			;
		else if (is_not_a_valid_identifier(word_list->word))
			err_export_valid(word_list->word, &data->err_code);
		/* else */
		/* { */
		/* 	if (is_add_and_assign(word_list->word)) */
		/* 		add_and_assign_env(word_list->word); */
		/* 	else if (is_in_equal(word_list->word)) */
		/* 		insert_or_update_env(word_list->word, data); */
		/* 	else */
		/* 		insert_env_to_env_map(data->env_map, word_list->word); */
		/* } */
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
	if (word_list == NULL || is_only_null_word_node(word_list))
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
