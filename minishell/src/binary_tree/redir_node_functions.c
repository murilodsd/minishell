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
	//REVIEW -> Precisavam mesmo dessa verificação? Não vai sempre existir o nome do arquivo?
	if (!token->next)
	{
		redir->file = NULL;
		redir->file_status = NO_QUOTE;
	}
	else
	{
		redir->file = token->next->data;
		redir->file_status = token->next->quote;
		redir->env_var_name = token->env_var_name;
	}
	printf("env_var_name %s\n", redir->env_var_name);
}

t_node_type	get_redir_node_type(t_token *token)
{
	if (!token)
		return (-1);
	if (token->type == REDIR_IN)
		return (REDIR_IN_NODE);
	else if (token->type == REDIR_OUT)
		return (REDIR_OUT_NODE);
	else if (token->type == REDIR_APPEND)
		return (REDIR_APPEND_NODE);
	else
		return (HEREDOC_NODE);
}

void	*get_redir_down_node(void *down)
{
	t_node_type	node_type;

	if (down)
	{
		node_type = *(t_node_type *)down;
		if (node_type == EXEC_NODE)
			return ((t_exec *)down);
		//REVIEW -> acho que poderia ser só um else
		// else if (node_type == REDIR_IN_NODE || node_type == REDIR_OUT_NODE
		// 	|| node_type == REDIR_APPEND_NODE || node_type == HEREDOC_NODE)
		else
			return ((t_redir *)down);
	}
	else
		return (NULL);
}

t_redir	*create_redir_node(t_shell *shell, void *down, t_token *token, bool reset_id)
{
	t_redir		*redir;
	static int	id = 0;

	if (reset_id == TRUE)
	{
		id = 0;
		return (NULL);
	}
	redir = ft_calloc(sizeof(t_redir), 1);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			redir, "Calloc failed");
	redir->down = get_redir_down_node(down);
	//REVIEW -> APAGAR PRINT
	//printf("tipo do token redir: %s\n", token->data);
	redir->type = get_redir_node_type(token);
	define_redir_file(redir, token);
	if (redir->type == HEREDOC_NODE)
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
