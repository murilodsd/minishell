#include "../../includes/minishell.h"

char	**get_path(t_shell *shell)
{
	t_list	*path_node;
	char	*path_string;
	char	**path_array_string;
	int	i;

	if (!shell->envp_lst)
		return (NULL);
	path_node = ft_lstfind_name(shell->envp_lst, "PATH");
	if (!path_node)
		return (NULL);
	path_string = ((t_var *)(path_node->content))->value;
	if (!path_string)
		return (NULL);
	path_array_string = ft_split(path_string,':');
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
		path_array_string, "Calloc failed");
	i = 0;
	while (path_array_string[i])
	{
		//REVIEW -> liberar memoria
		path_array_string[i] = ft_strjoin(path_array_string[i], "/");
		i++;
	}
	return (path_array_string);
}

void	handle_exec_error(int execve_ret, t_exec *exec, t_shell *shell)
{
	shell->exit_status = EXIT_CMD_NOT_FOUND;
	if (execve_ret == -1)
	{
		if (access(exec->args[0], X_OK) != 0)
		{
			shell->exit_status = 126;
			free_exit_error(shell, PERMISSION_DENIED, exec->args[0]);
		}
		if ((exec->args[0][0] == '.' && exec->args[0][1] == '/')
			|| exec->args[0][0] == '/')
			free_exit_error(shell, IS_DIRECTORY, exec->args[0]);
		else
			free_exit_error(shell, CMD_NOT_FOUND, exec->args[0]);
	}
	if ((exec->args[0][0] == '.' && exec->args[0][1] == '/')
			|| exec->args[0][0] == '/')
		free_exit_error(shell, NO_FILE_DIRECTORY, exec->args[0]);
	free_exit_error(shell, CMD_NOT_FOUND, exec->args[0]);
}


void	execute_execve(t_shell *shell, t_exec *exec)
{
	int		i;
	int		execve_ret;
	char	**path;
	char	**exported_envs;
	char	*path_cmd;

	execve_ret = 0;
	//REVIEW -> refazer para gerar char*
	//exported_envs = filter_envs(shell->envp_lst);
	exported_envs = NULL;
	if (access(exec->args[0], F_OK) == 0)
		execve_ret = execve(exec->args[0], exec->args, exported_envs);
	path = get_path(shell);
	i = 0;
	while (path[i])
	{
		path_cmd = ft_strjoin(path[i], exec->args[0]);
		if (access(path_cmd, F_OK) == 0)
			execve_ret = execve(path_cmd, exec->args, exported_envs);
		free(path_cmd);
		i++;
	}
	handle_exec_error(execve_ret, exec, shell);
}

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
		printf("runexecve");
		//run_execv(shell, exec);
	//free_exit(shell);
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
