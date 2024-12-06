#include "../../includes/minishell.h"

void	execute_redir_root(t_redir *redir, t_shell *shell)
{
	int	new_fd_to_stdout;
	int	new_fd_to_stdin;

	new_fd_to_stdout = dup(STDOUT_FILENO);
	new_fd_to_stdin = dup(STDIN_FILENO);
	if (execute_redirect(shell, redir, TRUE))
		execute_root_node(redir->down, shell);
	dup2(new_fd_to_stdout, STDOUT_FILENO);
	dup2(new_fd_to_stdin, STDIN_FILENO);
	close(new_fd_to_stdout);
	close(new_fd_to_stdin);
}

bool	is_there_a_file(t_shell *shell, t_redir *redir, bool is_root)
{
	if (!redir->file)
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
	if (!redir->file[0])
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
	int	fd;

	fd = 0;
	if (redir->type == REDIR_OUT_NODE)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
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
	else
		dup2(fd, STDOUT_FILENO);
	return (TRUE);
}

bool	redirect_in(t_shell *shell, t_redir *redir, bool is_root)
{
	int	fd;

	fd = 0;
	if (access(redir->file, F_OK) != 0)
	{
		shell->exit_status = EXIT_FAILURE;
		if (!is_root)
			free_exit_error(shell, NO_FILE_DIRECTORY, redir->file);
		else
		{
			msg_error(NO_FILE_DIRECTORY, redir->file);
			return (FALSE);
		}
	}
	fd = open(redir->file, O_RDONLY);
	if (fd == -1)
	{
		shell->exit_status = EXIT_FAILURE;
		if (!is_root)
			free_exit_error(shell, PERMISSION_DENIED, redir->env_var_name);
		else
		{
			msg_error(NO_FILE_DIRECTORY, redir->file);
			return (FALSE);
		}
	}
	else
		dup2(fd, STDIN_FILENO);
	return (TRUE);
}

int	execute_redirect(t_shell *shell, t_redir *redir, bool is_root)
{
	if (!is_there_a_file(shell, redir, is_root))
		return (FALSE);	
	if (redir->type == REDIR_OUT_NODE || redir->type == REDIR_APPEND_NODE)
		return (redirect_out(shell, redir, is_root));
	else
		return(redirect_in(shell, redir, is_root));
}