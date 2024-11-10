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
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	ENV_VAR,
	FILENAME
};

enum e_token_quote
{
	NO_QUOTE,
	SINGLE,
	DOUBLE
};

typedef struct s_token
{
	int					i;
	char				*data;
	enum e_token_type	type;
	enum e_token_quote	quote;
	struct s_token		*prev;
	struct s_token		*next;
}	t_token;

// tokenizer.c
void	tokenizer(char *cmd);

#endif
