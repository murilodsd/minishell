#ifndef BUILTINS_H
# define BUILTINS_H

// builtins.c
void	builtins(void);

// cd
// cd.c
void	cd_builtin(t_shell *shell, char **cd_args);

// echo
// echo.c
void	echo_builtin(t_shell *shell, char **args);

// env
// env.c
void	env_builtin(t_list *env_lst);

// exit
// exit.c
void	exit_builtin(t_shell * shell, char **exit_args);

// export
// export_utils.c
t_list	*ft_lstfind_name(t_list *lst, char *name);
void	edit_var(t_shell *shell, t_list *lst, t_var *var);
void	add_var(t_shell *shell, t_list *lst, t_var *var);
void	get_new_var_name_and_value(t_shell *shell, t_var *var, char *string);
// export.c
void	export_builtin(t_shell *shell, char **export_args);
void	ft_lstadd_var_ordered(t_list **lst, t_list *new);
void	add_or_edit_var(t_shell *shell, t_var *var);

// pwd
// pwd.c
void	pwd_builtin(t_shell * shell);
char	*safe_getcwd(char *buf, size_t size, t_shell *shell);

// unset
// unset.c
void	unset_builtin(t_shell *shell, char **unset_args);

#endif
