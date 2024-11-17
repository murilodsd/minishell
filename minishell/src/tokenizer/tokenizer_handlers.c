#include "../../includes/minishell.h"

int	handle_s_quotes(char *cmd, int i, t_shell *shell)
{
	int j;
	char	*tmp;

	j = i + 1;
	j = ignore_quotes(cmd, j);
	while (cmd[j] && cmd[j] != '\'')
		j++;
	tmp = ft_substr(cmd, i + 1, j - i - 1);
	if (tmp)
		add_token(&shell, tmp, WORD, SINGLE);
	return (j);
}

int	handle_d_quotes(char *cmd, int i, t_shell *shell)
{
	int j;
	char	*tmp;

	j = i + 1;
	j = ignore_quotes(cmd, j);
	while (cmd[j] && cmd[j] != '\"')
		j++;
	tmp = ft_substr(cmd, i + 1, j - i - 1);
	if (tmp)
		add_token(&shell, tmp, WORD, DOUBLE);
	return (j);
}

int	handle_pipe(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	tmp = ft_substr(cmd, i, 1);
	if (tmp)
		add_token(&shell, tmp, PIPE, NO_QUOTE);
	return (i);
}

int handle_env_var(char *cmd, int i, t_shell *shell)
{
	char	*tmp;

	tmp = ft_substr(cmd, i, 1);
	if (tmp)
		add_token(&shell, tmp, ENV_VAR, NO_QUOTE);
	return (i);
}


