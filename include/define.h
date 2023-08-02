#ifndef DEFINE_H
#define DEFINE_H

# define PROMPT "minishell >> "
# define HEREDOC_PROMPT "> "
# define SPECIAL_CHAR " \t\n<>|"
# define SPACE_CHAR " \t\n"
# define IFS_CHARS " \t\n"
# define NEED_TO_BE_ESCAPED "\n`$\"\\"

# define ERR_SYNTAX	"minishell: syntax error near unexpected token `"
# define ERR_SYNTAX_CLOSE	"'"
# define ERR_MANY_ARG "minishell: "
# define ERR_MANY_ARG_CLOSE	": too many arguments"
# define ERR_NO_HOME	"minishell: cd: HOME not set"
# define ERR_NO_FILE	"minishell: cd: "
# define ERR_NO_FILE_CLOSE	": No such file or directory"
# define ERR_EXIT	"minishell: exit: "
# define ERR_EXIT_CLOSE	": numeric argument required"
# define ERR_NOT_CLOSE_QUOTATION "Error: not close quotation"
# define ERR_CRR_DIR_NOT_EXIST	"Error: Current dir info does not exist"
# define ERR_EXPORT_VALID "minishell: export: `"
# define ERR_EXPORT_VALID_CLOSE	"': not a valid identifier"

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
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

enum e_size
{
	HASH_MAP_SIZE = 27,
	BUFFER_SIZE = 100,
};

enum e_cd
{
	CD_SUCCESS = 0,
	CD_FAILD = -1,
	CD_MALLOC_ERR = -2,
};

enum e_quote_mode
{
	NOT_Q_MODE = 0,
	SINGLE_Q_MODE,
	DOUBLE_Q_MODE,
};

typedef enum e_sig_mode
{
	NORMAL = 0,
	READLINE_MODE,
	ENTER_CTRL_C_MODE,
	HEREDOC_MODE,
	EXEC_MODE,
}	t_sig_mode;

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

typedef struct s_words
{
	struct s_words	*next;
	t_token_type	token_type;
	char			*word;
	pid_t			command_pid;
}	t_words;

typedef struct s_tree_node
{
	t_node_type			node_type;
	t_words				*word_list;
	struct s_tree_node	*prev;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;


typedef struct	s_env
{
	char			*original;
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	int			err_code;
	bool		err_flag;
	t_env		**env_map;
	char		*crr_dir;
	char		*line;
	t_tree_node	*root;
}	t_data;

extern char						**environ;
extern volatile	sig_atomic_t	g_sig_mode;

#endif
