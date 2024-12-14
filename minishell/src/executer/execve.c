/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:46:35 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/14 16:55:53 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	append_slash(t_shell *shell, char **string)
{
	char	*tmp;

	tmp = *string;
	*string = ft_strjoin(*string, "/");
	free(tmp);
	if (!(*string))
		free_exit_error(shell, GENERAL_ERROR, "Calloc failed");
}

char	**get_path(t_shell *shell)
{
	t_list	*path_node;
	char	*path_string;
	char	**path_array_string;
	int		i;

	if (!shell->envp_lst)
		return (NULL);
	path_node = ft_lstfind_name(shell->envp_lst, "PATH");
	if (!path_node)
		return (NULL);
	path_string = ((t_var *)(path_node->content))->value;
	if (!path_string)
		return (NULL);
	path_array_string = ft_split(path_string, ':');
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
		path_array_string, "Calloc failed");
	i = 0;
	while (path_array_string[i])
	{
		append_slash(shell, &(path_array_string[i]));
		i++;
	}
	return (path_array_string);
}

void	handle_exec_error(int execve_ret, t_exec *exec, t_shell *shell, \
	bool path_exist)
{
	struct stat	st;

	shell->exit_status = EXIT_CMD_NOT_FOUND;
	if (!path_exist)
		free_exit_error(shell, NO_FILE_DIRECTORY, exec->args[0]);
	if (execve_ret == -1 && exec->args[0][0] != '/')
	{
		if (safe_access(exec->args[0], F_OK) == 0)
		{
			shell->exit_status = EXIT_PERMISSION_DENIED;
			if (stat(exec->args[0], &st) == 0 && S_ISDIR(st.st_mode))
				free_exit_error(shell, IS_DIRECTORY, exec->args[0]);
			free_exit_error(shell, PERMISSION_DENIED, exec->args[0]);
		}
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
	if (ft_strchr(exec->args[0], '/') != NULL)
	{
		if (safe_access(exec->args[0], F_OK) == 0)
			execve_ret = execve(exec->args[0], exec->args, exported_envs);
		handle_exec_error(execve_ret, exec, shell, TRUE);
	}
	path = get_path(shell);
	i = -1;
	while (path && path[++i])
	{
		path_cmd = ft_strjoin(path[i], exec->args[0]);
		if (safe_access(path_cmd, F_OK) == 0)
			execve_ret = execve(path_cmd, exec->args, exported_envs);
		free(path_cmd);
	}
	handle_exec_error(execve_ret, exec, shell, path && *path);
}
