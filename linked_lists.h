/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:35:25 by paulhenr          #+#    #+#             */
/*   Updated: 2023/12/24 12:07:02 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_LIST_H
# define LINK_LIST_H

#include <stdlib.h>
#include "typedefs.h"

// helpers.c
void		*ft_memdup(void *data, size_t data_size);

// free_struct.c
t_list		*clear_list(t_list *head);
t_dblist	*clear_list2(t_dblist *head);
t_stack		*clear_stack(t_stack *stack);
t_stack2	*clear_stack2(t_stack2 *stack);

// new_struct.c
t_list		new_node();
t_dblist	new_node2();
t_stack		init_stack();
t_stack2	init_stack2();

// lnk_list.c
t_list		*lst_insert(t_list *head, t_list *node, size_t index);
t_list		*lst_delete(t_list *head, size_t index);
t_list		*lst_pop(t_list *head, size_t index);
t_list		*lst_slice(t_list *head, size_t start, size_t end);
t_list		*lst_extend(t_list *head, size_t index);

// lnk_list_extra.c
t_list		*lst_append(t_list *head, t_list *node);
size_t		*lst_len(t_list *head);
t_list		*lst_tail(t_list *head);
t_list		*lst_sort(t_list *head, int (*cmp(void *data1, void *data2)));
t_list		*lst_rev(t_list *head);

#endif
