/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_creation2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:18:41 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/15 09:36:12 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list2	*new_node2(void *data, void (*failsafe)(void *data))
{
	t_list2	*node;

	node = malloc(sizeof(t_list2));
	if (!node)
	{
		if (failsafe)
			failsafe(data);
		return (NULL);
	}
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_list2	*arr_to_list2(void *arr, size_t size, size_t data_size)
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
		data = lst_ft_memdup(arr + (size * data_size), data_size);
		node = new_node2(data, free);
		if (!node)
			return (lst_clear2(&head, free), NULL);
		lst_insert2(&head, node, 0);
		if (size == 0)
			break ;
	}
	free(arr);
	return (head);
}

t_list2	*list_from_arr2(const void *arr, size_t size, size_t data_size)
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
		data = lst_ft_memdup(arr + (size * data_size), data_size);
		node = new_node2(data, free);
		if (!node)
			return (lst_clear2(&head, free), NULL);
		lst_insert2(&head, node, 0);
		if (size == 0)
			break ;
	}
	return (head);
}

void	*lst_from_arr2(const t_list2 *head, size_t data_size)
{
	void			*array;
	size_t			size;
	size_t			index;
	const t_list2	*tmp;

	size = lst_len2(head);
	if (!head || !size || !data_size)
		return (NULL);
	array = malloc(data_size * size);
	if (!array)
		return (NULL);
	tmp = head;
	index = 0;
	while (tmp)
	{
		lst_ft_memcpy(array + (index * data_size), tmp->data, data_size);
		tmp = tmp->next;
		index++;
	}
	return (array);
}
