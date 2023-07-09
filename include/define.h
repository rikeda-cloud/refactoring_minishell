#ifndef DEFINE_H
#define DEFINE_H

# define BUFFER_SIZE	100
# define HASH_MAP_SIZE	27

# define SPECIAL_CHAR	" \t\n<>|"
# define SPACE_CHAR		" \t\n"
# define IFS_CHAR		" \t\n"
# define PROMPT			"minishell >> "
# define SYNTAX_ERR_MES	"minishell: syntax error near unexpected token `%s'\n"

# define NOT_Q_MODE		0
# define SINGLE_Q_MODE	1
# define DOUBLE_Q_MODE	2 

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_global_data
{
	int		error_number;
	t_env	**env_map;
}	t_global_data;

typedef enum e_token_type
{
	WORD,
	PIPE_CHAR,
	READ,
	WRITE,
	APPEND,
	HEREDOC,
	TMP_SINGLE_QUOTE,
	TMP_DOUBLE_QUOTE,
	TMP_IFS,
}	t_token_type;

typedef enum e_node_type
{
	COMMAND,
	PIPE,
}	t_node_type;

typedef struct s_words
{
	struct s_words	*next;
	t_token_type	token_type;
	char			*word;
}	t_words;

typedef struct s_tree_node
{
	t_node_type		node_type;
	t_words				*word_list;
	struct s_tree_node	*prev;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;

extern	char	**	environ;
extern	t_global_data data;

#endif
