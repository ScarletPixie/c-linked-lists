/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_addition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:41:34 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/27 14:53:48 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	lst_insert(t_list **head, t_list *node, size_t index)
{
	t_list	*curr;

	if (!node || !head || *head == node ||
		(node->next != NULL && index != 0 && *head))
		return ;
	if (!*head || index == 0)
	{
		node->next = *head;
		*head = node;
		return ;
	}
	curr = *head;
	while (curr->next && index > 0)
	{
		curr = curr->next;
		index--;
	}
	if (index == 0)
	{
		node->next = curr;
		curr->next = node;
	}
	else
		curr->next = node;
}

void	lst_append(t_list **head, t_list *node)
{
	t_list	*last;

	if (!node || !head || *head == node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	last = last_node(*head);
	last->next = node;
}

void	lst_extend(t_list **head, size_t index, t_list *list)
{
	size_t	i;
	t_list	*curr;

	i = 0;
	if (!list || !head || *head == list)
		return ;
	curr = *head;
	if (index == 0 || !*head)
	{
		last_node(list)->next = *head;
		*head = list;
		return ;
	}
	while (curr->next && i <= index)
	{
		if ((i + 1) == index)
		{
			(last_node(list))->next = curr->next;
			curr->next = list;
			return ;
		}
		curr = curr->next;
		i++;
	}
	curr->next = list;
}

t_list	*array_to_list(const void *arr, size_t size, size_t data_size)
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

void	*list_to_array(t_list *head, size_t data_size)
{
	size_t	index;
	void	*array;
	t_list	*tmp;
	size_t	size;

	size = lst_len(head);
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
