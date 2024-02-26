/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_removal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:01:59 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/26 16:15:59 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

static void	del_func(t_list **head, size_t index, void (*func)(void *data));
static void del_no_func(t_list **head, size_t index);

void	lst_delete(t_list **head, size_t index, void (*func)(void *data))
{
	if (!head || !*head)
		return ;
	if (func)
		del_func(head, index, func);
	else
		del_no_func(head, index);
}

t_list	*lst_pop(t_list **head, size_t index)
{
	size_t	i;
	t_list	*curr;
	t_list	*prev;

	i = 0;
	if (!head || !*head)
		return (NULL);
	curr = *head;
	prev = *head;
	while (i <= index && curr)
	{
		if (i == index)
		{
			if (index == 0)
				*head = (*head)->next;
			else
				prev->next = curr->next;
			return (cut_node(curr));
		}
		curr = curr->next;
		if (i > 0)
			prev = prev->next;
		i++;
	}
	return (NULL);
}

t_list	*lst_slice(t_list **head, size_t start, size_t size)
{
	t_list	*curr;
	t_list	*next;
	t_list	*sub_list;

	if (!head || !*head)
		return (NULL);
	curr = *head;
	sub_list = get_node(*head, start);
	if (!sub_list)
		return (NULL);
	while (curr && curr->next != sub_list)
		curr = curr->next;
	curr = cut_node(curr);
	next = get_node(sub_list, size);
	if (next)
	{
		if (start == 0)
			(*head)->next = next->next;
		curr->next = next->next;
	}
	next = cut_node(next);
	return (sub_list);
}

static void	del_func(t_list **head, size_t index, void (*func)(void *data))
{
	t_list	*curr;
	t_list	*prev;
	size_t	i;

	i = 0;
	prev = *head;
	curr = *head;
	while (curr)
	{
		if (i == index)
		{
			prev->next = curr->next;
			if (index == 0)
				*head = curr->next;
			func(curr->data);
			free(curr);
			return ;
		}
		curr = curr->next;
		if (i > 0)
			prev = prev->next;
		i++;
	}
}

static void del_no_func(t_list **head, size_t index)
{
	t_list	*curr;
	t_list	*prev;
	size_t	i;

	i = 0;
	prev = *head;
	curr = *head;
	while (curr)
	{
		if (i == index)
		{
			prev->next = curr->next;
			if (index == 0)
				*head = curr->next;
			free(curr);
			return ;
		}
		curr = curr->next;
		if (i > 0)
			prev = prev->next;
		i++;
	}
}