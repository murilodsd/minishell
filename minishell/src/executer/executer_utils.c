#include "../../includes/minishell.h"

int	safe_fork(t_shell *shell)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		msg_error(GENERAL_ERROR, "Fork failed");
		free_all(shell);
	}
	return (pid);
}