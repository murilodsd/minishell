/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_execve.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:04:04 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 21:50:04 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

static void	fork_execute_execve(t_shell *shell, void *root)
{
	int	child_exit_status;

	ignore_sig_int_and_quit();
	if (safe_fork(shell, NULL) == 0)
	{
		shell->process = CHILD;
		reset_sig_int_and_quit();
		execute_execve(shell, root);
		free_exit(shell);
	}
	wait(&child_exit_status);
	shell->exit_status = get_child_status(child_exit_status);
}

static void	choose_builtin_or_execve(t_shell *shell, t_exec *exec, bool is_root)
{
	if (!ft_strcmp(exec->args[0], "echo"))
		echo_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "export"))
		export_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "env"))
		env_builtin(shell, exec->args, is_root);
	else if (!ft_strcmp(exec->args[0], "unset"))
		unset_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "pwd"))
		pwd_builtin(shell);
	else if (!ft_strcmp(exec->args[0], "cd"))
		cd_builtin(shell, exec->args);
	else if (!ft_strcmp(exec->args[0], "exit"))
		exit_builtin(shell, exec->args, is_root);
	else
	{
		if (is_root)
			fork_execute_execve(shell, exec);
		else
			execute_execve(shell, exec);
	}
}

void	execute_builtin_or_execve(t_shell *shell, t_exec *exec, bool is_root)
{
	if (!exec || !exec->args[0])
		return ;
	if (exec->args[0][0] == '\0')
	{
		shell->exit_status = EXIT_CMD_NOT_FOUND;
		msg_error(CMD_NOT_FOUND, exec->args[0]);
	}
	else
		choose_builtin_or_execve(shell, exec, is_root);
	if (!is_root)
		free_exit(shell);
}
