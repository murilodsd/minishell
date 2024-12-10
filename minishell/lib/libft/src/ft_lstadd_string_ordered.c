/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_string_ordered.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:52:14 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 22:22:17 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_string_ordered(t_list **lst, t_list *new)
{
	t_list	*node_ref;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else if (ft_strcmp((char *)((*lst)->content), (char *)((new)->content)) > 0)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		node_ref = *lst;
		while (node_ref->next && (ft_strcmp((char *)(node_ref->next->content), \
			(char *)((new)->content)) < 0))
			node_ref = node_ref->next;
		if (node_ref->next == NULL)
			ft_lstlast(*lst)->next = new;
		else
		{
			new->next = node_ref->next;
			node_ref->next = new;
		}
	}
}
