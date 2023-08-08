#include "../../include/minishell.h"

static t_words	*wrap_append_word_node(t_words *list, char *str, t_data *data)
{
	t_words	*new_node;

	if (str == NULL)
	{
		data->err_flag = true;
		return (NULL);
	}
	new_node = ft_calloc(sizeof(t_words), 1);
	if (new_node == NULL)
	{
		data->err_flag = true;
		return (free_str(str));
	}
	new_node->word = str;
	if (new_node->word[0] == '$')
		new_node->token_type = TMP_DALLOR_WORD;
	return (append_word_node(list, new_node));
}

static char	*skip_to_dallor(char *str)
{
	if (*str == '$')
		str++;
	while (*str != '\0' && *str != '$')
		str++;
	return (str);
}

static char	*strdup_to_dallor(char *str)
{
	const char	*str_top_ptr;

	str_top_ptr = str;
	str = skip_to_dallor(str);
	return (strdup_n(str_top_ptr, str - str_top_ptr));
}

static t_words	*split_dallor_str(char *str, t_data *data)
{
	t_words	*list;
	char	*tmp_str;

	list = NULL;
	while (*str != '\0' && data->err_flag == false)
	{
		if (*str != '$')
		{
			tmp_str = strdup_to_dallor(str);
			str = skip_to_dallor(str);
		}
		else
		{
			tmp_str = strdup_n(str, 1 + count_env_size(str));
			str = &str[1 + count_env_size(str)];
		}
		list = wrap_append_word_node(list, tmp_str, data);
	}
	if (data->err_flag)
		list = free_all_word_list(list);
	return (list);
}

t_words	*split_word_list_by_dallor_str(t_words *word_list, t_data *data)
{
	t_words	*new_word_list;
	t_words	*next_word_ptr;
	t_words	*tmp_word_ptr;

	new_word_list = NULL;
	while (word_list != NULL && data->err_flag == false)
	{
		next_word_ptr = word_list->next;
		word_list->next = NULL;
		if (is_c_in_str(word_list->word, '$'))
		{
			tmp_word_ptr = word_list;
			word_list = split_dallor_str(word_list->word, data);
			free_word_node(tmp_word_ptr);
		}
		if (data->err_flag)
			next_word_ptr = free_all_word_list(next_word_ptr);
		new_word_list = append_word_node(new_word_list, word_list);
		word_list = next_word_ptr;
	}
	if (data->err_flag)
		return (free_all_word_list(new_word_list));
	return (new_word_list);
}
