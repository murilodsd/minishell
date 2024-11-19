#include "../../../includes/minishell.h"

char	*safe_getcwd(char *buf, size_t size, t_shell *shell)
{
	char	*cwd;

	cwd = getcwd(buf, size);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
		cwd, "Getcwd failed");
	//REVIEW - AQUI DÁ EXIT OU NÃO SE FALHAR?
	return (cwd);
}

void	pwd_builtin(void)
{
	char	*pwd;

	pwd = safe_getcwd(NULL, 0, NULL);
	ft_printf(1, "%s\n", pwd);
	//REVIEW - PRECISA SETAR A SAÍDA AQUI?
	//shell->exit_status = EXIT_SUCCESS;
}
