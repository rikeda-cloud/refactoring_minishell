#include "../../include/minishell.h"

bool	is_quotation(const int c)
{
	if (c == '\'')
		return (true);
	else if (c == '"')
		return (true);
	else
		return (false);
}

bool	is_quote_node(t_words *node)
{
	if (node->token_type == TMP_SINGLE_QUOTE)
		return (true);
	if (node->token_type == TMP_DOUBLE_QUOTE)
		return (true);
	return (false);
}
