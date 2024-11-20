/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:22:57 by mde-souz          #+#    #+#             */
/*   Updated: 2024/11/20 13:54:59 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.
 * @param lst: The node to free.
 * @param del: The address of the function used to delete the content.
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	lst->content = NULL;
	free(lst);
}
/* #include <stdio.h>
void ft_printlst(t_list *head)
{
	t_list *temp = head;

	if (!head)
		printf("Lista inexistente\n");
	else
	{
	while (temp != NULL)
	{
		printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}
	//printf("\n");
	}
}
static int	*ft_int_p(int rand_num)
{
	int	*p_num;

	p_num = (int *)malloc(sizeof(int));
	if(!p_num)
		return (NULL);
	*p_num = rand_num;
	return (p_num);
}
void	delete(void* content)
{
	free(content);
}
int	main(void)
{
	printf("\n");
	int	num = 2;
	t_list	*head;

	head = NULL;
 	while (num--)//Isere na lista primeiro os maiores numeros...
		ft_lstadd_back(&head,ft_lstnew(ft_int_p(num)));
	printf("Do primeiro ao ultimo ->");
	ft_printlst(head);
	printf("#------------------------------#\n");
	printf("Deletando: %d\n", *(int *)ft_lstlast(head)->content);
	ft_lstdelone(ft_lstlast(head),delete);
	ft_lstdelone(head,delete);
	printf("Size of s_list: %zu\n", sizeof(t_list));
	return (0);
} */
