/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:38:30 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/26 15:33:24 by paulhenr         ###   ########.fr       */
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

t_list2	*get_node2(t_list2 *head, size_t index)
{
	size_t	i;

	i = 0;
	while (i <= index)
	{
		head = head->next;
		i++;
	}
	return (head);
}

t_list2	*last_node2(t_list2 *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_swap(void **ptr1, void **ptr2)
{
	void	*tmp;

	if (!ptr1 || !ptr2)
		return ;
	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
