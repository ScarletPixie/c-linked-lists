/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_removal_extra.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:42:38 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/08 16:48:41 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	lst_del_if2(t_list2 **head, int (*cmp)(void *d), void (*del)(void *d))
{
	t_list2	*next;
	t_list2	*tmp;

	if (!head || !*head || !cmp)
		return ;
	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		if (cmp(tmp->data))
		{
			if (tmp == *head)
				*head = tmp->next;
			link_node2(tmp->prev, tmp->next);
			del_node2(tmp, del);
			tmp = next;
		}
		else
			tmp = tmp->next;
	}
}

void	lst_del_from2(t_list2 **head, t_list2 *from,
			t_list2 *to, void (*f)(void *dt))
{
	t_list2	*tmp;
	t_list2	*safe;

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
		del_node2(from, f);
		from = safe;
	}
	link_node2(tmp, safe);
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
