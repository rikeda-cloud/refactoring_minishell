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

t_words	*append_new_node(t_words *list, t_words *new_node)
{
	t_words	*head;

	head = list;
	while (list->next != NULL)
		list = list->next;
	list->next = new_node;
	return (head);
}

t_words *split_word_by_ifs(t_words *word_list)
{
	size_t	idx;
	char	*new_str;
	t_words *ifs_and_second;

	idx = strlen_ifs(word_list->word);
	new_str = strdup_n(&word_list->word[idx], strlen_to_ifs(&word_list->word[idx]));
	if (new_str == NULL)
		return (NULL);
	idx += strlen_to_ifs(&word_list->word[idx]);
	idx += strlen_ifs(&word_list->word[idx]);
	ifs_and_second = new_ifs_and_second_node(ft_strdup(&word_list->word[idx]));
	if (ifs_and_second == NULL)
	{
		free(new_str);
		return (NULL);
	}
	ifs_and_second = append_new_node(ifs_and_second, word_list->next);
	free(word_list->word);
	word_list->word = new_str;
	word_list->next = ifs_and_second;
	return (word_list);
}

void	split_word_list_by_ifs(t_words *word_list, bool *err_flag)
{
	int	quote_mode;

	quote_mode = NOT_Q_MODE;
	while (word_list != NULL)
	{
		if (is_token_type_quotation(word_list->token_type))
			change_quote_mode(&quote_mode, word_list->token_type);
		else if (quote_mode == NOT_Q_MODE && is_in_ifs_char(word_list->word))
		{
			word_list = split_word_by_ifs(word_list);
			if (word_list == NULL)
			{
				*err_flag = true;
				break ;
			}
		}
		word_list = word_list->next;
	}
}
