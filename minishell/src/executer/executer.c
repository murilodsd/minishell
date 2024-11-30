#include "../../includes/minishell.h"

void	run_exec(t_shell *shell, t_exec *exec)
{
	if (!exec || !exec->args[0])
		return ;
	//REVIEW -> caso de o comando ser "" ou $abc
	//if (!exec->args[0][0])
	//	shell_error(shell, "", 1, true);
	if (!ft_strcmp(exec->args[0], "echo"))
		echo_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "export"))
		export_builtin(shell, exec->args);
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
		//run_execv(shell, exec);
	free_exit(shell);
}

void	executer(t_shell * shell, void *root)
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
