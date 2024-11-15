#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>


// ********************************* GLOBAL VARIABLE ********************* //

extern int	g_signal;

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
	TOO_MANY_ARGS,
}	t_error_codes;

// ********************************* EXIT CODES ************************* //

# define EXIT_USAGE_SYNTAX_ERROR 2
# define EXIT_CMD_NOT_FOUND 127

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
}				t_shell;

# include "utils.h"
# include "handle_signals.h"
# include "syntax_check.h"
# include "tokenizer.h"
# include "parser.h"
# include "binary_tree.h"
# include "executer.h"
# include "builtins.h"

#endif
