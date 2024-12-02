#ifndef EXECUTER_H
# define EXECUTER_H
# include "minishell.h"

//executer.c
void	executer(t_shell * shell, void *root);

//execve.c
void	execute_execve(t_shell *shell, t_exec *exec);
char	**get_exported_env_vars(t_shell *shell, t_list *envp);

#endif
