/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:58:35 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/02 21:29:24 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the node ’new’ at the beginning of the list.*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
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

int	*ft_seq_int_arr(int rand_num)
{
	int	*p_num;

	p_num = (int *)malloc(sizeof(int) * rand_num);
	if(!p_num)
		return (NULL);
	while(rand_num--)
		p_num[rand_num] = rand_num;
	return (p_num);
}
int	main(void)
{
	int	num = 4;
	int	*p_num = ft_seq_int_arr(num);//gera um array sequencial 0,1,2...
	t_list	*head;
	
	head = NULL;
 	while (num--)//lista array sequencial comecando pro primeiro, o zero.
		ft_lstadd_front(&head,ft_lstnew(p_num++));
	ft_printlst(head);
	return (0);
} */