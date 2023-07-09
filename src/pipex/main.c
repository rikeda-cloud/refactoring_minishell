#include "../../include/minishell.h"

int	main(int argc, char **argv)
{
	check_argc(argc);
	if (argc == 4)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
			only_heredoc(argv);
		else
			no_pipe(argv);
	}
	else
		choice_case_cmd(argc, argv);
}
