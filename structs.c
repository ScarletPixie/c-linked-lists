/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:29:22 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/04 09:57:16 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*new_node(void *data, void (*failsafe)(void *data))
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		if (failsafe)
			failsafe(data);
		return (NULL);
	}
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list2	*new_node2(void *data, void (*failsafe)(void *data))
{
	t_list2	*node;

	node = malloc(sizeof(t_list2));
	if (!node)
	{
		if (failsafe)
			failsafe(data);
		return (NULL);
	}
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	lst_clear(t_list **head, void (*func)(void *data))
{
	t_list	*tmp;

	if (!head || !*head)
		return ;
	tmp = *head;
	if (func)
	{
		while (tmp)
		{
			tmp = (*head)->next;
			func((*head)->data);
			free(*head);
			*head = tmp;
		}
		return ;
	}
	while (tmp)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

void	lst_clear2(t_list2 **head, void (*func)(void *data))
{
	t_list2	*tmp;

	if (!head || !*head)
		return ;
	tmp = *head;
	if (func)
	{
		while (tmp)
		{
			tmp = (*head)->next;
			func((*head)->data);
			free(*head);
			*head = tmp;
		}
		return ;
	}
	while (tmp)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}
