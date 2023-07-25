#include "../../include/minishell.h"

void	*free_all_data(t_data *data)
{
	free_str(data->crr_dir);
	free_str(data->line);
	free_all_tree_node(data->root);
	free_hash_map(data->env_map);
	return (NULL);
}
