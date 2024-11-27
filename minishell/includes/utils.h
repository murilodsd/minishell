#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

// handle_mem.c
void	check_mem_alloc(t_shell *shell, t_list **ptr_or_matrix_list, \
	void *ptr, char *error_msg);

// handle_error.c
void	free_exit(t_shell *shell);
void	free_exit_error(t_shell *shell, t_error_codes error_code, char *error_msg);
void	msg_error(t_error_codes error_code, char *error_msg, ...);
void	handle_error(void);
void	ft_lstremove_mem_node(t_list **lst, void *content);
void	free_all(t_shell *shell);

// handle_input.c
void	handle_input(char *cmd, t_shell *shell);

// init_data.c
void	init_data(t_shell **shell, int argc, char **argv, char **envp);

// utils.c
int		ft_isspace(char c);
int		ignore_spaces(char *cmd, int i);
int		check_malloc(void *ptr);

#endif
