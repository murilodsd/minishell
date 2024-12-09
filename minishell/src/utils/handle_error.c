/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:20:20 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 15:29:02 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	errno_msg_error(char *error_msg, char *first_va_arg)
{
	if (errno == ENOENT)
		ft_printf(STDERR_FILENO, "minishell: %s%s: %s\n", \
			error_msg, first_va_arg, strerror(errno));
	else if (errno == EACCES)
		ft_printf(STDERR_FILENO, "minishell: %s: %s\n", \
			error_msg, strerror(errno));
	else
		ft_printf(STDERR_FILENO, "minishell: %s: %s\n", \
			error_msg, strerror(errno));
}

void	others_msg_error(t_error_codes error_code, char *error_msg)
{
	if (error_code == CMD_NOT_FOUND)
		ft_printf(STDERR_FILENO, "%s: command not found\n", error_msg);
	else if (error_code == NO_FILE_DIRECTORY)
		ft_printf(STDERR_FILENO, \
			"minishell: %s: No such file or directory\n", error_msg);
	else if (error_code == PERMISSION_DENIED)
		ft_printf(STDERR_FILENO, \
			"minishell: %s: Permission denied\n", error_msg);
	else if (error_code == AMBIGUOS_REDIRECT)
		ft_printf(STDERR_FILENO, \
			"minishell: ambiguous redirect\n", error_msg);
	else if (error_code == IS_DIRECTORY)
		ft_printf(STDERR_FILENO, \
			"minishell: %s: Is a directory\n", error_msg);
	else if (error_code == IS_NOT_DIRECTORY)
		ft_printf(STDERR_FILENO, \
			"minishell: %s: Not a directory\n", error_msg);
	else if (error_code == TOO_MANY_ARGS)
		ft_printf(STDERR_FILENO, \
			"minishell: %s: too many arguments\n", error_msg);
	else if (error_code == SYNTAX_ERROR)
		ft_printf(STDERR_FILENO, \
			"minishell: syntax error near unexpected token `%s'\n", error_msg);
	else
		ft_printf(STDERR_FILENO, "%s\n", error_msg);
}

void	msg_error(t_error_codes error_code, char *error_msg, ...)
{
	va_list	va_args;

	va_start(va_args, error_msg);
	if (errno != 0)
		errno_msg_error(error_msg, va_arg(va_args, char *));
	else
	{
		if (error_code == NOT_VALID_IDENTIFIER)
			ft_printf(STDERR_FILENO, \
				"minishell: %s: `%s': not a valid identifier\n", \
				error_msg, va_arg(va_args, char *));
		else if (error_code == VAR_NOT_SET)
			ft_printf(STDERR_FILENO, \
				"minishell: %s: `%s' not set\n", \
				error_msg, va_arg(va_args, char *));
		else if (error_code == NUMERIC_ARGUMENT_REQUIRED)
			ft_printf(STDERR_FILENO, \
				"minishell: %s: %s: numeric argument required\n", \
				error_msg, va_arg(va_args, char *));
		else
			others_msg_error(error_code, error_msg);
	}
	va_end(va_args);
	errno = 0;
}
