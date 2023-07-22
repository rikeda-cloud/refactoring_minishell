#ifndef DEFINE_H
#define DEFINE_H

# define PROMPT "minishell >> "

# define SPECIAL_CHAR " \t\n<>|"
# define SPACE_CHAR " \t\n"
# define IFS_CHARS " \t\n"
# define NEED_TO_BE_ESCAPED "$\"\\"

# define FMT_ERR_SYNTAX	"minishell: syntax error near unexpected token `%s'\n"
# define FMT_ERR_EXIT	"bash: exit: %s: numeric argument required\n"
# define FMT_ERR_MANY_ARG_CD "minishell: cd: too many arguments\n"
# define FMT_ERR_MANY_ARG_EXIT "minishell: exit: too many arguments\n"
# define FMT_ERR_NO_HOME	"minishell: cd: HOME not set\n"
# define FMT_ERR_NO_FILE	"minishell: cd: %s: No such file or directory\n"
#define FMT_ERR_NOT_CLOSE_QUOTATION "Error not close quotation\n"
#define FMT_ERR_CAN_NOT_CREATE_MAP "Error hash map can not create\n"
#define FMT_ERR_EXPORT_VALID "minishell: export: `%s': not a valid identifier\n"

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
	char			*original;
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	int		err_number;
	t_env	**env_map;
	char	*crr_dir;
}	t_data;

typedef enum e_token_type
{
	WORD = 0,
	PIPE_CHAR,
	READ,
	WRITE,
	APPEND,
	HEREDOC,
	DELIMITER,
	DELIMITER_QUOTE,
	TMP_SINGLE_QUOTE,
	TMP_DOUBLE_QUOTE,
	TMP_IFS,
}	t_token_type;

typedef enum e_node_type
{
	COMMAND = 0,
	PIPE,
}	t_node_type;


enum e_quote_mode
{
	NOT_Q_MODE = 0,
	SINGLE_Q_MODE,
	DOUBLE_Q_MODE,
};

enum e_size
{
	HASH_MAP_SIZE = 27,
	BUFFER_SIZE = 100,
};

typedef struct s_words
{
	struct s_words	*next;
	t_token_type	token_type;
	char			*word;
}	t_words;

typedef struct s_tree_node
{
	t_node_type			node_type;
	t_words				*word_list;
	struct s_tree_node	*prev;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;

extern	char **environ;

#endif
