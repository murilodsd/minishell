#include "../../includes/minishell.h"

void	binary_tree(t_shell *shell)
{
	t_token		*token;

	token = get_next_pipe(shell->token);
	ft_printf(1, "antes do pipe: %s depois do pipe %s", token->prev->prev->data, token->next->next->data);
	token = token->next;
	token = get_next_pipe(shell->token);
	ft_printf(1, "antes do pipe: %s depois do pipe %p", token->prev->prev->data, token->next);
}

t_pipe	*build_pipe(void *left, void *right)
{
	t_pipe	*pipe;

	pipe = ft_calloc(sizeof(t_pipe), 1);
	pipe->left = left;
	pipe->right = right;
	pipe->type = PIPE;
	return (pipe);
}

void	*build_tree(void *token)
{
	void	*root;

	//TODO -> setar o root igual saida do exec;
	root = token;
	
	if (get_next_pipe(token) != NULL)
		root = build_pipe(root, build_tree(get_next_pipe(token)->next));
	(void)token;
	return (NULL);

}

t_token	*get_next_pipe(t_token *token)
{
	while (token)
	{
		if (token->type == PIPE)
			return (token);
		token = token->next;
	}
	return (NULL);
}
