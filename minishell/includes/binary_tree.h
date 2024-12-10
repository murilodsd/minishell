/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:12:30 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 22:13:33 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H
# include "minishell.h"

// binary_tree.c
void	*build_tree(t_shell *shell, t_token *token);

// binary_tree_utils.c
t_token	*get_next_pipe(t_token *token);
bool	is_redir_token(t_token *token);
bool	is_redir_node_type(t_node_type node_type);
char	**get_args(t_shell *shell, t_token *token);

// redir_node_functions.c
t_token	*get_previous_redir(t_token *token);
t_redir	*create_redir_node(t_shell *shell, void *down, \
	t_token *token, bool reset_id);

#endif
