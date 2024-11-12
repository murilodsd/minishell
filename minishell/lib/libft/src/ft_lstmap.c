/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:55:31 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/03 11:49:03 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of a node if needed.
 * @param lst: The address of a pointer to a node.
 * @param f: The address of the function used to iterate on the list.
 * @param del: The address of the function used to delete
 * the content of a node if needed.
 * @return The new list. NULL if the allocation fails.
 */

#include "libft.h"

static void	*ft_clear(t_list **lst, void *content, void (*del)(void *))
{
	if (content)
		del(content);
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (ft_clear(&head, content, del));
		new = ft_lstnew(content);
		if (!new)
			return (ft_clear(&head, content, del));
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
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
void	*content2(void* content)
{
	int	*int_content = (int*)malloc(sizeof(int)); 
	*int_content = 2 * *(int *)content;
	return (int_content);
}
void	delete(void* content)
{
	free(content);
}
int	main(void)
{
	printf("\n");
	int	num = 3;
	t_list	*head;
	t_list	*new;

	head = NULL;
 	while (num--)//Insere na lista primeiro os maiores numeros...
		ft_lstadd_back(&head,ft_lstnew(ft_int_p(num)));
	printf("Do primeiro ao ultimo ->");
	ft_printlst(head);
	printf("#------------------------------#\n");
	printf("Multiplicando por dois todos\n");
	new = ft_lstmap(head,content2,delete);
	ft_printlst(new);
	ft_lstclear(&head,delete);
	printf("Size of s_list: %zu\n", sizeof(t_list));
	return (0);
} */