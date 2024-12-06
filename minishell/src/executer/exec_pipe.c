#include "../../includes/minishell.h"

void	handle_signal_output(int exit_status_0, int exit_status_1)
{
	if (exit_status_0 == SIGINT || exit_status_1 == SIGINT)
		ft_printf(STDOUT_FILENO, "\n");
	else if (exit_status_0 == SIGQUIT || exit_status_1 == SIGQUIT)
		ft_printf(STDOUT_FILENO, "Quit (core dumped)\n");

}

int	handle_exit_code(int exit_code)
{
	int exit_status = WTERMSIG(exit_code);
	if (exit_status == SIGINT)
		return 130;
	else if (exit_status == SIGQUIT)
		return 131;
	return 0;
}

int check_signaled_exit(int exit_code[2]) {
	int	exit_status_0 = 0;
	int	exit_status_1 = 0;

	if (WIFSIGNALED(exit_code[0]) || WIFSIGNALED(exit_code[1]))
	{
		exit_status_0 = WTERMSIG(exit_code[0]);
		exit_status_1 = WTERMSIG(exit_code[1]);
		handle_signal_output(exit_status_0, exit_status_1);
		if (WIFSIGNALED(exit_code[1])) 
			return (handle_exit_code(exit_code[1]));
	}
	return (WEXITSTATUS(exit_code[1]));
}

void	create_left_and_right_nodes(t_shell *shell, t_pipe *pipe_node, int fd[2], int pid[2])
{
	pid[0] = safe_fork(shell);
	if (pid[0] == CHILD)
	{
		reset_sig_int_and_quit();
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute_tree(shell, pipe_node->left);
		close(fd[1]);
		free_exit(shell);
	}
	pid[1] = safe_fork(shell);
	if (pid[1] == CHILD)
	{
		reset_sig_int_and_quit();
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execute_tree(shell, pipe_node->right);
		close(fd[0]);
		free_exit(shell);
	}
}

void	execute_pipe(t_shell *shell, t_pipe *pipe_node)
{
	int	fd[2];
	int	pid[2];
	int	exit_code[2];

	if (pipe(fd) == -1)
		free_exit_error(shell, GENERAL_ERROR, "Pipe function failed");
	ignore_sig_int_and_quit();
	create_left_and_right_nodes(shell, pipe_node, fd, pid);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], &exit_code[0], 0);
	waitpid(pid[1], &exit_code[1], 0);
	shell->exit_status = check_signaled_exit(exit_code);
	free_exit(shell);
}
