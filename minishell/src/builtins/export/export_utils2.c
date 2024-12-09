/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:37:29 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 11:07:12 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	swap_pointers(t_list *new, t_list **lst)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_var_ordered(t_list **lst, t_list *new)
{
	t_list	*node_ref;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else if (ft_strcmp(((t_var *)((*lst)->content))->name, \
		((t_var *)((new)->content))->name) > 0)
		swap_pointers(new, lst);
	else
	{
		node_ref = *lst;
		while (node_ref->next && \
			ft_strcmp(((t_var *)(node_ref->next->content))->name, \
			((t_var *)(new->content))->name) < 0)
			node_ref = node_ref->next;
		if (node_ref->next == NULL)
			ft_lstlast(*lst)->next = new;
		else
			swap_pointers(new, &(node_ref->next));
	}
}
