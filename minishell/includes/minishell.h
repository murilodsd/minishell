/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:20:43 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/14 17:06:53 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lib/libft/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include "definitions.h"
# include "structures.h"
# include "syntax_check.h"
# include "handle_signals.h"
# include "tokenizer.h"
# include "parser.h"
# include "binary_tree.h"
# include "heredoc.h"
# include "executer.h"
# include "builtins.h"
# include "utils.h"
# include "prints.h"

#endif
