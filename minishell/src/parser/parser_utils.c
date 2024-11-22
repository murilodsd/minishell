#include "../../includes/minishell.h"

void	expand_var(t_token *token, t_shell *shell)
{
	char	*env_var;

	if (token->type == ENV_VAR_NAME)
	{
		env_var = ft_getenv(shell->envp_lst, token->data);
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
// remover o token
		}
		token->type = WORD;
	}
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

void	expand_var_d_quote(t_token *token, int i)
{
	int		j;
	char	*env_var;

	j = i + 1;
	env_var = ft_substr(token->data, i, j - i);
}

char	*ft_getenv(t_list *envp_lst, char *name)
{
	t_var *var;
	t_list *lst;

	lst = envp_lst;
	while (lst)
	{
		var = (t_var *)lst->content;
		if (ft_strcmp(var->name, name) == 0)
			return (var->value);
		lst = lst->next;
	}
	return (NULL);
}
