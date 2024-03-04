/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_addition2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:42:49 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/27 15:46:26 by paulhenr         ###   ########.fr       */
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

void	lst_extend2(t_list2 **head, size_t index, t_list2 *list)
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

t_list2	*array_to_list2(const void *arr, size_t size, size_t data_size)
{
	void	*data;
	t_list2	*node;
	t_list2	*head;

	if (!arr || !size || !data_size)
		return (NULL);
	head = NULL;
	while (size > 0)
	{
		if (size > 0)
			--size;
		data = ft_memdup(arr + (size * data_size), data_size);
		node = new_node2(data, free);
		if (!node)
			return (clear_list2(&head, free), NULL);
		lst_insert2(&head, node, 0);
		if (size == 0)
			break ;
	}
	return (head);
}

void	*list_to_array2(t_list2 *head, size_t data_size)
{
	size_t	index;
	void	*array;
	size_t	size;
	t_list2	*tmp;

	size = lst_len2(head);
	if (!head || !size)
		return (NULL);
	array = malloc(data_size * size);
	if (!array)
		return (NULL);
	tmp = head;
	index = 0;
	while (tmp)
	{
		ft_memcpy(array + (index * data_size), tmp->data, data_size);
		tmp = tmp->next;
		index++;
	}
	return (array);
}
