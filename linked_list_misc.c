/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_misc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:40:36 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/26 16:07:44 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

size_t	lst_len(t_list *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	lst_sort(t_list *head, int (*cmp)(void *data1, void *data2))
{
	t_list	*inner;
	t_list	*outer;

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

void	lst_rev(t_list *head)
{
	size_t	i;
	t_list	*tmp;
	t_list	*tmp2;
	size_t	len;

	i = 0;
	if (!head)
		return ;
	len = lst_len(head);
	if (!len)
		return ;
	tmp = head;
	while (i < len / 2)
	{
		tmp2 = get_node(head, lst_len(head) - 1 - i);
		ft_swap(&tmp->data, &tmp2->data);
		tmp = tmp->next;
		i++;
	}
}

t_list	*cut_node(t_list *node)
{
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}