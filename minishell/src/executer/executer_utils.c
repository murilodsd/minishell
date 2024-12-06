#include "../../includes/minishell.h"

int	safe_fork(t_shell *shell, int fd[2])
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		msg_error(GENERAL_ERROR, "Fork failed");
		if (fd)
		{
			close(fd[0]);
			close(fd[1]);
		}
		free_all(shell);
	}
	return (pid);
}