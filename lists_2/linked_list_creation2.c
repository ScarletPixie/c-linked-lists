/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_creation2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:18:41 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/04 10:27:47 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

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
		data = ft_memdup(arr + (size * data_size), data_size);
		node = new_node2(data, free);
		if (!node)
			return (clear_list2(&head, free), NULL);
		lst_insert2(&head, node, 0);
		if (size == 0)
			break ;
	}
	free(arr);
	return (head);
}

void	*lst_to_arr2(t_list2 **head, size_t data_size)
{
	void	*array;
	size_t	size;
	size_t	index;
	t_list2	*tmp;

	if (!head || !data_size || !*head)
		return (NULL);
	size = lst_len2(*head);
	array = malloc(data_size * size);
	if (!array)
		return (NULL);
	tmp = *head;
	index = 0;
	while (*head)
	{
		(*head) = (*head)->next;
		ft_memcpy(array + (index * data_size), tmp->data, data_size);
		free(tmp);
		tmp = *head;
		index++;
	}
	return (array);
}

t_list2	*arr_from_list2(const void *arr, size_t size, size_t data_size)
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
		ft_memcpy(array + (index * data_size), tmp->data, data_size);
		tmp = tmp->next;
		index++;
	}
	return (array);
}
