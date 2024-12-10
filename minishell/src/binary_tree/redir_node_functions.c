/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_node_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:11:37 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/08 20:13:58 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		redir->env_var_name = token->next->env_var_name;
	}
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
		else
			return ((t_redir *)down);
	}
	else
		return (NULL);
}

t_redir	*create_redir_node(t_shell *shell, void *down, t_token *token, \
	bool reset_id)
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
