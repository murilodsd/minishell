#ifndef BINARY_TREE_H
# define BINARY_TREE_H
# include "minishell.h"

void	binary_tree(t_shell *shell);

// binary_tree_utils.c
t_token	*get_next_pipe(t_token *token);
bool	is_redir_token(t_token *token);

// redir_node_functions.c
t_token	*get_previous_redir(t_token *token);
t_token	*get_next_redir(t_token *token);
t_redir	*define_redir(t_shell *shell, void *down, t_token *token, int flag);


#endif
