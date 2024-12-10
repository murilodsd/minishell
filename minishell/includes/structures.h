/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:16:01 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 22:18:48 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char			*env_var_name;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

// ************************** HEREDOC STRUCT *********************** //

typedef struct s_heredoc
{
	int					i;
	int					fd_heredoc;
	char				*fd_heredoc_path;
	char				*eof;
	t_token_quote		eof_quote;
	int					count_hd;
	struct s_heredoc	*next;
}	t_heredoc;

// ******************************** SHELL STRUCT *********************** //

typedef struct s_shell
{
	t_mem_alloc		mem_allocation;
	void			*root;
	int				exit_status;
	int				pid;
	int				process;
	int				fd_in;
	int				fd_out;
	char			*cmd;
	char			*path;
	t_list			*envp_lst;
	t_list			*export_lst;
	t_token			*token;
	t_heredoc		*heredoc;
}	t_shell;

typedef struct s_var
{
	char	*name;
	char	*value;
	bool	is_incremental;
}	t_var;

// ************************** BINARY TREE STRUCTS *********************** //

typedef struct s_pipe
{
	enum e_node_type	type;
	void				*left;
	void				*right;
}	t_pipe;

typedef struct s_exec
{
	enum e_node_type	type;
	char				**args;
}	t_exec;

typedef struct s_redir
{
	enum e_node_type	type;
	enum e_token_quote	file_status;
	void				*down;
	int					id;
	char				*file;
	char				*env_var_name;
}	t_redir;

#endif
