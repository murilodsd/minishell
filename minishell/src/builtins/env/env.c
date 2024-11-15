#include "../../../includes/minishell.h"

void	print_env(void *envp)
{
	char	*content;

	content = (char *)envp;
	printf("%s\n", content);
}

void	env_builtin(t_list *env_lst)
{
	ft_lstiter(env_lst, print_env);
}
