#include "../../includes/minishell.h"

size_t calculate_total_length(t_list *envp)
{
	size_t	size;

	size = 0;
	while (envp)
	{
		if (((t_var *)(envp->content))->value)
		{
			size = ft_strlen(((t_var *)(envp->content))->name);
			size += ft_strlen(((t_var *)(envp->content))->value);
			size += 2;	
		}
		envp = envp->next;
	}
	return (size);
}

char	*get_exported_env_vars(t_shell *shell, t_list *envp)
{
	char	*envp_string;
	int	total_length;
	
	if (!envp)
		return (NULL);
	total_length = calculate_total_length(envp);
	envp_string = ft_calloc(total_length, sizeof(char));
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				envp_string, "Calloc failed");
	while (envp)
	{
		if (((t_var *)(envp->content))->value)
		{
			ft_strcat(envp_string, ((t_var *)(envp->content))->name);
			ft_strcat(envp_string, "=");
			ft_strcat(envp_string, ((t_var *)(envp->content))->value);
			ft_strcat(envp_string, ":");
		}
		envp = envp->next;
	}
	if (total_length)
		envp_string[total_length - 1] = '\0';
	return (envp_string);
}
