#include "../../../includes/minishell.h"

void	exit_builtin(t_shell * shell, char **exit_args)
{
	if (exit_args[2])
	{
		shell->exit_status = EXIT_CMD_NOT_FOUND;
		free_exit_error(shell, TOO_MANY_ARGS, "exit");
	}
	else if (!exit_args[1])
		
}
