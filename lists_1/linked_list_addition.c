/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_addition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:41:34 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/04 10:41:50 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	lst_insert(t_list **head, t_list *node, size_t index)
{
	t_list	*curr;
	size_t	i;

	i = 0;
	if (!node || !head || *head == node || node->next != NULL)
		return ;
	curr = *head;
	if (!*head || index == 0)
	{
		node->next = *head;
		*head = node;
		return ;
	}
	while (i <= index && curr->next)
	{
		if ((i + 1) == index)
		{
			node->next = curr->next;
			curr->next = node;
			return ;
		}
		curr = curr->next;
		i++;
	}
	curr->next = node;
}

void	lst_append(t_list **head, t_list *node)
{
	t_list	*last;

	if (!node || !head || *head == node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	last = last_node(*head);
	last->next = node;
}

void	lst_extend(t_list **head, t_list *list, size_t index)
{
	size_t	i;
	t_list	*curr;

	i = 0;
	if (!list || !head || *head == list)
		return ;
	curr = *head;
	if (index == 0 || !*head)
	{
		last_node(list)->next = *head;
		*head = list;
		return ;
	}
	while (curr->next && i <= index)
	{
		if ((i + 1) == index)
		{
			(last_node(list))->next = curr->next;
			curr->next = list;
			return ;
		}
		curr = curr->next;
		i++;
	}
	curr->next = list;
}
