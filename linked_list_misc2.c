/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_misc2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:35:48 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/27 13:21:03 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

size_t	lst_len2(t_list2 *head)
{
	size_t	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	lst_sort2(t_list2 *head, int (*cmp)(void *data1, void *data2))
{
	t_list2	*inner;
	t_list2	*outer;

	if (!cmp || !head)
		return ;
	inner = head;
	outer = head;
	while (outer)
	{
		inner = inner->next;
		while (inner)
		{
			if (cmp(outer->data, inner->data) > 0)
				ft_swap(&outer->data, &inner->data);
			inner = inner->next;
		}
		outer = outer->next;
		inner = outer;
	}
}

#include <stdio.h>
void	lst_rev2(t_list2 *head)
{
	size_t	size;
	t_list2	*last;

	if (!head || !head->next)
		return ;
	last = last_node2(head);
	size = (lst_len2(head) / 2);
	while (1)
	{
		if (size > 0)
			size--;
		ft_swap(&head->data, &last->data);
		head = head->next;
		last = last->prev;
		if (size == 0)
			break ;
	}
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
	return (NULL);
}
