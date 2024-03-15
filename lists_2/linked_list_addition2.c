/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_addition2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:42:49 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/15 12:30:25 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	lst_insert2(t_list2 **head, t_list2 *node, size_t index)
{
	size_t	i;
	t_list2	*curr;

	i = 0;
	if (!node || !head || *head == node || node->next || node->prev)
		return ;
	curr = *head;
	if (index == 0 || !*head)
	{
		link_node2(node, *head);
		*head = node;
		return ;
	}
	while (i < index && curr->next)
	{
		i++;
		curr = curr->next;
	}
	if (i == index)
	{
		link_node2(curr->prev, node);
		link_node2(node, curr);
		return ;
	}
	link_node2(curr, node);
}

void	lst_insert_next2(t_list2 **head, t_list2 *new_node, t_list2 *node)
{
	t_list2	*tmp;

	if (!head || !new_node || new_node->next || new_node->prev
		|| (!*head && node) || new_node == *head)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp != node && tmp->next && tmp->next != node)
		tmp = tmp->next;
	link_node2(new_node, tmp->next);
	link_node2(tmp, new_node);
}

void	lst_append2(t_list2 **head, t_list2 *node)
{
	t_list2	*last;

	if (!node || !head || *head == node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	last = last_node2(*head);
	link_node2(last, node);
}

void	lst_prepend2(t_list2 **head, t_list2 *node)
{
	if (!head || !node || node == *head)
		return ;
	link_node2(last_node2(node), *head);
	*head = node;
}

void	lst_extend2(t_list2 **head, t_list2 *list, size_t index)
{
	size_t	i;
	t_list2	*curr;

	i = 0;
	if (!list || !head || *head == list)
		return ;
	curr = *head;
	if (index == 0 || !*head)
	{
		link_node2(last_node2(list), *head);
		*head = list;
		return ;
	}
	while (i < index && curr->next)
	{
		i++;
		curr = curr->next;
	}
	if (i == index)
	{
		link_node2(curr->prev, list);
		link_node2(last_node2(list), curr);
		return ;
	}
	link_node2(curr, list);
}
