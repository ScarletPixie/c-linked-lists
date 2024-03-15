/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:04:05 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/15 15:47:54 by paulhenr         ###   ########.fr       */
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

t_list	*new_list(size_t size, void *(*gen)(void),
			void (*gen_failsafe)(void *dt))
{
	size_t	index;
	t_list	*list;
	t_list	*node;

	list = NULL;
	index = 0;
	while (index < size)
	{
		if (gen)
		{
			node = new_node(gen(), gen_failsafe);
			if (!node)
				return (lst_destroy(list, gen_failsafe));
		}
		else
		{
			node = new_node(NULL, NULL);
			if (!node)
				return (lst_destroy(list, NULL));
		}
		lst_prepend(&list, node);
		index++;
	}
	lst_rev(list);
	return (list);
}

t_list	*lst_map(t_list *head, t_list *(*func)(void *dt))
{
	t_list	*list;
	t_list	*node;

	if (!head || !func)
		return (NULL);
	list = NULL;
	while (head)
	{
		node = func(head->data);
		if (!node)
			return (list);
		lst_insert(&list, node, 0);
		head = head->next;
	}
	lst_rev(list);
	return (list);
}

void	lst_foreach(t_list *head, void (*func)(t_list *node))
{
	if (!head || !func)
		return ;
	while (head)
	{
		func(head);
		head = head->next;
	}
}
