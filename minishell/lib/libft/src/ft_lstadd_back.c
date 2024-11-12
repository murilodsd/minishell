/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:41:56 by mde-souz          #+#    #+#             */
/*   Updated: 2024/08/20 18:32:27 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Adds the node ’new’ at the end of the list.
 * @param lst: The address of a pointer to the first link of a list.
 * @param new: The address of a pointer to the node to be added to the list.
 */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}
/* #include <stdio.h>
static void ft_printstringlst(t_list *head)
{
	t_list *temp = head;
	
	if (!head)
		printf("Lista inexistente\n");
	else
	{
	while (temp != NULL)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	}
}
static void ft_printintlst(t_list *head)
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

static int	*ft_seq_int_arr(int rand_num)
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
	t_list	*head; // Ponteiro que ira apontar para o primeiro no da lista
	t_list	*new_node1;
	t_list	*new_node2;
	t_list	*new_node3;
	char	*string1;
	char	*string2;
	char	*string3;
	char	**matrix;
	int	num = 4;
	//int	*p_num = ft_seq_int_arr(num);//gera um array sequencial 0,1,2...
	int	last_int = 99;
	
	
	// Criar uma lista na qual o conteudo sera uma string
	head = NULL; 
	string1 = ft_strdup("string1");
	string2 = ft_strdup("string2");
	string3 = ft_strdup("string3");
	//Depois de criarmos as strings, inserimos elas na lista.
	new_node1 = ft_lstnew(string1);
	new_node2 = ft_lstnew(string2);
	new_node3 = ft_lstnew(string3);
	ft_lstadd_back(&head,new_node1);
	ft_lstadd_back(&head,new_node2);
	ft_lstadd_back(&head,new_node3);
	//Imprimimos a lista para verificar se está na ordem correta.
	ft_printstringlst(head);
	//Damos free na lista, nos nós e nas strings
	ft_lstclear(&head,free);

	
 	// while (num--)//lista array sequencial comecando pelo primeiro, o zero.
	// 	ft_lstadd_back(&head,ft_lstnew(p_num++));
	// ft_printintlst(head);
	// printf("Adicionando mais um numero a lista: %d\n", last_int);
	// ft_lstadd_back(&head,ft_lstnew(&last_int));
	// printf("Chmando funcao ft_lstlast\n");
	// printf("O ultimo elemento é %d\n",*(int *)ft_lstlast(head)->content);
	return (0);
} */