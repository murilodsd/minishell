/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:25:05 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/02 21:30:20 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * Counts the number of nodes in a list.
 * @param lst: The beginning of the list.
 * @return The length of the list
 */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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
	int	num = 0;
	int	*p_num = ft_seq_int_arr(num);
	t_list	*head;
	
	head = NULL;
 	while (num--)
		ft_lstadd_front(&head,ft_lstnew(p_num++));
	printf("%d\n",ft_lstsize(head));
	return (0);
} */