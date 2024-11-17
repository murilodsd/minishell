#include "../../includes/minishell.h"

int	ft_isword(char c)
{
	if (ft_isspace(c) || c == '\'' || c == '"'
		|| c == '|' || c == '$' || c == '>'
		|| c == '<')
		return (0);
	return (1);
}

void	clear_list(t_token **token)
{
	t_token	*tmp;

	while (*token)
	{
		tmp = *token;
		*token = (*token)->next;
		free(tmp->data);
		free(tmp);
	}
}
char	*format_data_parentheses(const char *data)
{
	size_t	len = strlen(data);
	char	*formatted = malloc(len + 3);
	if (!formatted)
		return "(allocation failed)";
	formatted[0] = '(';
	strcpy(formatted + 1, data);
	formatted[len + 1] = ')';
	formatted[len + 2] = '\0';
	return formatted;
}

const char	*get_token_type_str(t_token_type type)
{
	if (type == WORD)
		return "Word";
	else if (type == PIPE)
		return "Pipe";
	else if (type == REDIR_IN)
		return "Redir in";
	else if (type == REDIR_OUT)
		return "Redir out";
	else if (type == REDIR_APPEND)
		return "Redir app";
	else if (type == HEREDOC)
		return "Heredoc";
	else if (type == SINGLE_QUOTE)
		return "S Quote";
	else if (type == DOUBLE_QUOTE)
		return "D Quote";
	else if (type == ENV_VAR)
		return "Env var";
	else if (type == FILENAME)
		return "Filename";
	return "Unknown";
}

const char	*get_token_quote_str(t_token_quote quote)
{
	if (quote == NO_QUOTE)
		return "No quote";
	else if (quote == SINGLE)
		return "Single";
	else if (quote == DOUBLE)
		return "Double";
	return "Unknown";
}
void	print_list(t_token *token)
{
	t_token	*tmp;
	int		index;

	printf("+-------+----------------------------------------------------+------------+------------+\n");
	printf("| Index | Data                                               | Type       | Quote      |\n");
	printf("+-------+----------------------------------------------------+------------+------------+\n");
	tmp = token;
	index = 0;
	while (tmp)
	{
		printf("| %-5d | %-50.50s | %-10.10s | %-10.10s |\n",
			index,
			tmp->data ? format_data_parentheses(tmp->data) : "(null)",
			get_token_type_str(tmp->type),
			get_token_quote_str(tmp->quote));
		printf("+-------+----------------------------------------------------+------------+------------+\n");
		tmp = tmp->next;
		index++;
	}
	printf("\n");
}
