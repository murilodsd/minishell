#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "handle_signals.h"
# include "syntax_check.h"
# include "tokenizer.h"
# include "parser.h"
# include "binary_tree.h"
# include "executer.h"
# include "builtins.h"
# include "utils.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdarg.h>
# include <stddef.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_data
{
	char	*cmd;
	char	**envp;
}	t_data;

#endif
