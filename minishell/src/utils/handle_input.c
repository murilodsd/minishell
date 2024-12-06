#include "../../includes/minishell.h"
/*
//PUSH REVIEW -> apagar funcao de print da arvore
* char *get_node_type_name(t_node_type type) {
    if (type == EXEC_NODE) {
        return "EXEC_NODE";
    } else if (type == PIPE_NODE) {
        return "PIPE_NODE";
    } else if (type == REDIR_IN_NODE) {
        return "REDIR_IN_NODE";
    } else if (type == REDIR_OUT_NODE) {
        return "REDIR_OUT_NODE";
    } else if (type == REDIR_APPEND_NODE) {
        return "REDIR_APPEND_NODE";
    } else if (type == HEREDOC_NODE) {
        return "HEREDOC_NODE";
    } else {
        return "UNKNOWN_TYPE"; // Valor inválido
    }
}
char *get_node_type_name(t_node_type type, void *node) {
    if (type == EXEC_NODE) {
        return ("exec");
    } else if (type == PIPE_NODE) {
        return "|";
    } else if (type == REDIR_IN_NODE) {
        return (ft_strjoin("< ", (((t_redir *)node)->file)));
    } else if (type == REDIR_OUT_NODE) {
        return (ft_strjoin("> ", (((t_redir *)node)->file)));
    } else if (type == REDIR_APPEND_NODE) {
        return (ft_strjoin(">> ", (((t_redir *)node)->file)));
    } else if (type == HEREDOC_NODE) {
        return (ft_strjoin("<< ", (((t_redir *)node)->file)));
    } else {
        return "UNKNOWN_TYPE"; // Valor inválido
    }
}
void print_tree(void *node, int level, bool first) {
	int i = 0;
	if (node == NULL) {
		return;
	}

	// Recur para o lado direito primeiro, para impressão hierárquica
	if (*((t_node_type *)node) == PIPE_NODE)
		print_tree(((t_pipe *)node)->right, level + 1, TRUE);

	// Imprime o nível atual
	for (int i = 0; i < level; i++)
	{
		// if (i < level - 1)
		// 	printf("    "); // Indentação para níveis mais profundos
		// else
		// {
			if (*((t_node_type *)node) == PIPE_NODE)
				printf("     "); // Indentação para níveis mais profundos
			else
			{
				if (first)
					printf("     ");
				else
				{
					printf(" - ");
					break;
				}
			}
		// }
	}

	// Exibe o tipo do nó
	if (*((t_node_type *)node) == PIPE_NODE)
		printf("( %s )\n", get_node_type_name(*((t_node_type *)node), node));
	else if (*((t_node_type *)node) == EXEC_NODE)
	{
		i = 0;
		printf("( ");
		while (((t_exec *)node)->args[i])
			printf(" %s",(((t_exec *)node)->args[i++]));
		printf(" )");
	}
	else
		printf("( %s )", get_node_type_name(*((t_node_type *)node), node));

	// Recur para o lado esquerdo
	if (*((t_node_type *)node) == PIPE_NODE)
    		print_tree(((t_pipe *)node)->left, level + 1, TRUE);
	else if (*((t_node_type *)node) == EXEC_NODE)
		printf("\n");
	else
		print_tree(((t_redir *)node)->down, level + 1, FALSE);
}

void printTree(void *node, int depth) {
  if (node == NULL) {
    return;
  }

  // Imprime espaços para representar a profundidade
  for (int i = 0; i < depth; i++) {
    printf("  ");
  }

  // Imprime o tipo de nó e o dado
  //printf("Type: %s\n", get_node_type_name(*((t_node_type *)node)));
  printf("(%d)\n", *((t_node_type *)node));

  // Chama recursivamente para a subárvore direita
  if (*((t_node_type *)node) == PIPE_NODE)
  	printTree(((t_pipe *)node)->right, depth + 1);

  // Chama recursivamente para a subárvore esquerda (que só tem um ramo)
  if (*((t_node_type *)node) == PIPE_NODE)
    		printTree(((t_pipe *)node)->left, depth + 1);
	else if (*((t_node_type *)node) == EXEC_NODE)
		return ;
	else
		printTree(((t_redir *)node)->down, depth + 1);
}
*/

void	handle_input(char *cmd, t_shell *shell)
{
	if (syntax_check(cmd))
	{
		shell->exit_status = EXIT_USAGE_SYNTAX_ERROR;
		return ;
	}
	tokenizer(cmd, shell, 0);
	parser(shell);
	print_list(shell->token);
	//print_tree(build_tree(shell, shell->token), 0, TRUE);
	//builtins();
	//executer();
	//handle_error();
	clear_token_list(shell);
	clear_heredoc_list(shell);
}
