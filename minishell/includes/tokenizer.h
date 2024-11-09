#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC,
	SEMICOLON,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	ENV_VAR,
	FILENAME
};

typedef struct s_token
{
	int				i;
	char			*data;
	enum e_token_type	type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

// tokenizer.c
void	tokenizer(char *cmd);

#endif
