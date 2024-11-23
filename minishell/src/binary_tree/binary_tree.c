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

	pipe = ft_calloc(1, sizeof(t_pipe));
	pipe->left = left;
	pipe->right = right;
	pipe->type = PIPE;
	return (pipe);
}

char	**get_args(t_shell *shell, t_token *token)
{
	int	i;
	t_token	*tmp;
	char	**args;

	i = 0;
	tmp = token;
	while (token->type == WORD)
	{
		tmp = tmp->next;
		i++;
	}
	args = ft_calloc(i + 1, sizeof(char *));
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
			args, "Calloc failed");
	while(i--)
	{
		args[i] = ft_dup(tmp->data);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			args[i], "Calloc failed");
		tmp = tmp->prev;
	}
	return (args);
}

t_exec	*build_exec(t_shell *shell, t_token *token)
{
	t_exec	*exec;
	char	**args;

	exec = ft_calloc(sizeof(t_exec), 1);
	args = get_args(shell, token);
	return (exec);
}
void	*build_tree(t_shell *shell, t_token *token)
{
	void	*root;

	//TODO -> setar o root igual saida do exec;
	root = build_exec(shell, token);
	
	if (get_next_pipe(token) != NULL)
		root = build_pipe(root, build_tree(shell, get_next_pipe(token)->next));
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
