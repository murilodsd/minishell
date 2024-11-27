#include "../../includes/minishell.h"

bool	is_redir_token(t_token *token)
{
	if (!token)
		return (false);
	if (token->type == REDIR_IN || token->type == REDIR_APPEND
		|| token->type == REDIR_OUT || token->type == HEREDOC)
		return (true);
	return (false);
}
