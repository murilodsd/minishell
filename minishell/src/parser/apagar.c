#include "../../includes/minishell.h"

void	clear_list(t_token **lst)
{
	t_token	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->data)
			free(tmp->data);
		if (tmp)
			free(tmp);
	}
}

char	*format_data_parentheses(const char *data)
{
	size_t	len;
	char	*formatted;

	len = ft_strlen(data);
	formatted = malloc(len + 3);
	if (!formatted)
		return ("(allocation failed)");
	formatted[0] = '(';
	ft_strcpy(formatted + 1, (char *)data);
	formatted[len + 1] = ')';
	formatted[len + 2] = '\0';
	return (formatted);
}

const char	*get_token_type_str(t_token_type type)
{
	if (type == WORD)
		return ("Word");
	else if (type == COMMAND)
		return ("Command");
	else if (type == COMMAND_ARG)
		return ("Command arg");
	else if (type == PIPE)
		return ("Pipe");
	else if (type == REDIR_IN)
		return ("Redir in");
	else if (type == REDIR_IN_FILE)
		return ("Redir in file");
	else if (type == REDIR_OUT)
		return ("Redir out");
	else if (type == REDIR_OUT_FILE)
		return ("Redir out file");
	else if (type == REDIR_APPEND)
		return ("Redir app");
	else if (type == REDIR_APPEND_FILE)
		return ("Redir app file");
	else if (type == HEREDOC)
		return ("Heredoc");
	else if (type == EOF_TOKEN)
		return ("EOF");
	else if (type == ENV_VAR)
		return ("Env var");
	else if (type == ENV_VAR_EXIT_CODE)
		return ("Env var exit code");
	else if (type == ENV_VAR_NAME)
		return ("Env var name");
	else if (type == SPACE_TOKEN)
		return ("Space");
	else if (type == NULL_TOKEN)
		return ("Null");
	else
		return ("Unknown");
}

const char	*get_token_quote_str(t_token_quote quote)
{
	if (quote == NO_QUOTE)
		return ("No quote");
	else if (quote == SINGLE)
		return ("Single");
	else if (quote == DOUBLE)
		return ("Double");
	return ("Unknown");
}

void	print_list(t_token *token)
{
	t_token	*tmp;
	int		index;
	char	*formatted_data;

	printf("+-------+----------------------------------------------------+----------------------+------------+\n");
	printf("| Index | Data                                               | Type                 | Quote      |\n");
	printf("+-------+----------------------------------------------------+----------------------+------------+\n");
	tmp = token;
	index = 0;
	while (tmp)
	{
		formatted_data = tmp->data ? format_data_parentheses(tmp->data) : NULL;
		printf("| %-5d | %-50.50s | %-20.15s | %-10.10s |\n",
			index,
			formatted_data,
			get_token_type_str(tmp->type),
			get_token_quote_str(tmp->quote));
		printf("+-------+----------------------------------------------------+----------------------+------------+\n");
		if (ft_strcmp(formatted_data, "(null)") != 0)
			free(formatted_data);
		tmp = tmp->next;
		index++;
	}
}
