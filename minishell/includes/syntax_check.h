#ifndef SYNTAX_CHECK_H
# define SYNTAX_CHECK_H
# include "minishell.h"

// syntax_check.c
int	syntax_check(char *cmd);
int	check_pipe(char *cmd);
int	check_quotes(char *cmd);
int	check_spaces(char *cmd);

// syntax_check_utils.c
int	ignore_quotes(char *cmd, int i);

#endif
