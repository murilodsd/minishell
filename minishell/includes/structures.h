#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "minishell.h"

// ********************************* ERROR CODES ************************* //

typedef enum e_error_codes
{
	GENERAL_ERROR,
	CMD_NOT_FOUND,
	NO_FILE_DIRECTORY,
	PERMISSION_DENIED,
	AMBIGUOS_REDIRECT,
	IS_DIRECTORY,
	IS_NOT_DIRECTORY,
	SYNTAX_ERROR
}	t_error_codes;

// ******************************** SHELL STRUCT *********************** //

typedef struct s_shell
{
	t_mem_alloc	mem_allocation;
	void		*root;
	int			*array_fd_here_doc;
	int			exit_status;
	int			pid;
	int			process;
	int			fd_in;
	int			fd_out;
	int			count_hd;
	char		**envp;
	char		*cmd;
	char		*path;
}				t_shell;

#endif
