#include "../../includes/minishell.h"

void	handle_ctrl_d(t_shell *shell)
{
	ft_printf(STDIN_FILENO, "exit\n");
	free_exit(shell);
}
