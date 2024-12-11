/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:13:56 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 21:23:35 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "minishell.h"

// cd.c
void	cd_builtin(t_shell *shell, char **cd_args);

// echo.c
void	echo_builtin(t_shell *shell, char **args);

// env.c
void	env_builtin(t_shell *shell, char **args, bool is_root);

// exit.c
void	exit_builtin(t_shell *shell, char **exit_args, bool is_root);

// export.c
void	export_builtin(t_shell *shell, char **export_args);
void	ft_lstadd_var_ordered(t_list **lst, t_list *new);
void	add_or_edit_var(t_shell *shell, t_var *var);
// export_utils.c
t_list	*ft_lstfind_name(t_list *lst, char *name);
void	edit_var(t_shell *shell, t_var *var);
void	add_var(t_shell *shell, t_var *var);
void	get_new_var_name_and_value(t_shell *shell, t_var *var, char *string);
// export_utils2.c
void	ft_lstadd_var_ordered(t_list **lst, t_list *new);

// pwd.c
void	pwd_builtin(t_shell *shell);
char	*safe_getcwd(char *buf, size_t size, t_shell *shell);

// unset.c
void	unset_builtin(t_shell *shell, char **unset_args);

#endif
