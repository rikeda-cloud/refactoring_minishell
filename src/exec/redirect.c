#include "../../include/minishell.h"

bool	redirect_check(t_words *word_list, bool exit_flag)
{
	bool	err_flag;

	err_flag = false;
    while (word_list != NULL && err_flag == false)
    {
        if (word_list->token_type == READ)
        {
            redirect_read(word_list->next, exit_flag, &err_flag);
            word_list = word_list->next->next;
        }
        else if(word_list->token_type == WRITE)
        {
            redirect_write(word_list->next, exit_flag, &err_flag);
            word_list = word_list->next->next;
        }
        else if (word_list->token_type == APPEND)
        {
            redirect_append(word_list->next, exit_flag, &err_flag);
            word_list = word_list->next->next;
        }
        else
            word_list = word_list->next;
    }
	return (err_flag);
}
