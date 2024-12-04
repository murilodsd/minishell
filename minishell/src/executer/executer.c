#include "../../includes/minishell.h"

void	run_exec(t_shell *shell, t_exec *exec)
{
	if (!exec || !exec->args[0])
		return ;
	//REVIEW -> caso de o comando ser "" ou $abc
	if (exec->args[0][0] == '\0')
	{
		shell->exit_status = EXIT_CMD_NOT_FOUND;
		free_exit_error(shell, CMD_NOT_FOUND, exec->args[0]);
	}
	if (!ft_strcmp(exec->args[0], "echo"))
		echo_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "export"))
		export_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "env"))
		env_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "unset"))
		unset_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "pwd"))
		pwd_builtin(shell);
	else if (!ft_strcmp(exec->args[0], "cd"))
		cd_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "exit"))
		exit_builtin(shell, exec->args);
	//REVIEW - Caso de nao ser nenhum comando valido
	else
		execute_execve(shell, exec);
	//free_exit(shell);
}

void	execute(t_shell * shell, void *root)
{
	t_node_type	node_type;

	if (!root)
		return ;
	node_type = *(t_node_type*)root;
	if (node_type == EXEC_NODE)
		run_exec(shell, (t_exec *)root);
	// else if (is_redir_node_type(node_type))
	// 	run_redir(shell, (t_redir *)root);
	// else if (node_type == PIPE_NODE)
	// 	run_pipe(shell, (t_pipe *)root);
}
int	get_child_status(int child_exit_status)
{
	if (WIFEXITED(child_exit_status))
		return (WEXITSTATUS(child_exit_status));
	else if (WIFSIGNALED(child_exit_status))
	{
		if (WTERMSIG(child_exit_status) == SIGINT)
		{
			ft_printf(1, "\n");
			return (130);
		}
		else if (WTERMSIG(child_exit_status) == SIGQUIT)
		{
			ft_printf(1, "Quit (core dumped)\n");
			return (131);
		}
	}
	return (0);
}

void	fork_execute_in_child(t_shell * shell, void *root)
{
		int	child_exit_status;
		
		if (safe_fork(shell) == 0)
		{
			shell->process = CHILD;
			reset_sig_int_and_quit();
			//REVIEW -> Abrir heredoc?
			//if (shell->count_hd)
			//	open_all_heredocs(shell->root, shell);
			execute(shell, root);
			free_exit(shell);
		}
		ignore_sig_int_and_quit();
		wait(&child_exit_status);
		shell->exit_status = get_child_status(child_exit_status);
}

void	execute_in_parent(void *root, t_shell *shell)
{
	t_node_type	node_type;

	node_type = *(t_node_type *)root;
	shell->process = 1; //REVIEW -> Parent
	if (node_type == EXEC_NODE)
		run_builtin_p((t_exec *)root, shell);
	else if (node_type == REDIR_IN_NODE || node_type == REDIR_OUT_NODE
		|| node_type == REDIR_APPEND_NODE || node_type == HEREDOC_NODE)
		run_redir_p((t_redir *)root, shell);
}

void	executer(t_shell * shell, void *root)
{
	if (!root)
		return ;
	//REVIEW -> Checar se tem heredoc?
	//if (*((t_node_type *)root) != PIPE_NODE && !shell->count_hd)
	if (*((t_node_type *)root) != PIPE_NODE)
		//REVIEW -> execute_in_parent(shell, root);
		execute_in_parent(shell, root);
	//REVIEW -> Checar se tem heredoc? Não é else, pois o resultado de parent afeta aqui
	//if (shell->process == CHILD || shell->count_hd)
	else
		fork_execute_in_child(shell, root);
}
