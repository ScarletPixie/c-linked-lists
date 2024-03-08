/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_removal_extra.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:58:03 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/08 12:53:47 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	lst_del_if(t_list **head, int (*cmp)(void *dt), void (*del)(void *dt))
{
	t_list	*prev;
	t_list	*tmp;
	t_list	*safe;

	if (!head || !*head || !cmp)
		return ;
	tmp = *head;
	prev = *head;
	while (tmp)
	{
		safe = tmp->next;
		if (prev->next == tmp)
			prev = prev->next;
		if (cmp(tmp->data))
		{
			if (tmp == *head)
				*head = safe;
			del_node(tmp, del);
			link_node(prev, safe);
			tmp = prev;
		}
		else
			tmp = tmp->next;
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
