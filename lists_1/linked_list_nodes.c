/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:46:35 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/08 12:53:16 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*get_node(t_list *head, size_t index)
{
	t_list	*curr;
	size_t	i;

	i = 0;
	curr = head;
	while (curr)
	{
		if (i == index)
			return (curr);
		i++;
		curr = curr->next;
	}
	return (curr);
}

t_list	*last_node(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_list	*cut_node(t_list *node)
{
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}

void	link_node(t_list *node1, t_list *node2)
{
	if (!node1 || node1 == node2)
		return ;
	node1->next = node2;
}
