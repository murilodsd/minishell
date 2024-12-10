/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:19:21 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/08 20:22:53 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_pipe	*build_pipe(t_shell *shell, void *left, void *right)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof(t_pipe));
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				pipe, "Calloc failed");
	pipe->left = left;
	pipe->right = right;
	pipe->type = PIPE_NODE;
	return (pipe);
}

void	*build_redir(t_shell *shell, void *down, t_token *token)
{
	t_token	*end_of_the_command;
	t_token	*last_redir;
	void	*root;

	root = NULL;
	end_of_the_command = get_next_pipe(token);
	if (!end_of_the_command)
		end_of_the_command = last_token(token);
	last_redir = get_previous_redir(end_of_the_command);
	if (last_redir)
	{
		root = create_redir_node(shell, down, last_redir, FALSE);
		token = get_previous_redir(last_redir);
		while (is_redir_token(token))
		{
			root = create_redir_node(shell, root, token, 0);
			token = get_previous_redir(token);
		}
	}
	if (!root)
		return (down);
	return (root);
}

void	*build_exec(t_shell *shell, t_token *token)
{
	void	*root;
	t_exec	*exec;
	char	**args;

	args = get_args(shell, token);
	if (args != NULL)
	{
		exec = ft_calloc(sizeof(t_exec), 1);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				exec, "Calloc failed");
		exec->args = args;
		exec->type = EXEC_NODE;
	}
	else
		exec = NULL;
	root = build_redir(shell, exec, token);
	return (root);
}

void	*build_tree(t_shell *shell, t_token *token)
{
	void	*root;
	t_token	*pipe_token;

	root = build_exec(shell, token);
	pipe_token = get_next_pipe(token);
	if (pipe_token != NULL)
		root = build_pipe(shell, root, build_tree(shell, pipe_token->next));
	return (root);
}
