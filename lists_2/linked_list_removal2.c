/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_removal2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:02:50 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/15 09:57:35 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	lst_del_at2(t_list2 **head, size_t index, void (*del)(void *data))
{
	size_t	i;
	t_list2	*curr;

	i = 0;
	curr = *head;
	if (!head || !*head)
		return ;
	if (index == 0)
		*head = (*head)->next;
	while (i < index && curr->next)
	{
		i++;
		curr = curr->next;
	}
	if (!curr)
		return ;
	if (i == index)
	{
		link_node2(curr->prev, curr->next);
		del_node2(curr, del);
	}
}

t_list2	*lst_pop2(t_list2 **head, size_t index)
{
	size_t	i;
	t_list2	*curr;

	i = 0;
	if (!head || !*head)
		return (NULL);
	curr = *head;
	while (i < index && curr->next)
	{
		curr = curr->next;
		i++;
	}
	if (i == index)
	{
		if (index == 0)
			*head = (*head)->next;
		link_node2(curr->prev, curr->next);
		return (cut_node2(curr));
	}
	return (NULL);
}

t_list2	*lst_slice2(t_list2 **head, size_t start, size_t size)
{
	t_list2	*curr;
	t_list2	*next;
	t_list2	*sub_list;

	if (!head || !*head || !size)
		return (NULL);
	sub_list = get_node2(*head, start);
	if (!sub_list)
		return (NULL);
	curr = sub_list->prev;
	sub_list->prev = NULL;
	next = get_node2(sub_list, size - 1);
	link_node2(curr, get_node2(next, 1));
	if (start == 0)
		(*head) = get_node2(next, 1);
	if (next)
		next->next = NULL;
	return (sub_list);
}

t_list2	*lst_destroy2(t_list2 *head, void (*del)(void *data))
{
	t_list2	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp)
	{
		tmp = head->next;
		del_node2(head, del);
		head = tmp;
	}
	return (NULL);
}
