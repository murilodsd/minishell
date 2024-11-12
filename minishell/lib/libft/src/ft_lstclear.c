/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:42:19 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/20 17:22:20 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
 * @param lst: The address of a pointer to a node.
 * @param del: The address of the function used to delete
 * the content of the node.
 * @return none
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next;
	}
	*lst = NULL;
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
	printf("\n");
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
	printf("Deletando o ultimo a lista\n");
	ft_lstclear(&head,delete);
	printf("Size of s_list: %zu\n", sizeof(t_list));
	return (0);
} */