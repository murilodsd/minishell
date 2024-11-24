#include "../../includes/minishell.h"

char	**get_args(t_shell *shell, t_token **token)
{
	int	i;
	t_token	*tmp;
	char	**args;

	i = 0;
	tmp = *token;
	ft_printf(1,BLUE"Primeiro token = %i\n"RESET, tmp->type);
	while (tmp->type != PIPE && tmp->type != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	ft_printf(1,BLUE"Qunatidade de tokens %i\n"RESET, i);
	ft_printf(1,BLUE"Token que não é palavra = %i\n"RESET, tmp->type);
	*token = tmp;
	args = ft_calloc(i + 1, sizeof(char *));
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
			args, "Calloc failed");
	tmp = tmp->prev;
	while(i--)
	{
		ft_printf(1,BLUE"ARGS[%i] = %s\n"RESET, i, tmp->data);
		args[i] = ft_strdup(tmp->data);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			args[i], "Calloc failed");
		tmp = tmp->prev;
	}
	return (args);
}

void	binary_tree(t_shell *shell)
{
	t_token		*token;
	char	**args;

	ft_printf(1,BLUE"token list comeca com = %s\n"RESET, shell->token->data);
	ft_printf(1,BLUE"token list comeca com = %i\n"RESET, (*(&(shell->token)))->type);
	args = get_args(shell, &(shell->token));
	while (*args)
		ft_printf(1,BLUE"Args = %s\n"RESET, *(args++));
	token = get_next_pipe(shell->token);
	ft_printf(1, "antes do pipe: %s depois do pipe %s\n", token->prev->prev->data, token->next->next->data);
	token = token->next;
	token = get_next_pipe(shell->token);
	ft_printf(1, "antes do pipe: %s depois do pipe %p\n", token->prev->prev->data, token->next);
}

t_pipe	*build_pipe(void *left, void *right)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof(t_pipe));
	pipe->left = left;
	pipe->right = right;
	pipe->type = PIPE_NODE;
	return (pipe);
}

void	*build_exec(t_shell *shell, t_token *token)
{
	t_exec	*exec;
	char	**args;

	exec = ft_calloc(sizeof(t_exec), 1);
	args = get_args(shell, &token);
	exec->args = args;
	exec->type = EXEC_NODE;
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
