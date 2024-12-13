/*#include "../includes/minishell.h"

char	*format_data_parentheses(const char *data)
{
	size_t	len;
	char	*formatted;

	len = ft_strlen(data);
	formatted = malloc(len + 3);
	if (!formatted)
		return ("(allocation failed)");
	formatted[0] = '(';
	ft_strcpy(formatted + 1, (char *)data);
	formatted[len + 1] = ')';
	formatted[len + 2] = '\0';
	return (formatted);
}

const char	*get_token_type_str(t_token_type type)
{
	if (type == WORD)
		return ("Word");
	else if (type == COMMAND)
		return ("Command");
	else if (type == COMMAND_ARG)
		return ("Command arg");
	else if (type == PIPE)
		return ("Pipe");
	else if (type == REDIR_IN)
		return ("Redir in");
	else if (type == REDIR_IN_FILE)
		return ("Redir in file");
	else if (type == REDIR_OUT)
		return ("Redir out");
	else if (type == REDIR_OUT_FILE)
		return ("Redir out file");
	else if (type == REDIR_APPEND)
		return ("Redir app");
	else if (type == REDIR_APPEND_FILE)
		return ("Redir app file");
	else if (type == HEREDOC)
		return ("Heredoc");
	else if (type == EOF_TOKEN)
		return ("EOF");
	else if (type == ENV_VAR)
		return ("Env var");
	else if (type == ENV_VAR_EXIT_CODE)
		return ("Env var exit code");
	else if (type == ENV_VAR_NAME)
		return ("Env var name");
	else if (type == SPACE_TOKEN)
		return ("Space");
	else if (type == NULL_TOKEN)
		return ("Null");
	else
		return ("Unknown");
}

const char	*get_token_quote_str(t_token_quote quote)
{
	if (quote == NO_QUOTE)
		return ("No quote");
	else if (quote == SINGLE)
		return ("Single");
	else if (quote == DOUBLE)
		return ("Double");
	return ("Unknown");
}

void	print_list(t_token *token)
{
	t_token	*tmp;
	int		index;
	char	*formatted_data;

	printf("+-------+----------------------------------------------------+----------------------+------------+\n");
	printf("| Index | Data                                               | Type                 | Quote      |\n");
	printf("+-------+----------------------------------------------------+----------------------+------------+\n");
	tmp = token;
	index = 0;
	while (tmp)
	{
		formatted_data = tmp->data ? format_data_parentheses(tmp->data) : NULL;
		printf("| %-5d | %-50.50s | %-20.15s | %-10.10s |\n",
			index,
			formatted_data,
			get_token_type_str(tmp->type),
			get_token_quote_str(tmp->quote));
		printf("+-------+----------------------------------------------------+----------------------+------------+\n");
		if (ft_strcmp(formatted_data, "(null)") != 0)
			free(formatted_data);
		tmp = tmp->next;
		index++;
	}
}*/
/*
//PUSH REVIEW -> apagar funcao de print da arvore
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
