#include "../../includes/minishell.h"

void	binary_tree(t_shell *shell)
{
	t_token		*token;
	char	**args;

	ft_printf(1,BLUE"token list comeca com = %s\n"RESET, shell->token->data);
	ft_printf(1,BLUE"token list comeca com = %i\n"RESET, (*(&(shell->token)))->type);
	args = get_args(shell, shell->token);
	while (*args)
		ft_printf(1,BLUE"Args = %s\n"RESET, *(args++));
	token = get_next_pipe(shell->token);
	ft_printf(1, "antes do pipe: %s depois do pipe %s\n", token->prev->data, token->next->data);
	args = get_args(shell, shell->token->next);
	//token = token->next;
	//token = get_next_pipe(shell->token);
	//ft_printf(1, "antes do pipe: %s depois do pipe %p\n", token->prev->data, token->next->data);
}

t_pipe	*build_pipe(t_shell *shell, void *left, void *right)
{
	t_pipe	*pipe;

	pipe = ft_calloc(1, sizeof(t_pipe));
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				pipe, "Calloc failed");
	pipe->left = left;
	pipe->right = right;
	pipe->type = PIPE_NODE;
	return (pipe);
}


void	*build_redir(t_shell *shell, void *down, t_token *token)
{
	t_token	*end_of_the_command;
	t_token	*last_redir;
	void	*root;

	root = NULL;
	end_of_the_command = get_next_pipe(token);
	//REVIEW -> apagar print
	//printf("Encontrou pipe (redir)? %i\n", end_of_the_command != NULL);
	if (!end_of_the_command)
		end_of_the_command = last_token(token);
	//printf("ùltimo token %s\n", end_of_the_command->prev->data);
	//REVIEW - sera que já nao tem uma funcao que pega o ultimo redir?
	last_redir = get_previous_redir(end_of_the_command);
	//printf("Encontrou redir? %i\n", last_redir != NULL);
	if (last_redir)
	{
		root = create_redir_node(shell, down, last_redir, FALSE);
		token = get_previous_redir(last_redir);
		while (is_redir_token(token))
		{
			root = create_redir_node(shell, root, token, 0);
			token = get_previous_redir(token);
		}
	}
	if (!root)
		return (down);
	return (root);
}

void	*build_exec(t_shell *shell, t_token *token)
{
	void	*root;
	t_exec	*exec;
	char	**args;

	args = get_args(shell, token);
	if (args != NULL)
	{
		exec = ft_calloc(sizeof(t_exec), 1);
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
				exec, "Calloc failed");
		exec->args = args;
		exec->type = EXEC_NODE;
		//REVIEW -> apagar print
		//printf("node exec args[0] = %s\n",args[0]);
	}
	else
		exec = NULL;
	root = build_redir(shell, exec, token);
	return (root);
}

//REVIEW -> apagar funcao de print da arvore
char *get_node_type_name(t_node_type type);

void	*build_tree(t_shell *shell, t_token *token)
{
	void	*root;
	t_token	*pipe_token;

	root = build_exec(shell, token);
	pipe_token = get_next_pipe(token);
	//REVIEW -> apagar print abaixo
	//printf("Encontrou pipe (build_tree)? %i\n", pipe_token != NULL);
	//if (pipe_token != NULL)
	//	printf("Token depois do pipe? %s\n", pipe_token->next->data);
	if (pipe_token != NULL)
		root = build_pipe(shell, root, build_tree(shell, pipe_token->next));
	//REVIEW -> apagar print abaixo
	//meu print
	//ft_printf(1, "nó pai %s\n", get_node_type_name(*((t_node_type *)root)));
	//ft_printf(1, "filho esquerdo %s filho direito %s\n", get_node_type_name(*((t_node_type *)((t_pipe *)root)->left)), get_node_type_name(*((t_node_type *)((t_pipe *)root)->right)));
	return (root);
}
