/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_misc2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:35:48 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/15 14:02:35 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

size_t	lst_len2(const t_list2 *head)
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

t_list2	*get_node_if2(t_list2 *head, int (*func)(void *data))
{
	if (!head || !func)
		return (NULL);
	while (head)
	{
		if (func(head->data))
			return (head);
		head = head->next;
	}
	return (NULL);
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
				lst_ft_swap(&outer->data, &inner->data);
			inner = inner->next;
		}
		outer = outer->next;
		inner = outer;
	}
}

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
		lst_ft_swap(&head->data, &last->data);
		head = head->next;
		last = last->prev;
		if (size == 0)
			break ;
	}
}

void	lst_print2(t_list2 *head, void (*print_data)(void *dt))
{
	if (!print_data || !head)
		return ;
	while (head)
	{
		print_data(head->data);
		head = head->next;
	}
}