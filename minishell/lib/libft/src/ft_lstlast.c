/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:17:49 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/26 18:24:06 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Returns the last node of the list.
 * @param lst: The beginning of the list.
 * @return Last node of the list
 */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/* #include <stdio.h>

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
	int	num = 3;
	int	*p_num = ft_seq_int_arr(num);
	t_list	*head;
	
	head = NULL;
 	while (num--)
		ft_lstadd_front(&head,ft_lstnew(p_num++));
	printf("%d\n",*(int *)ft_lstlast(head)->content);
	return (0);
} */