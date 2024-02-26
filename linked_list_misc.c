/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_misc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:40:36 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/26 12:21:54 by paulhenr         ###   ########.fr       */
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

void	lst_rev(t_list **head)
{
	t_list	*tmp;
	t_list	*og_head;
	size_t	len;
	size_t	i;

	i = 0;
	if (!head || !*head)
		return ;
	len = lst_len(*head);
	if (!len)
		return ;
	og_head = *head;
	*head = NULL;
	while (i < len)
	{
		tmp = lst_pop(&og_head, lst_len(og_head) - 1);
		lst_append(head, tmp);
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