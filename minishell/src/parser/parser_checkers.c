#include "../../includes/minishell.h"

void	check_env_var(t_token *token, t_shell *shell)
{
	int		i;

	i = 0;
	while (token->data[i])
	{
		if (i == 0 && !isalpha(token->data[i]) && token->data[i] != '_')
			break;
		if (!isalnum(token->data[i]) && token->data[i] != '_')
			break;
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

	printf("check_exit_code\n");
	printf("exit_status: %d\n", shell->exit_status);
	exit_code = ft_itoa(shell->exit_status);
	printf("exit_code: %s\n", exit_code);
	ft_str_replace(&(token->data), exit_code);
	ft_printf(1, "exit_code: %s\n", token->data);
}
