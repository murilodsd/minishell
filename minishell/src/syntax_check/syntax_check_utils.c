#include "../../includes/minishell.h"

int	ignore_quotes(char *cmd, int i)
{
	if (cmd[i] == '\'')
	{
		i++;
		while (cmd[i] && cmd[i] != '\'')
			i++;
	}
	else if (cmd[i] == '\"')
	{
		i++;
		while (cmd[i] && cmd[i] != '\"')
			i++;
	}
	return (i);
}

int	is_redir(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int	analyze_redir(char *cmd, int i)
{
	if (is_redir(cmd[i + 1]))
	{
		if (cmd[i] == '>' && cmd[i + 1] == '>')
			return (APPEND_ERROR);
		else if (cmd[i] == '<' && cmd[i + 1] == '<')
			return (HEREDOC_ERROR);
	}
	if (cmd[i] == '>')
		return (R_OUT_ERROR);
	if (cmd[i] == '<')
		return (R_IN_ERROR);
	return (-1);
}
