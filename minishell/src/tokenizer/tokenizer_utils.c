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
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), tmp,
//		"Tmp malloc failed");
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
