#include "../../includes/minishell.h"

void	builtins(t_shell *shell, char **args)
{
	if (!ft_strcmp(args[0], "pwd"))
		pwd_builtin(shell);
	if (!ft_strcmp(args[0], "echo"))
		echo_builtin(shell, args);
	if (!ft_strcmp(args[0], "cd"))
		cd_builtin(shell, args);
	if (!ft_strcmp(args[0], "export"))
		export_builtin(shell, args);
	if (!ft_strcmp(args[0], "unset"))
		unset_builtin(shell, args);
	if (!ft_strcmp(args[0], "env"))
		env_builtin(shell, args);
	if (!ft_strcmp(args[0], "exit"))
		exit_builtin(shell, args);
	else
		//exec
		ft_printf(1, "exec");
}
