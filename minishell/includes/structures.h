#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "minishell.h"

// ******************************** TOKEN STRUCT *********************** //

typedef struct s_token
{
	int				i;
	char			*data;
	t_token_type	type;
	t_token_quote	quote;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

// ******************************** SHELL STRUCT *********************** //

typedef struct s_shell
{
	t_mem_alloc	mem_allocation;
	void			*root;
	int				*array_fd_here_doc;
	int				exit_status;
	int				pid;
	int				process;
	int				fd_in;
	int				fd_out;
	int				count_hd;
	t_list			*envp_lst;
	t_list			*export_lst;
	char			*cmd;
	char			*path;
	t_token			*token;
}				t_shell;

#endif
