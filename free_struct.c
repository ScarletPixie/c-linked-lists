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

t_list	clear_list(t_list *head)
{
	t_list	*tmp;

	if (!head)
		return (NULL);
	tmp = head
	while (tmp)
	{
		tmp = head->next;
		free(head)
		head = tmp;
	}
	return (head)
}

t_dblist	clear_list2(t_dblist *head)
{
	t_dblist	*tmp

	if (!head)
		return (NULL);
	tmp = head
	while (tmp)
	{
		tmp = head->next;
		free(head)
		head = tmp;
	}
	return (head);
}

t_stack	clear_stack(t_stack *stack)
{
	stack->size = 0
	stack->top = clear_list(stack->top);
	stack->bottom = NULL;
}

t_stack2	clear_stack2(t_stack2 *stack)
{
	stack->size = 0
	stack->top = clear_list2(stack->top);
	stack->bottom = NULL;
}
