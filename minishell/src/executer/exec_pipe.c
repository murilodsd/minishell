#include "../../includes/minishell.h"

void	exec_pipe(t_shell *shell, t_pipe *pipe_node)
{
	int	fd[2];
	int	pid[2];

	if (pipe(fd) == -1)
		free_exit_error(shell, GENERAL_ERROR, "Pipe function failed");
	ignore_sig_int_and_quit();
	pid[0] = fork();
	if (pid[0] == CHILD)
	{
		reset_sig_int_and_quit();
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		executer(shell, pipe_node->left);
		close(fd[0]);
		free_exit(shell);
	}
	if (pid[1] == CHILD)
	{
		reset_sig_int_and_quit();
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		executer(shell, pipe_node->right);
		close(fd[0]);
		free_exit(shell);
	}
}