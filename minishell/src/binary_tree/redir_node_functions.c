#include "../../includes/minishell.h"

bool	is_last_redir(t_token *token)
{
	if (is_redir_token(token))
		return (false);
	token = get_next_redir(token);
	if (!token)
		return (true);
	return (false);
}

void	define_redir_file(t_redir *redir, t_token *token)
{
	if (!token->next)
	{
		redir->file = NULL;
		redir->file_status = NO_QUOTE;
	}
	else
	{
		redir->file = token->next->data;
		redir->file_status = token->next->quote;
	}
}

t_redir	*define_redir(t_shell *shell, void *down, t_token *token, bool reset_id)
{
	t_redir		*redir;
	t_node_type	node_type;
	static int	id = 0;

	if (reset_id == 1)
	{
		id = 0;
		return (NULL);
	}
	redir = ft_calloc(sizeof(t_redir), 1);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			redir, "Calloc failed");
	//REVIEW -> SÃO TIPOS DIFERENTES
	redir->type = token->type;
	define_redir_file(redir, token);
	if (down)
		redir->down = down;
	//REVIEW -> down pode ser o no exec ou um no redir
	// {
	// 	node_type = *(t_node_type *)down;
	// 	if (node_type == WORD)
	// 		redir->down = (t_exec *)down;
	// 	else if (node_type == REDIR_IN || node_type == REDIR_OUT
	// 		|| node_type == REDIR_APPEND || node_type == HEREDOC)
	// 		redir->down = (t_redir *)down;
	// }
	else
		redir->down = NULL;
	if (redir->type == HEREDOC)
	{
		redir->id = id;
		id++;
	}
	return (redir);
}

t_token	*get_previous_redir(t_token *token)
{
	if (!token)
		return (NULL);
	if (token->prev)
		token = token->prev;
	else
		return (NULL);
	while (token && token->type != PIPE)
	{
		if (is_redir_token(token))
			return (token);
		token = token->prev;
	}
	return (NULL);
}

t_token	*get_next_redir(t_token *token)
{
	if (!token)
		return (NULL);
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
