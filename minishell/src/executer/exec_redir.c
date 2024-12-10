/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:15:24 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 17:05:36 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_redir_root(t_redir *redir, t_shell *shell)
{
	if (execute_redirect(shell, redir, TRUE) && redir->down)
		execute_root_node(shell, redir->down);
	if (shell->fd_in != -1)
		close(shell->fd_in);
	if (shell->fd_out != -1)
		close(shell->fd_out);
	shell->fd_in = open("/dev/tty", O_RDONLY);
	if (shell->fd_in == -1)
		free_exit_error(shell, GENERAL_ERROR, \
			"Error opening /dev/tty for reading");
	shell->fd_out = open("/dev/tty", O_WRONLY);
	if (shell->fd_out == -1)
		free_exit_error(shell, GENERAL_ERROR, \
			"Error opening /dev/tty for writing");
}

bool	is_there_a_file(t_shell *shell, t_redir *redir, bool is_root)
{
	if (!redir->file[0] && redir->env_var_name)
	{
		shell->exit_status = EXIT_FAILURE;
		if (!is_root)
			free_exit_error(shell, AMBIGUOS_REDIRECT, redir->env_var_name);
		else
		{
			msg_error(AMBIGUOS_REDIRECT, redir->env_var_name);
			return (FALSE);
		}
	}
	else if (!redir->file[0])
	{
		shell->exit_status = EXIT_FAILURE;
		if (!is_root)
			free_exit_error(shell, NO_FILE_DIRECTORY, redir->env_var_name);
		else
		{
			msg_error(NO_FILE_DIRECTORY, redir->file);
			return (FALSE);
		}
	}
	return (TRUE);
}

int	redirect_out(t_shell *shell, t_redir *redir, bool is_root)
{
	if (shell->fd_out != -1)
		close (shell->fd_out);
	if (redir->type == REDIR_OUT_NODE)
		shell->fd_out = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		shell->fd_out = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (shell->fd_out == -1)
	{
		shell->exit_status = EXIT_FAILURE;
		if (!is_root)
			free_exit_error(shell, PERMISSION_DENIED, redir->file);
		else
		{
			msg_error(PERMISSION_DENIED, redir->file);
			return (FALSE);
		}
	}
	return (TRUE);
}

bool	redirect_in(t_shell *shell, t_redir *redir, bool is_root)
{
	if (safe_access(redir->file, F_OK) != 0)
	{
		msg_error(NO_FILE_DIRECTORY, redir->file);
		if (!is_root)
		{
			shell->exit_status = EXIT_FAILURE;
			free_exit(shell);
		}
		shell->exit_status = EXIT_SUCCESS;
		return (FALSE);
	}
	if (shell->fd_in != -1)
		close(shell->fd_in);
	shell->fd_in = open(redir->file, O_RDONLY);
	if (shell->fd_in == -1)
	{
		shell->exit_status = EXIT_FAILURE;
		if (!is_root)
			free_exit_error(shell, PERMISSION_DENIED, redir->env_var_name);
		msg_error(NO_FILE_DIRECTORY, redir->file);
		return (FALSE);
	}
	return (TRUE);
}

int	execute_redirect(t_shell *shell, t_redir *redir, bool is_root)
{
	if (!is_there_a_file(shell, redir, is_root))
		return (FALSE);
	if (redir->type == REDIR_OUT_NODE || redir->type == REDIR_APPEND_NODE)
		return (redirect_out(shell, redir, is_root));
	else
		return (redirect_in(shell, redir, is_root));
}
