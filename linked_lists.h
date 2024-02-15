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


// free_struct.c
void		clear_list(t_list **head, int free_data);
void		clear_list2(t_list2 **head, int free_data);

// new_struct.c
t_list		*new_node();
t_list2		*new_node2();

// lnk_list.c
void		lst_insert(t_list **head, t_list *node, size_t index);
void		lst_delete(t_list **head, size_t index);
t_list		*lst_pop(t_list **head, size_t index);
t_list		*lst_slice(t_list **head, size_t start, size_t end);

// lnk_list_extra.c
void		lst_append(t_list **head, t_list *node);
void		lst_extend(t_list **head, size_t index, t_list *list);
size_t		lst_len(t_list *head);
void		lst_sort(t_list *head, int (*cmp)(void *data1, void *data2));
void		lst_rev(t_list **head);

// helpers.c
void		*ft_memdup(void *data, size_t data_size);
t_list		*get_node(t_list *head, size_t index);
t_list		*last_node(t_list *head);
void    	ft_swap(void **ptr1, void **ptr2);

#endif
