/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_addition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:41:34 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/26 12:39:01 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	lst_insert(t_list **head, t_list *node, size_t index)
{
	t_list	*curr;
	size_t	i;

	i = 0;
	if (!node || !head || *head == node)
		return ;
	curr = *head;
	if (!*head || index == 0)
	{
		node->next = *head;
		*head = node;
		return ;
	}
	while (i <= index && curr->next)
	{
		if ((i + 1) == index)
		{
			node->next = curr->next;
			curr->next = node;
			return ;
		}
		curr = curr->next;
		i++;
	}
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
	t_list	*curr;
	t_list	*next;
	size_t	i;

	i = 0;
	if (!list || !head || *head == list)
		return ;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		if (i++ == index)
		{
			curr->next = list;
			(last_node(list))->next = next;
			if (index == 0)
				*head = list;
			return ;
		}
		curr = curr->next;
	}
	if (!*head)
		*head = list;
}

void	*list_to_array(t_list *head, size_t data_size)
{
	size_t	index;
	void	*array;
	t_list	*tmp;
	size_t	size;

	size = lst_len(head);
	if (!head || !size)
		return ;
	array = malloc(data_size * size);
	if (!array)
		return (NULL);
	tmp = head;
	index = 0;
	while (tmp)
	{
		ft_memcpy(&array[index], tmp->data, data_size);
		tmp = tmp->next;
		index++;
	}
	return (array);
}