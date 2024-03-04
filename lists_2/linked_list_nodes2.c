/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_nodes2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:51:20 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/04 10:00:28 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list2	*get_node2(t_list2 *head, size_t index)
{
	size_t	i;

	i = 0;
	while (head && (i < index))
	{
		head = head->next;
		i++;
	}
	return (head);
}

t_list2	*last_node2(t_list2 *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	link_node2(t_list2 *node1, t_list2 *node2)
{
	if (node1)
		node1->next = node2;
	if (node2)
		node2->prev = node1;
}

t_list2	*cut_node2(t_list2 *node)
{
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list2	*first_node(t_list2 *last)
{
	if (!last)
		return (NULL);
	while (last->prev)
		last = last->prev;
	return (last);
}