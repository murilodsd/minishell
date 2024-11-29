#ifndef BINARY_TREE_H
# define BINARY_TREE_H
# include "minishell.h"

void	binary_tree(t_shell *shell);
void	*build_tree(t_shell *shell, t_token *token);

// binary_tree_utils.c
t_token	*get_next_pipe(t_token *token);
bool	is_redir_token(t_token *token);
char	**get_args(t_shell *shell, t_token *token);

// redir_node_functions.c
t_token	*get_previous_redir(t_token *token);
t_token	*get_next_redir(t_token *token);
t_redir	*create_redir_node(t_shell *shell, void *down, t_token *token, bool reset_id);


#endif
