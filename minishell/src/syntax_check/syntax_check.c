#include "../../includes/minishell.h"

int	check_redirect(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i] == '<')
		return (1);
	while (cmd[i])
	{
		if ((cmd[i] == '>' || cmd[i] == '<')
			&& (cmd[i + 1] == cmd[i]) && cmd[i + 2] == cmd[i])
			return (1);
		if ((cmd[i] == '<' || cmd[i] == '>') && cmd[i + 1] == '\0')
			return (1);
		if (cmd[i] == '<' || cmd[i] == '>')
		{
			i++;
			while (cmd[i] && cmd[i] == ' ')
				i++;
			if ((cmd[i] == '<' || cmd[i] == '>' || cmd[i] == '\0'))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_quotes(char *cmd)
{
	int	i;
	int	single_quote;
	int	double_quote;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			if (cmd[i] == '\'' && !single_quote)
				single_quote = 1;
			else if (cmd[i] == '\'' && single_quote)
				single_quote = 0;
			if (cmd[i] == '\"' && !double_quote)
				double_quote = 1;
			else if (cmd[i] == '\"' && double_quote)
				double_quote = 0;
		}
		i++;
	}
	if (single_quote || double_quote)
		return (1);
	return (0);
}

int	check_pipe(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i] == '|')
		return (1);
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
			i = ignore_quotes(cmd, i);
		if (cmd[i] == '|' && (cmd[i + 1] == '|'
			|| cmd[i + 1] == '\0'))
			return (1);
		if (cmd[i] == '|')
		{
			i++;
			while (cmd[i] && cmd[i] == ' ')
				i++;
			if (cmd[i] == '|' || cmd[i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_space(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i] == '\0')
		return (1);
	return (0);
}

int	syntax_check(char *cmd)
{
	if (check_space(cmd))
		return (1);
	else if (check_quotes(cmd))
		msg_error(SYNTAX_ERROR, "open quote");
	else if (check_pipe(cmd))
		msg_error(SYNTAX_ERROR, "|");
	else if (check_redirect(cmd))
		msg_error(SYNTAX_ERROR, "redirect");
	else
		return (0);
	return (1);
}
