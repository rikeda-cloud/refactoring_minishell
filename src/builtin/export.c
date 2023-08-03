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
			if (env_value != NULL)
				update_env(data->env_map, env_name, env_value);
			free_str(env_value);
		}
	}
	free_str(env_name);
}

bool	is_in_plus_equal(const char *str)
{
	if (str == NULL)
		return (false);
	while (str[0] != '\0' && str[1] != '\0')
	{
		if (ft_strncmp(str++, "+=", 2) == 0)
			return (true);
	}
	return (false);
}

size_t	count_to_front_of_plus_equal(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && str[size + 1] != '\0')
	{
		if (ft_strncmp(&str[size], "+=", 2) == 0)
			return (size);
		size++;
	}
	return (size);
}

char	*skip_plus_equal(char *str)
{
	while (str[0] != '\0' && str[1] != '\0')
	{
		if (ft_strncmp(str, "+=", 2) == 0)
			break;
		str++;
	}
	return (&str[2]);
}

static void	fill_new_word(char *new_str, char *str, char *key, char *value)
{
	size_t	idx;

	idx = 0;
	while (key[idx] != '\0')
	{
		new_str[idx] = key[idx];
		idx++;
	}
	str =  &str[idx] + 2;
	new_str[idx++] = '=';
	if (value != NULL)
	{
		while (*value != '\0')
			new_str[idx++] = *value++;
	}
	while (*str != '\0')
		new_str[idx++] = *str++;
}

char	*change_plus_equal_to_word(char *str, t_data *data)
{
	size_t	size;
	t_env	*env;
	char	*key;
	char	*new_str;

	size = ft_strlen(str) - 1;
	key = strdup_n(str, count_to_front_of_plus_equal(str));
	if (key == NULL)
		return (NULL);
	env = select_env(data->env_map, key);
	if (env != NULL && env->value != NULL)
		size += ft_strlen(env->value);
	new_str = ft_calloc(sizeof(char), (size + 1));
	if (new_str == NULL)
		return (free_str(key));
	if (env != NULL && env->value != NULL)
		fill_new_word(new_str, str, key, env->value);
	else
		fill_new_word(new_str, str, key, NULL);
	free_double_str(str, key);
	return (new_str);
}

void	export_have_arg_pattern(t_words *word_list, t_data *data)
{
	while (word_list != NULL)
	{
		if (is_only_under_env(word_list->word))
			;
		else if (is_not_a_valid_identifier(word_list->word))
			err_export_valid(word_list->word, &data->err_code);
		else if (is_in_plus_equal(word_list->word))
		{
			word_list->word = change_plus_equal_to_word(word_list->word, data);
			insert_or_update_env(word_list->word, data);
		}
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
