/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:01:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/08/06 15:01:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*strjoin_path(char *sepflag, char *separgv)
{
	char	*path;
	char	*tmp;

	path = ft_strjoin(sepflag, "/");
	if (path == NULL)
		return (NULL);
	tmp = path;
	path = ft_strjoin(path, separgv);
	free_str(tmp);
	return (path);
}
