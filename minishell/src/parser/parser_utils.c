#include "../../includes/minishell.h"

void	expand_var(t_token *token)
{
	char	*env_var;

	if (token->type == ENV_VAR_NAME)
	{
		env_var = getenv(token->data);
		if (env_var)
		{
			free(token->data);
			token->data = ft_strdup(env_var);
//			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list),
//				token->data, "Strdup malloc failed");
		}
		else
		{
			free(token->data);
			token->data = ft_strdup(" ");
//			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list),
//				token->data, "Strdup malloc failed");
		}
		token->type = WORD;
	}
}

void	check_env_var(t_token *token)
{
	int		i;

	i = 0;
	while (token->data[i])
	{
		if (!isalnum(token->data[i]) && token->data[i] != '_')
			break;
		i++;
	}
	if (token->data[i] == '\0')
		token->type = ENV_VAR_NAME;
	else
		split_token(token, i);
	expand_var(token);
}

void	split_token(t_token *token, int i)
{
	char	*env_var;
	char	*word;

	env_var = ft_substr(token->data, 0, i);
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), env_var,
//		"Substr malloc failed");
	word = ft_substr(token->data, i, ft_strlen(token->data - i) - i);
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), word,
//		"Substr malloc failed");
	free(token->data);
	token->data = env_var;
	token->type = ENV_VAR_NAME;
	find_place(token, word, token->quote);
}

void	find_place(t_token *token, char *word, t_token_quote quote)
{
	t_token	*new_token;
	t_token	*tmp;

	new_token = (t_token *)malloc(sizeof(t_token));
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), new_token,
//		"Token malloc failed");
	new_token->data = word;
	new_token->type = WORD;
	new_token->quote = quote;
	tmp = token->next;
	token->next = new_token;
	new_token->prev = token;
	new_token->next = tmp;
	if (tmp)
		tmp->prev = new_token;
}
