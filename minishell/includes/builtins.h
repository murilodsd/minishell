#ifndef BUILTINS_H
# define BUILTINS_H

// builtins.c
void	builtins(void);

// cd
// cd.c
//void	cd_builtin(void);

// echo
// echo.c
void	echo_builtin(void);

// env
// env.c
void	env_builtin(t_list *env_lst);

// exit
// exit.c
void	exit_builtin(void);

// export
// export.c
void	export_builtin(t_list *export_lst);

// pwd
// pwd.c
void	pwd_builtin(void);

// unset
// unset.c
void	unset_builtin(void);

#endif
