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
