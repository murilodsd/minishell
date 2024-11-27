#include "../../includes/minishell.h"

char	**get_args(t_shell *shell, t_token **token)
{
	int	i;
	t_token	*tmp;
	char	**args;

	i = 0;
	tmp = *token;
	while (tmp->type != PIPE && tmp->type != NULL_TOKEN)
	{
		if (tmp->type == COMMAND || tmp->type == COMMAND_ARG)
			i++;
		tmp = tmp->next;
	}
	*token = tmp;
	if (i == 0)
		return (NULL);
	args = ft_calloc(i + 1, sizeof(char *));
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
			args, "Calloc failed");
	tmp = tmp->prev;
	while(i)
	{
		ft_printf(1,BLUE"Passando por: %s\n"RESET, tmp->data);
		if (tmp->type == COMMAND || tmp->type == COMMAND_ARG)
		{
			args[--i] = ft_strdup(tmp->data);
			ft_printf(1,BLUE"ARGS[%i] = %s\n"RESET, i, tmp->data);
			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				args[i], "Calloc failed");
		}
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
	ft_printf(1, "antes do pipe: %s depois do pipe %s\n", token->prev->data, token->next->data);
	args = get_args(shell, &(shell->token->next));
	//token = token->next;
	//token = get_next_pipe(shell->token);
	//ft_printf(1, "antes do pipe: %s depois do pipe %p\n", token->prev->data, token->next->data);
}

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
	void	*root;

	root = NULL;
	end_of_the_command = get_next_pipe(token);
	if (!end_of_the_command)
		end_of_the_command = ft_lstlast(token);
	token = get_previous_redir(end_of_the_command);
	while (is_redir_token(token))
	{
		if (last_redir(token))
			root = create_new_redir(shell, down, token, 0);
		else
			root = create_new_redir(shell, root, token, 0);
		token = get_previous_redir(token);
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

	//REVIEW => Será que não poderia dar problema no caso de só ter redirecionamento?
	args = get_args(shell, &token);
	if (args != NULL)
	{
		exec = ft_calloc(sizeof(t_exec), 1);
		exec->args = args;
		exec->type = EXEC_NODE;
	}
	else
		exec = NULL;
	root = build_redirect(shell, exec, token);
	return (root);
}

void	*build_tree(t_shell *shell, t_token *token)
{
	void	*root;

	//TODO -> setar o root igual saida do exec;
	root = build_exec(shell, token);
	
	if (get_next_pipe(token) != NULL)
		root = build_pipe(shell, root, build_tree(shell, get_next_pipe(token)->next));
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
