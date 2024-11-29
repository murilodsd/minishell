#include "../../includes/minishell.h"

bool	is_redir_token(t_token *token)
{
	if (!token)
		return (false);
	if (token->type == REDIR_IN || token->type == REDIR_APPEND
		|| token->type == REDIR_OUT || token->type == HEREDOC)
		return (true);
	return (false);
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

int	count_args(t_token *token)
{
	int	i;

	i = 0;	
	while (token->type != PIPE && token->type != NULL_TOKEN)
	{
		if (token->type == COMMAND || token->type == COMMAND_ARG)
			i++;
		token = token->next;
	}
	return (i);
}

char	**get_args(t_shell *shell, t_token *token)
{
	int	n_args;
	int	i;
	char	**args;

	n_args = count_args(token);
	if (n_args == 0)
		return (NULL);
	args = ft_calloc(n_args + 1, sizeof(char *));
	check_mem_alloc(shell, &(shell->mem_allocation.matrix_mem_list), \
			args, "Calloc failed");
	i = 0;
	while(i < n_args)
	{
		if (token->type == COMMAND || token->type == COMMAND_ARG)
		{
			args[i] = ft_strdup(token->data);
			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				args[i], "Calloc failed");
			i++;
		}
		token = token->next;
	}
	return (args);
}
