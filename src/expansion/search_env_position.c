#include "../../include/minishell.h"

static bool	is_deal_target(const char *str)
{
	if (ft_isalpha(str[1]))
		return (true);
	else if (str[1] == '_' && str[1] != '\0' && str[2] == '_')
		return (true);
	return (false);
}

static const char	*skip_to_next_quote_or_dallor_prev_char(const char *str)
{
	str++;
	while (*str != '\0')
	{
		if (is_quotation(*str) || *str == '$')
			break;
		str++;
	}
	str--;
	return (str);
}

const char	*search_env_position(const char *str)
{
	bool	single_quote_flag;
	bool	double_quote_flag;

	single_quote_flag = false;
	double_quote_flag = false;
	while (*str != '\0')
	{
		if (*str == '\'')
			reverse_flag(&single_quote_flag);
		else if (*str == '"')
			reverse_flag(&double_quote_flag);
		else if (*str == '$')
		{
			if (double_quote_flag == true && is_deal_target(str))
				break;
			if (single_quote_flag == false && is_deal_target(str))
				break;
			str = skip_to_next_quote_or_dallor_prev_char(str);
		}
		str++;
	}
	return (str);
}

