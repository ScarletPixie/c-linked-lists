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

void    clear_list(t_list **head, void (*f)(void *data))
{
    t_list  *tmp;

    if (!*head)
        return ;
    tmp = *head;
	if (f)
	{
    	while (tmp)
    	{
        	tmp = (*head)->next;
			f((*head)->data);
        	free(*head);
        	*head = tmp;
    	}
		return ;
	}
	while (tmp)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void    clear_list2(t_list2 **head, void (*f)(void *data))
{
    t_list2 *tmp;
                                                                                            if (!*head)
        return ;
    tmp = *head;
	if (f)
	{
    	while (tmp)
		{
	        tmp = (*head)->next;
			f((*head)->data);
        	free(*head);                                                                            *head = tmp;
    	}
		return ;
	}
	while (tmp)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
