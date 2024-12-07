#include "../../includes/minishell.h"

void	handle_error(void)
{
	printf("Error\n");
}

void	free_all(t_shell *shell)
{
	if (shell->fd_out != -1)
		close(shell->fd_out);
	if (shell->fd_in != -1)
		close(shell->fd_in);
	if (shell->token)
		clear_token_list(shell);
	if (shell->mem_allocation.ptr_mem_list != NULL)
		ft_lstclear(&(shell->mem_allocation.ptr_mem_list), free);
	if (shell->mem_allocation.matrix_mem_list != NULL)
		ft_lstclear(&(shell->mem_allocation.matrix_mem_list), ft_free_matrix);
	if (shell->token)
		clear_token_list(shell);
	if (shell->heredoc)
		clear_heredoc_list(shell);
	free(shell);
}

void	msg_error(t_error_codes error_code, char *error_msg, ...)
{
	va_list	va_args;

	va_start(va_args, error_msg);
	if (errno != 0)
	{
		if (errno == ENOENT)
			ft_printf(STDERR_FILENO, "minishell: %s%s: %s\n", error_msg, va_arg(va_args, char *), strerror(errno));
		else
			ft_printf(STDERR_FILENO, "minishell: %s%s\n", error_msg, strerror(errno));
	}
	else
	{
		if (error_code == CMD_NOT_FOUND)
			ft_printf(STDERR_FILENO, "%s: command not found\n", error_msg);
		else if (error_code == NO_FILE_DIRECTORY)
			ft_printf(STDERR_FILENO, "minishell: %s: No such file or directory\n",
				error_msg);
		else if (error_code == PERMISSION_DENIED)
			ft_printf(STDERR_FILENO, "minishell: %s: Permission denied\n", error_msg);
		else if (error_code == AMBIGUOS_REDIRECT)
			ft_printf(STDERR_FILENO, "minishell: ambiguous redirect\n", error_msg);
		else if (error_code == IS_DIRECTORY)
			ft_printf(STDERR_FILENO, "minishell: %s: Is a directory\n", error_msg);
		else if (error_code == IS_NOT_DIRECTORY)
			ft_printf(STDERR_FILENO, "minishell: %s: Not a directory\n", error_msg);
		else if (error_code == TOO_MANY_ARGS)
			ft_printf(STDERR_FILENO, "minishell: %s: too many arguments\n", error_msg);
		else if (error_code == SYNTAX_ERROR)
			ft_printf(STDERR_FILENO, "minishell: syntax error near unexpected token `%s'\n", error_msg);
		else if (error_code == NOT_VALID_IDENTIFIER)
			ft_printf(STDERR_FILENO, "minishell: %s: `%s': not a valid identifier\n", error_msg, va_arg(va_args, char *));
		else if (error_code == VAR_NOT_SET)
			ft_printf(STDERR_FILENO, "minishell: %s: `%s' not set\n", error_msg, va_arg(va_args, char *));
		else if (error_code == NUMERIC_ARGUMENT_REQUIRED)
			ft_printf(STDERR_FILENO, "minishell: %s: %s: numeric argument required\n", error_msg, va_arg(va_args, char *));
		else
			ft_printf(STDERR_FILENO, "%s\n", error_msg);
	va_end(va_args);
	}
	errno = 0;
}

void	free_exit_error(t_shell *shell, t_error_codes error_code, char *error_msg)
{
	if (!shell->exit_status)
		shell->exit_status = 1;
	if (error_msg)
		msg_error(error_code, error_msg);
	free_exit(shell);
}

void	free_exit(t_shell *shell)
{
	int	exit_status;

	exit_status = shell->exit_status;
	free_all(shell);
	exit(exit_status);
}
