/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_removal_extra2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:42:38 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/27 10:56:09 by paulhenr         ###   ########.fr       */
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

void	lst_divide_at2(t_list2 **head, t_list2 **list_ptr, size_t index)
{
	size_t	i;
	t_list2	*tmp;

	if (!head || !*head || !list_ptr)
		return ;
	i = 0;
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
	(*head)->prev = NULL;
	tmp->next = NULL;
}

void	lst_del_node2(t_list2 **head, t_list2 *node, void (*del)(void *dt))
{
	t_list2	*tmp;

	if (!head || !*head || !node)
		return ;
	tmp = *head;
	while (tmp && tmp != node)
		tmp = tmp->next;
	if (!tmp)
		return ;
	if (tmp == *head)
		*head = tmp->next;
	link_node2(tmp->prev, node->next);
	del_node2(tmp, del);
}
