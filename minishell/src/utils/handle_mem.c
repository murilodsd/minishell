#include "../../includes/minishell.h"

static void	save_pointer(t_shell *shell, \
	t_list **ptr_or_matrix_list, void *ptr)
{
	t_list	*new_node;

	new_node = ft_lstnew(ptr);
	if (!new_node)
		free_exit_error(shell, GENERAL_ERROR, \
			"Failed to allocate mem for a node");
	ft_lstadd_front(ptr_or_matrix_list, new_node);
}

void	check_mem_alloc(t_shell *shell, t_list **ptr_or_matrix_list, \
	void *ptr, char *error_msg, bool exit_program)
{
	if (!ptr)
		free_exit_error(shell, GENERAL_ERROR, error_msg);
	else
		save_pointer(shell, ptr_or_matrix_list, ptr);
}
