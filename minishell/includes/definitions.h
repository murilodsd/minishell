/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:19:00 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 11:11:19 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define EXIT_PERMISSION_DENIED 126
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_SIGINT 130
# define EXIT_SIGQUIT 131

// ********************************* PROCESS PID ************************* //

# define CHILD 0

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
	ENV_VAR,
	ENV_VAR_EXIT_CODE,
	ENV_VAR_NAME,
	SPACE_TOKEN,
	NULL_TOKEN
}	t_token_type;

typedef enum e_node_type
{
	EXEC_NODE,
	PIPE_NODE,
	REDIR_IN_NODE,
	REDIR_OUT_NODE,
	REDIR_APPEND_NODE,
	HEREDOC_NODE
}	t_node_type;

typedef enum e_token_quote
{
	NO_QUOTE,
	SINGLE,
	DOUBLE
}	t_token_quote;

#endif
