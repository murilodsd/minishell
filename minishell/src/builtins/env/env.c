#include "../../../includes/minishell.h"

void	print_env(void *envp)
{
	t_var	*content;

	content = (t_var *)envp;
	printf("%s", content->name);
	if (content->value)
		printf("=%s\n", content->value);
}

void	env_builtin(t_list *env_lst)
{
	ft_lstiter(env_lst, print_env);
}
