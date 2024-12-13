/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:13:13 by dramos-j          #+#    #+#             */
/*   Updated: 2024/12/13 11:56:10 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_redir(char *cmd)
{
	int	i;

	i = ignore_spaces(cmd, 0);
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
			i = ignore_quotes(cmd, i);
		else if (is_redir(cmd[i]))
		{
			if (cmd[i + 1] == cmd[i])
				i++;
			i = ignore_spaces(cmd, i + 1);
			if (cmd[i] == '\0')
				return (NO_ARGS);
			else if (cmd[i] == '|')
				return (PIPE_ARG_ERROR);
			else if (is_redir(cmd[i]))
				return (analyze_error_redir(cmd, i));
		}
		else
			i++;
	}
	return (-1);
}

int	check_pipe(char *cmd)
{
	int	i;

	i = ignore_spaces(cmd, 0);
	if (cmd[i] == '|')
		return (1);
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
			i = ignore_quotes(cmd, i);
		if (is_redir(cmd[i]) && check_redir(cmd) != -1)
			return (0);
		else if (cmd[i] == '|' && (cmd[i + 1] == '|'
				|| cmd[ignore_spaces(cmd, i + 1)] == '|'))
			return (1);
		else if (cmd[i] == '|' && (cmd[i + 1] == '\0'
				|| cmd[ignore_spaces(cmd, i + 1)] == '\0'))
			return (2);
		i++;
	}
	return (0);
}

int	check_quotes(char *cmd)
{
	int	i;

	i = ignore_spaces(cmd, 0);
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			i++;
			while (cmd[i] && cmd[i] != '\'')
				i++;
			if (cmd[i] == '\0')
				return (1);
		}
		else if (cmd[i] == '\"')
		{
			i++;
			while (cmd[i] && cmd[i] != '\"')
				i++;
			if (cmd[i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_spaces(char *cmd)
{
	int	i;

	i = ignore_spaces(cmd, 0);
	if (cmd[i] == '\0')
		return (1);
	return (0);
}

int	syntax_check(char *cmd)
{
	int	pipe_check;
	int	redir_check;

	if (check_spaces(cmd))
		return (2);
	else if (check_quotes(cmd))
		msg_error(SYNTAX_ERROR, "open quote");
	else if (check_pipe(cmd))
	{
		pipe_check = check_pipe(cmd);
		if (pipe_check == 1)
			msg_error(SYNTAX_ERROR, "|");
		else if (pipe_check == 2)
			msg_error(SYNTAX_ERROR, "newline");
	}
	else if (check_redir(cmd) != -1)
	{
		redir_check = check_redir(cmd);
		msg_error_redir(redir_check);
	}
	else
		return (0);
	return (1);
}
