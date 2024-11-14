#include "../../../includes/minishell.h"

void	print_env(void *envp)
{
	char	*content;

	content = (char *)envp;
	printf("%s\n", content);
}

t_list	*create_env_lst(t_shell *shell, char **envp)
{
	int	i;
	t_list	*env_lst;
	t_list	*new_node;

	env_lst = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		new_node = ft_lstnew(envp[i]);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			new_node, "Calloc failed");
		ft_lstadd_back(&env_lst, new_node);
		i++;
	}
	return (t_list);
}

void	env_builtin(t_list *env_lst)
{
	ft_lstiter(env_lst, print_env);
}
