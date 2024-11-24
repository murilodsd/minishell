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
			token->type = WORD;
		}
		else
			rm_token(&token, shell);
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

char	*expand_var_d_quote(t_shell *shell, char *tmp, char *cmd, int *i)
{
	char	*env_var_name;
	char	*env_var;
	char	*strjoin;
	int		j;

	j = *i;
	while (cmd[*i] && (ft_isalnum(cmd[*i]) || cmd[*i] == '_'))
		*i = *i + 1;
	env_var_name = ft_substr(cmd, j, *i - j);
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), env_var,
//		"Substr malloc failed");
	env_var = ft_getenv(shell->envp_lst, env_var_name);
	if (env_var)
	{
		strjoin = ft_strjoin(tmp, env_var);
//		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list),
//			strjoin, "Strjoin malloc failed");
	}
	else
		strjoin = ft_strdup(tmp);
//	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), strjoin,
//		"Strdup malloc failed");
	*i = *i - 1;
	return (strjoin);
}

char	*expand_exit_code(t_shell *shell, char *tmp)
{
	char	*exit_code;
	char	*strjoin;

	exit_code = ft_itoa(shell->exit_status);
	if (exit_code == NULL)
		return (tmp);
	else
	{
		strjoin = ft_strjoin(tmp, exit_code);
		free(exit_code);
		return (strjoin);
	}
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
