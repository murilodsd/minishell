/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:21:02 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 11:02:06 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_tree(t_shell *shell, void *root)
{
	t_node_type	node_type;

	if (!root)
		return ;
	node_type = *(t_node_type *)root;
	if (node_type == EXEC_NODE)
		execute_builtin_or_execve(shell, (t_exec *)root, FALSE);
	else if (is_redir_node_type(node_type))
	{
		if (execute_redirect(shell, (t_redir *)root, FALSE) && \
			((t_redir *)root)->down)
			execute_tree(shell, ((t_redir *)root)->down);
	}
	else if (node_type == PIPE_NODE)
		execute_pipe(shell, (t_pipe *)root);
}

void	execute_root_node(t_shell *shell, void *root)
{
	t_node_type	node_type;

	node_type = *((t_node_type *)root);
	if (node_type == EXEC_NODE)
		execute_builtin_or_execve(shell, (t_exec *)root, TRUE);
	else if (node_type == REDIR_IN_NODE || node_type == REDIR_OUT_NODE
		|| node_type == REDIR_APPEND_NODE || node_type == HEREDOC_NODE)
		execute_redir_root((t_redir *)root, shell);
}

void	executer(t_shell *shell, void *root)
{
	if (!root)
		return ;
	if (*((t_node_type *)root) != PIPE_NODE)
		execute_root_node(shell, root);
	else
		execute_tree(shell, root);
}
