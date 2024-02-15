/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:58:54 by paulhenr          #+#    #+#             */
/*   Updated: 2023/12/24 11:29:49 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	clear_list(t_list **head, int free_data)
{
	t_list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp)
	{
		tmp = (*head)->next;
		if (free_data == 1)
			free((*head)->data);
		free(*head);
		*head = tmp;
	}
}

void	clear_list2(t_list2 **head, int free_data)
{
	t_list2	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while (tmp)
	{
		tmp = (*head)->next;
		if (free_data == 1)
			free((*head)->data);
		free(*head);
		*head = tmp;
	}
}
