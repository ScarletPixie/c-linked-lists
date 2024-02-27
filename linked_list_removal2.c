/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_removal2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:02:50 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/27 13:51:06 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

static void	del_func(t_list2 **head, size_t index, void (*func)(void *data));
static void	del_no_func(t_list2 **head, size_t index);

void	lst_delete2(t_list2 **head, size_t index, void (*func)(void *data))
{
	if (!head || !*head)
		return ;
	if (func)
		del_func(head, index, func);
	else
		del_no_func(head, index);
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
	curr = *head;
	sub_list = get_node2(*head, start);
	if (!sub_list)
		return (NULL);
	while (curr && (curr->next != sub_list) && (curr != sub_list))
		curr = curr->next;
	if (curr != sub_list)
		curr = cut_node2(curr);
	next = get_node2(sub_list, size - 1);
	if (next)
	{
		if (start > 0 && (curr != sub_list))
			curr->next = next->next;
	}
	if (start == 0)
		(*head) = get_node2(next, 1);
	next = cut_node2(next);
	return (sub_list);
}

static void	del_func(t_list2 **head, size_t index, void (*func)(void *data))
{
	size_t	i;
	t_list2	*curr;

	i = 0;
	curr = *head;
	if (index == 0)
		*head = (*head)->next;
	while (i < index && curr->next)
	{
		i++;
		curr = curr->next;
	}
	if (i == index)
	{
		link_node2(curr->prev, curr->next);
		func(curr->data);
		free(curr);
	}
}

static void	del_no_func(t_list2 **head, size_t index)
{
	size_t	i;
	t_list2	*curr;

	i = 0;
	curr = *head;
	if (index == 0)
		*head = (*head)->next;
	while (i < index && curr->next)
	{
		i++;
		curr = curr->next;
	}
	if (i == index)
	{
		link_node2(curr->prev, curr->next);
		free(curr);
	}
}
