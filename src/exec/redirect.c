#include "../../include/minishell.h"

void do_redirect(t_words *sign, t_words *file_name)
{
    int fd;

    if (sign->token_type == READ)
    {
        fd = open (file_name->word, O_RDONLY);
        if (fd < 0)
        {
            perror(file_name->word);
            exit(1);
        }
        dup2(fd, 0);
    }
    else
    {
        fd = open(file_name->word, (O_RDWR | O_CREAT | O_TRUNC), 0644);
        if (fd < 0)
            perror("test");
        dup2(fd, 1);
    }
    close(fd);
}

void    do_append(t_words *file_name)
{
    int fd;
    fd = open (file_name->word, (O_RDWR | O_APPEND | O_CREAT), 0644);
    dup2(fd, 1);
    close(fd);
}

void redirect_check(t_words *word_list)
{
    while (word_list != NULL)
    {
        if (word_list->token_type == READ || word_list->token_type == WRITE)
        {
            do_redirect(word_list, word_list->next);
            word_list = word_list->next->next;
        }
        else if (word_list->token_type == APPEND)
        {
            do_append(word_list->next);
            word_list = word_list->next->next;
        }
        else
            word_list = word_list->next;
    }
}
