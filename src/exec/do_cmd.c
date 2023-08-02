#include "../../include/minishell.h"

int parents(t_tree_node *root, pid_t pid, int prevfd, int *pipefd)
{
    root -> word_list -> command_pid = pid;
    if (prevfd == 0)
    {
        prevfd = pipefd[0];
        close(pipefd[1]);
        return(prevfd);
    }
    else
    {
        close(prevfd);
        prevfd = pipefd[0];
        close(pipefd[1]);
        return(prevfd);
    }
}

void    last_parents(t_tree_node *root, pid_t pid, int prevfd)
{
    root -> word_list -> command_pid = pid;
	if (prevfd != 0)
		close(prevfd);
}

void    child_wait(t_tree_node *root, t_tree_node *first_command)
{
	int	wstatus;
    root = first_command;
    while(true)
    {
        if (root -> prev == NULL ||(root -> prev -> prev == NULL && root != root -> prev -> left))
        {
            waitpid(root -> word_list -> command_pid, &wstatus, 0);
            /* waitpid(root -> word_list -> command_pid, NULL, 0); */
            break ;
        }
        else
        {
            waitpid(root ->word_list -> command_pid, &wstatus, 0); 
            /* waitpid(root ->word_list -> command_pid, NULL, 0); */ 
            if (root == first_command)
                root = root -> prev -> right;
            else
                root = root -> prev -> prev -> right;
        }
    }
    return ;
}

int do_command(t_tree_node *root, int prevfd, int heredoc_fd)
{
    pid_t   pid;
    char    **separgv;
    char    *path;
    int     pipefd[2];
    // int     stdin_fd;

    // stdin_fd = dup(0);
    // prevfd = heredoc_check(root -> word_list);
    pipe(pipefd);
    pid = fork();
    if (pid == 0)
    {
        if (prevfd != 0)
        {
            dup2(prevfd, 0);
            close (prevfd);
        }
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        close(pipefd[1]);
        if (heredoc_fd != 0)
        {
            dup2(heredoc_fd, 0);
            close(heredoc_fd);
        }
        redirect_check(root -> word_list);
        root -> word_list = delete_redirect_node(root -> word_list);
        separgv = ft_split(str_to_command(root), ' ');
        path = get_path(separgv[0]);
        execve(path, separgv, environ);
    }
    // close (stdin_fd);
    return (parents(root, pid, prevfd, pipefd));
}

void    do_last_command(t_tree_node *root, int prevfd, int heredoc_fd)
{
    char    **separgv;
    char    *path;
    pid_t   pid;
    // int     stdin_fd;

    // stdin_fd = dup(0);
    // prevfd = heredoc_check(root -> word_list);
    pid = fork();
    if (pid == 0)
    {
        if (prevfd != 0)
        {
            dup2(prevfd, 0);
            close (prevfd);
        }
        // heredoc_check(root -> word_list, stdin_fd);
        if (heredoc_fd != 0)
        {
            dup2(heredoc_fd, 0);
            close(heredoc_fd);
        }
        redirect_check(root -> word_list);
        root -> word_list = delete_redirect_node(root -> word_list);
        separgv = ft_split(str_to_command(root), ' ');
        path = get_path(separgv[0]);
        execve(path, separgv, environ);
    }
    else
    {
        // close(stdin_fd);
        last_parents(root, pid, prevfd);
    }
}
