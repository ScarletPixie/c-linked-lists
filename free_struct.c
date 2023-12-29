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
		if (free_data = 1)
			free((*head)->data);
		free(*head);
		*head = tmp;
	}
}

void	empty_stack(t_stack *stack, int free_data)
{
	stack->size = 0;
	clear_list(&stack->top, free_data);
	stack->bottom = NULL;
}

void	empty_stack2(t_stack2 *stack, int free_data)
{
	stack->size = 0;
	clear_list2(&stack->top, free_data);
	stack->bottom = NULL;
}
