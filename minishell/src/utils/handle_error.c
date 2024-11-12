#include "../../includes/minishell.h"

void	handle_error(void)
{
	printf("Error\n");
}

void	free_all(t_shell *shell)
{
	if (shell->mem_allocation.ptr_mem_list != NULL)
		ft_lstclear(&(shell->mem_allocation.ptr_mem_list), free);
	if (shell->mem_allocation.matrix_mem_list != NULL)
		ft_lstclear(&(shell->mem_allocation.matrix_mem_list), ft_free_matrix);
	clear_history();
	free(shell);
}

void	msg_error(t_error_codes error_code, char *error_msg)
{
	if (error_code == 1)
		ft_printf(STDERR_FILENO, "%s: command not found\n", error_msg);
	else if (error_code == 2)
		ft_printf(STDERR_FILENO, "minishell: %s: No such file or directory\n",
			error_msg);
	else if (error_code == 3)
		ft_printf(STDERR_FILENO, "minishell: %s: Permission denied\n", error_msg);
	else if (error_code == 4)
		ft_printf(STDERR_FILENO, "minishell: ambiguous redirect\n", error_msg);
	else if (error_code == 5)
		ft_printf(STDERR_FILENO, "minishell: %s: Is a directory\n", error_msg);
	else if (error_code == 6)
		ft_printf(STDERR_FILENO, "minishell: %s: Not a directory\n", error_msg);
	else
		ft_printf(STDERR_FILENO, "%s\n", error_msg);
}

void	free_exit_error(t_shell *shell, t_error_codes error_code, char *error_msg)
{
	int	exit_status;

	exit_status = shell->exit_status;
	msg_error(error_code, error_msg);
	free_all(shell);
	exit(exit_status);
}