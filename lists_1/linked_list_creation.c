/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:04:05 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/04 10:22:50 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*arr_to_lst(void *arr, size_t size, size_t data_size)
{
	void	*data;
	t_list	*node;
	t_list	*head;

	if (!arr || !size || !data_size)
		return (NULL);
	head = NULL;
	while (size > 0)
	{
		if (size > 0)
			--size;
		data = ft_memdup(arr + (size * data_size), data_size);
		node = new_node(data, free);
		if (!node)
			return (lst_clear(&head, free), NULL);
		lst_insert(&head, node, 0);
		if (size == 0)
			break ;
	}
	free(arr);
	return (head);
}

void	*lst_to_arr(t_list **head, size_t data_size)
{
	size_t	index;
	void	*array;
	t_list	*tmp;
	size_t	size;

	if (!head || !data_size || !*head)
		return (NULL);
	size = lst_len(*head);
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

t_list	*arr_from_lst(const void *arr, size_t size, size_t data_size)
{
	void	*data;
	t_list	*node;
	t_list	*head;

	if (!arr || !size || !data_size)
		return (NULL);
	head = NULL;
	while (size > 0)
	{
		if (size > 0)
			--size;
		data = ft_memdup(arr + (size * data_size), data_size);
		node = new_node(data, free);
		if (!node)
			return (clear_list(&head, free), NULL);
		lst_insert(&head, node, 0);
		if (size == 0)
			break ;
	}
	return (head);
}

void	*lst_from_arr(const t_list *head, size_t data_size)
{
	void			*array;
	size_t			size;
	size_t			index;
	const t_list	*tmp;

	size = lst_len(head);
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
