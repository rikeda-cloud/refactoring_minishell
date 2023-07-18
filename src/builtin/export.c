#include "../../include/minishell.h"
#define FMT_ERR_EXPORT_VALID "minishell: export: `%s': not a valid identifier"

bool	is_not_a_valid_identifier(char *str)
{
	if (ft_isalnum(*str))
		return (true);
	else
		return (false);
}

bool	is_not_only_under(char *str)
{
	if (str[0] == '_' && str[1] == '=')
		return (true);
	else
		return (false);
}

void	insert_or_update_env(char *word)
{
	char	*env_name;
	char	*env_value;
	t_env	*env;

	env_name = strdup_n(word, count_to_front_of_c(word, '='));
	env = select_env(data.env_map, env_name);
	if (env == NULL)
		insert_env_to_env_map(data.env_map, word);
	else
	{
		while (*word != '=')
			word++;
		word++;
		env_value = strdup_n(word, count_to_front_of_c(word, '\0'));
		update_env(data.env_map, env_name, env_value);
		free(env_value);
	}
	free(env_name);
}

void	export_have_arg_pattern(t_words *word_list)
{
	char	*word;

	while (word_list != NULL)
	{
		word = word_list->word;
		if (is_not_a_valid_identifier(word))
			printf(FMT_ERR_EXPORT_VALID, word);
		else if (is_in_iqual(word) && is_not_only_under(word))
			insert_or_update_env(word_list->word);
		word_list = word_list->next;
	}
}

void	my_export(t_words *word_list, int fd)
{
	if (fd != STDOUT_FILENO)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (word_list == NULL)
		print_all_env(fmt_export, STDOUT_FILENO);
	else
		export_have_arg_pattern(word_list);
}
