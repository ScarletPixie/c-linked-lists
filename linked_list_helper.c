/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:38:30 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/26 15:25:37 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	*ft_memdup(const void *data, size_t data_size)
{
	size_t			i;
	unsigned char	*dup;
	unsigned char	*tpd;

	if (!data || !data_size)
		return (NULL);
	dup = malloc(data_size);
	if (!dup)
		return (NULL);
	i = 0;
	tpd = (unsigned char *)data;
	while (i < data_size)
	{
		dup[i] = tpd[i];
		i++;
	}
	return ((void *)dup);
}

void	ft_memcpy(void *dest, const void *source, size_t data_size)
{
	size_t			index;
	unsigned char	*dst;
	unsigned char	*src;

	if (!source || !data_size || !dest)
		return ;
	index = 0;
	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	while (index < data_size)
	{
		dst[index] = src[index];
		index++;
	}
}

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

void	ft_swap(void **ptr1, void **ptr2)
{
	void	*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
