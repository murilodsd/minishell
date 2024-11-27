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

void	msg_error_redir(int redir_check)
{
	if (redir_check == NO_ARGS)
		msg_error(SYNTAX_ERROR, "newline");
	else if (redir_check == R_OUT_ERROR)
		msg_error(SYNTAX_ERROR, ">");
	else if (redir_check == R_IN_ERROR)
		msg_error(SYNTAX_ERROR, "<");
	else if (redir_check == APPEND_ERROR)
		msg_error(SYNTAX_ERROR, ">>");
	else if (redir_check == HEREDOC_ERROR)
		msg_error(SYNTAX_ERROR, "<<");
	else if (redir_check == PIPE_ARG_ERROR)
		msg_error(SYNTAX_ERROR, "|");
}
