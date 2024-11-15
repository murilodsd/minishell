#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/libft/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include "structures.h"
# include "syntax_check.h"
# include "handle_signals.h"
# include "tokenizer.h"
# include "parser.h"
# include "binary_tree.h"
# include "executer.h"
# include "builtins.h"
# include "utils.h"

// ********************************* GLOBAL VARIABLE ********************* //

extern int	g_signal;

// ********************************* EXIT CODES ************************* //

# define EXIT_USAGE_SYNTAX_ERROR 2
# define EXIT_CMD_NOT_FOUND 127

#endif
