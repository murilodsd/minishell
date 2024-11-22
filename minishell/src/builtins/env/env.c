#include "../../../includes/minishell.h"

void	print_env(void *envp)
{
	t_var	*content;

	content = (t_var *)envp;
	if (content->value)
		printf("%s=%s\n", content->name, content->value);
}

void	env_builtin(t_shell *shell)
{
	ft_lstiter(shell->envp_lst, print_env);
	shell->exit_status = 0;
}
