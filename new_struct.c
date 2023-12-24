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

t_list		*new_node()
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = NULL;
	node->next = NULL;
}

t_dblist	*new_node2()
{
	t_dblist	*node;

	node = malloc(sizeof(t_dblist));
	if (!node)
		return (NULL);
	t_dblist->data = NULL;
	t_dblist->next = NULL;
	t_dblist->prev = NULL;
	return (node);
}

t_stack		*init_stack()
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

t_stack2	*init_stack2()
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
