#include "../../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ignore_spaces(char *cmd, int i)
{
	while (cmd[i] && ft_isspace(cmd[i]))
		i++;
	return (i);
}

int	ft_isword(char c)
{
	if (ft_isspace(c) || c == '\'' || c == '"'
		|| c == '|' || c == '$' || c == '>'
		|| c == '<')
		return (0);
	return (1);
}

int	check_malloc(void *ptr)
{
	if (!ptr)
	{
		printf("Malloc failed\n");
		return (1);
	}
	return (0);
}
