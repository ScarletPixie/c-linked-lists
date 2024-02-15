/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:29:22 by paulhenr          #+#    #+#             */
/*   Updated: 2023/12/24 12:07:17 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list		*new_node(void)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = NULL;
	node->next = NULL;
	return (node);
}

t_list2	*new_node2(void)
{
	t_list2	*node;

	node = malloc(sizeof(t_list2));
	if (!node)
		return (NULL);
	node->data = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack		*new_stack(void)
{
	t_stack	*stk;

	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->size = 0;
	stk->top = NULL;
	stk->bottom = NULL;
	return (stk);
}

t_stack2	*new_stack2(void)
{
	t_stack2	*stk;

	stk = malloc(sizeof(t_stack2));
	if (!stk)
		return (NULL);
	stk->size = 0;
	stk->top = NULL;
	stk->bottom = NULL;
	return (stk);
}
