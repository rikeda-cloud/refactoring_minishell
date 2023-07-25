#include "../../include/minishell.h"

t_words	*new_ifs_and_second_node(char *second_word)
{
	t_words	*ifs_and_second;

	if (second_word == NULL)
		return (NULL);
	ifs_and_second = new_ifs_node();
	if (ifs_and_second == NULL)
		return (free_str(second_word));
	if (is_only_space(second_word))
	{
		free(second_word);
		return (ifs_and_second);
	}
	ifs_and_second->next = (t_words *)ft_calloc(sizeof(t_words), 1);
	if (ifs_and_second->next == NULL)
	{
		free(ifs_and_second);
		return (free_str(second_word));
	}
	ifs_and_second->next->word = second_word;
	return (ifs_and_second);
}

t_words	*append_new_node_to_list(t_words *list, t_words *new_node)
{
	t_words	*head;

	head = list;
	while (list->next != NULL)
		list = list->next;
	list->next = new_node;
	return (head);
}

t_words *split_word_by_ifs(t_words *word, t_data *data)
{
	size_t	idx;
	char	*str;
	t_words *ifs_and_second;

	idx = strlen_ifs(word->word, data);
	str = strdup_n(&word->word[idx], strlen_to_ifs(&word->word[idx], data));
	if (str == NULL)
		return (NULL);
	idx += strlen_to_ifs(&word->word[idx], data);
	idx += strlen_ifs(&word->word[idx], data);
	ifs_and_second = new_ifs_and_second_node(ft_strdup(&word->word[idx]));
	if (ifs_and_second == NULL)
		return (free_str(str));
	ifs_and_second = append_new_node_to_list(ifs_and_second, word->next);
	free(word->word);
	word->word = str;
	word->next = ifs_and_second;
	return (word);
}

void	split_word_list_by_ifs(t_words *word_list, t_data *data)
{
	int	q_mode;

	q_mode = NOT_Q_MODE;
	while (word_list != NULL)
	{
		if (is_token_type_quotation(word_list->token_type))
			change_quote_mode(&q_mode, word_list->token_type);
		else if (q_mode == NOT_Q_MODE && is_in_ifs_char(word_list->word, data))
		{
			word_list = split_word_by_ifs(word_list, data);
			if (word_list == NULL)
			{
				data->err_flag = true;
				break ;
			}
		}
		word_list = word_list->next;
	}
}
