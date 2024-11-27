#include "../../includes/minishell.h"

bool	last_redir(t_token *token)
{
	if (token->type != REDIR_IN && token->type != REDIR_OUT
		&& token->type != REDIR_APPEND && token->type != HEREDOC)
		return (false);
	token = get_next_redir(token);
	if (!token)
		return (true);
	return (false);
}

bool	is_redir_token(t_token *token)
{
	if (!token)
		return (false);
	if (token->type == REDIR_IN || token->type == REDIR_APPEND
		|| token->type == REDIR_OUT || token->type == HEREDOC)
		return (true);
	return (false);
}
