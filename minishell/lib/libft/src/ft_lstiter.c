/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:29:59 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/26 18:55:17 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.
 * @param lst: The address of a pointer to a node.
 * @param f: The address of the function used to iterate on
 * @return none
the list.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
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
void	content2(void* content)
{
	int	*int_content;

	int_content = content;
	*int_content *= 2;
}
int	main(void)
{
	printf("\n");
	int	num = 3;
	t_list	*head;

	head = NULL;
 	while (num--)//Isere na lista primeiro os maiores numeros...
		ft_lstadd_back(&head,ft_lstnew(ft_int_p(num)));
	printf("Do primeiro ao ultimo ->");
	ft_printlst(head);
	printf("#------------------------------#\n");
	printf("Multiplicando por dois todos\n");
	ft_lstiter(head,content2);
	ft_printlst(head);
	printf("Size of s_list: %zu\n", sizeof(t_list));
	return (0);
} */