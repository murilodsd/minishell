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
			if (check_malloc(token->data))
				return ;
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
	if (check_malloc(env_var))
		return ;
	word = ft_substr(token->data, i, ft_strlen(token->data - i + 1));
	if (check_malloc(word))
	{
		free(env_var);
		return ;
	}
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
	env_var = ft_getenv(shell->envp_lst, env_var_name);
	free(env_var_name);
	if (env_var)
	{
		strjoin = ft_strjoin(tmp, env_var);
		if (check_malloc(strjoin))
			return (0);
	}
	else
	{
		strjoin = ft_strdup(tmp);
		if (check_malloc(strjoin))
			return (0);
	}
	*i = *i - 1;
	return (strjoin);
}

char	*expand_exit_code(t_shell *shell, char *tmp)
{
	char	*exit_code;
	char	*strjoin;

	exit_code = ft_itoa(shell->exit_status);
	if (check_malloc(exit_code))
		return (0);
	if (exit_code == NULL)
		return (tmp);
	else
	{
		strjoin = ft_strjoin(tmp, exit_code);
		if (check_malloc(strjoin))
			return (0);
		free(exit_code);
		return (strjoin);
	}
}

char	*ft_getenv(t_list *envp_lst, char *name)
{
	t_var	*var;
	t_list	*lst;

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
