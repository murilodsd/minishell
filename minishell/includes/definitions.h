#ifndef DEFINITIONS_H
# define DEFINITIONS_H
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
	TOO_MANY_ARGS,
	SYNTAX_ERROR,
	NOT_VALID_IDENTIFIER,
	VAR_NOT_SET,
	NUMERIC_ARGUMENT_REQUIRED
}	t_error_codes;

// ********************************* EXIT CODES ************************* //

# define EXIT_USAGE_SYNTAX_ERROR 2
# define EXIT_CMD_NOT_FOUND 127

// ********************************* TOKEN DEFINITIONS ***************** //

typedef enum e_token_type
{
	WORD,
	COMMAND,
	COMMAND_ARG,
	PIPE,
	REDIR_IN,
	REDIR_IN_FILE,
	REDIR_OUT,
	REDIR_OUT_FILE,
	REDIR_APPEND,
	REDIR_APPEND_FILE,
	HEREDOC,
	EOF_TOKEN,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	ENV_VAR,
	ENV_VAR_EXIT_CODE,
	ENV_VAR_NAME,
	SPACE_TOKEN,
	NULL_TOKEN
}	t_token_type;

typedef enum e_token_quote
{
	NO_QUOTE,
	SINGLE,
	DOUBLE
}	t_token_quote;

#endif
