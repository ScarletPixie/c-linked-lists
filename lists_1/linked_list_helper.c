/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:44:46 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/08 09:57:44 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	del_node(t_list *node, void (*del)(void *data))
{
	if (!node)
		return ;
	if (del)
		del(node->data);
	free(node);
}
