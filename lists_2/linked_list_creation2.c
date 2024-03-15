/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_creation2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:18:41 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/15 14:14:44 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

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

t_list2	*new_list2(size_t size, void *(*gen)(void),
			void (*gen_failsafe)(void *dt))
{
	size_t	index;
	t_list2	*list;
	t_list2	*node;

	list = NULL;
	index = 0;
	while (index < size)
	{
		if (gen)
		{
			node = new_node2(gen(), gen_failsafe);
			if (!node)
				return (lst_destroy2(list, gen_failsafe));
		}
		else
		{
			node = new_node2(NULL, NULL);
			if (!node)
				return (lst_destroy2(list, NULL));
		}
		lst_prepend2(&list, node);
		index++;
	}
	lst_rev2(list);
	return (list);
}

void	lst_foreach2(t_list2 *head, void (*func)(t_list2 *node))
{
	if (!head || !func)
		return ;
	while (head)
	{
		func(head);
		head = head->next;
	}
}
