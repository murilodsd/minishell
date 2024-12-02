#include "../../includes/minishell.h"

int	calculate_total_vars(t_list *envp)
{
	int	total;

	total = 0;
	while (envp)
	{
		if (((t_var *)(envp->content))->value)
			total++;
		envp = envp->next;
	}
	return (total);
}

size_t total_length(t_list *envp)
{
	size_t	size;

	size = ft_strlen(((t_var *)(envp->content))->name);
	size += ft_strlen(((t_var *)(envp->content))->value);
	return (size);
}

char	**get_exported_env_vars(t_shell *shell, t_list *envp)
{
	char	**envp_copy;
	int	i;

	if (!envp)
		return (NULL);
	envp_copy = ft_calloc(calculate_total_vars(envp) + 1, sizeof(char *));
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
		envp_copy, "Calloc failed");
	i = -1;
	while (envp)
	{
		if (((t_var *)(envp->content))->value)
		{
			envp_copy[++i] = ft_calloc(total_length(envp) + 2, sizeof(char));
			if (!envp_copy[i])
				free_exit_error(shell, GENERAL_ERROR, "Calloc failed");
			ft_strcat(envp_copy[i], ((t_var *)(envp->content))->name);
			ft_strcat(envp_copy[i], "=");
			ft_strcat(envp_copy[i], ((t_var *)(envp->content))->value);
		}
		envp = envp->next;
	}
	return (envp_copy);
}

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
	exported_envs = get_exported_env_vars(shell, shell->envp_lst);
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
