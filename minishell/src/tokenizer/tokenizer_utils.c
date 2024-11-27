#include "../../includes/minishell.h"

int	ft_isword(char c)
{
	if (ft_isspace(c) || c == '\'' || c == '"'
		|| c == '|' || c == '$' || c == '>'
		|| c == '<')
		return (0);
	return (1);
}

void	take_out_quotes(char **data, t_token_quote quote)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = malloc(ft_strlen(*data) + 1);
	if (check_malloc(tmp))
		return ;
	while ((*data)[i])
	{
		while ((*data)[i] == '\'' && quote == SINGLE)
			i++;
		while ((*data)[i] == '\"' && quote == DOUBLE)
			i++;
		tmp[j] = (*data)[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free(*data);
	*data = tmp;
}

void	add_quote_token(char quote, char *cmd, int i, t_shell *shell)
{
	if (quote == '\"')
		add_token(&shell, ft_substr(cmd, i + 1, 1), ENV_VAR_NAME, DOUBLE);
	else if (quote == '\'')
		add_token(&shell, ft_substr(cmd, i + 1, 1), ENV_VAR_NAME, SINGLE);
}
