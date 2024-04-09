/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_removal_extra.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:58:03 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/27 10:55:05 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

static void	link_helper(t_list **head, t_list *curr, t_list **prev);

void	lst_del_if(t_list **head, int (*cmp)(void *dt), void (*del)(void *dt))
{
	t_list	*prev;
	t_list	*tmp;

	if (!head || !*head || !cmp)
		return ;
	tmp = *head;
	prev = *head;
	while (tmp)
	{
		if (cmp(tmp->data))
		{
			link_helper(head, tmp, &prev);
			del_node(tmp, del);
			tmp = prev;
		}
		else
		{
			if (prev->next == tmp)
				prev = prev->next;
			tmp = tmp->next;
		}
	}
}

void	lst_del_from(t_list **head, t_list *from,
			t_list *to, void (*f)(void *dt))
{
	t_list	*tmp;
	t_list	*safe;

	if (!head || !*head || !from)
		return ;
	tmp = *head;
	safe = *head;
	while (tmp && tmp != from && tmp->next != from)
		tmp = tmp->next;
	if (!tmp)
		return ;
	if (tmp == from)
		tmp = NULL;
	while (from && from != to)
	{
		safe = from->next;
		if (*head == from)
			*head = safe;
		del_node(from, f);
		from = safe;
	}
	link_node(tmp, safe);
}

void	lst_del_node(t_list **head, t_list *node, void (*del)(void *data))
{
	t_list	*tmp;

	if (!head || !*head | !node)
		return ;
	tmp = *head;
	while (tmp && tmp != node && tmp->next != node)
		tmp = tmp->next;
	if (!tmp)
		return ;
	if (tmp == *head)
		*head = tmp->next;
	else
	{
		link_node(tmp, node->next);
		tmp = tmp->next;
	}
	del_node(tmp, del);
}

void	lst_divide_at(t_list **head, t_list **list_ptr, size_t index)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	if (!head || !*head || !list_ptr)
		return ;
	tmp = *head;
	if (index == 0)
	{
		*list_ptr = *head;
		*head = NULL;
		return ;
	}
	while ((i + 1) < index)
	{
		tmp = tmp->next;
		if (!tmp)
			return ;
		i++;
	}
	*list_ptr = *head;
	*head = tmp->next;
	tmp->next = NULL;
}

static void	link_helper(t_list **head, t_list *curr, t_list **prev)
{
	if (curr == *head)
	{
		*head = curr->next;
		*prev = *head;
	}
	link_node(*prev, curr->next);
}
