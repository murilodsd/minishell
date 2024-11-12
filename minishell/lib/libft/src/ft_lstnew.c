/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:32:52 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/20 10:43:42 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/* #include <stdio.h>
int main(void) {
	// Teste 1: Valor 42
	int *num = (int *)malloc(sizeof(int));
	*num = 42;
	t_list *node1 = ft_lstnew(num);
	printf("Test case 1: %d\n", *(int *)(ft_lstnew(num)->content));
	free(num);
	free(node1);

	// Teste 2: valor "Hello, World"
	char *str = "Hello, world!";
	t_list *node2 = ft_lstnew(str);
	printf("Test case 2: %s\n", (char *)(ft_lstnew(str)->content));
	free(node2);

	return 0;
} */
