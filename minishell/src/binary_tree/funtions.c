#include "../../includes/minishell.h"

t_token	*get_next_redir(t_token *token)
{
	if (token->next)
		token = token->next;
	else
		return (NULL);
	while (token && token->type != PIPE)
	{
		if (is_redir_token(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}