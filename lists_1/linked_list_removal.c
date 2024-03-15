/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_removal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:01:59 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/15 10:00:08 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	lst_del_at(t_list **head, size_t index, void (*del)(void *data))
{
	t_list	*curr;
	t_list	*prev;
	size_t	i;

	i = 0;
	prev = *head;
	curr = *head;
	if (!head || !*head)
		return ;
	while (curr)
	{
		if (i == index)
		{
			prev->next = curr->next;
			if (index == 0)
				*head = curr->next;
			del_node(curr, del);
			return ;
		}
		curr = curr->next;
		if (i > 0)
			prev = prev->next;
		i++;
	}
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

	if (!head || !*head || !size)
		return (NULL);
	curr = *head;
	sub_list = get_node(*head, start);
	if (!sub_list)
		return (NULL);
	while (curr && (curr->next != sub_list) && (curr != sub_list))
		curr = curr->next;
	if (curr != sub_list)
		curr = cut_node(curr);
	next = get_node(sub_list, size - 1);
	if (next)
	{
		if (start > 0 && (curr != sub_list))
			curr->next = next->next;
	}
	if (start == 0)
		(*head) = get_node(next, 1);
	next = cut_node(next);
	return (sub_list);
}

t_list	*lst_destroy(t_list *head, void (*del)(void *data))
{
	t_list	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp)
	{
		tmp = head->next;
		del_node(head, del);
		head = tmp;
	}
	return (NULL);
}
void	del_node(t_list *node, void (*del)(void *data))
{
	if (!node)
		return ;
	if (del)
		del(node->data);
	free(node);
}
