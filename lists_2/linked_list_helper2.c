/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:42:05 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/08 16:49:44 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	del_node2(t_list2 *node, void (*del)(void *data))
{
	if (!node)
		return ;
	if (del)
		del(node->data);
	free(node);
}
