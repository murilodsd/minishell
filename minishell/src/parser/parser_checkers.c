#include "../../includes/minishell.h"

void	check_env_var(t_token *token, t_shell *shell)
{
	int		i;

	i = 0;
	while (token->data[i])
	{
		if (i == 0 && !ft_isalpha(token->data[i]) && token->data[i] != '_')
		{
			i++;
			break ;
		}
		if (!isalnum(token->data[i]) && token->data[i] != '_')
			break ;
		i++;
	}
	if (token->data[i] == '\0')
		token->type = ENV_VAR_NAME;
	else
		split_token(token, i);
	expand_var(token, shell);
}

void	check_exit_code(t_token *token, t_shell *shell)
{
	char	*exit_code;

	exit_code = ft_itoa(shell->exit_status);
	ft_str_replace(&(token->data), exit_code);
	token->type = WORD;
	free(exit_code);
}

char	*check_env_var_d_quote(t_shell *shell, char *data)
{
	int		i;
	char	*tmp;
	char	*new_data;
	char	*next_char;

	i = 0;
	new_data = ft_strdup("");
	while (data[i])
	{
		if (data[i] == '$' && !ft_isspace(data[i + 1]) && data[i + 1] != '\0')
		{
			i++;
			tmp = new_data;
			if (data[i] == '?')
				new_data = expand_exit_code(shell, tmp);
			else
				new_data = expand_var_d_quote(shell, tmp, data, &i);
			free(tmp);
		}
		else
		{
			tmp = new_data;
			next_char = ft_substr(data, i, 1);
			new_data = ft_strjoin(tmp, next_char);
			free(tmp);
			free(next_char);
		}
		i++;
	}
	return (new_data);
}
