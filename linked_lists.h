/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:35:25 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/27 10:20:36 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H

# include <stdlib.h>
# include "typedefs.h"

// structs.c
void		clear_list(t_list **head, void (*func)(void *data));
void		clear_list2(t_list2 **head, void (*func)(void *data));
t_list		*new_node(void *data, void (*failsafe)(void *data));
t_list2		*new_node2(void *data, void (*failsafe)(void *data));

// linked_list_addition.c
void		lst_insert(t_list **head, t_list *node, size_t index);
void		lst_append(t_list **head, t_list *node);
void		lst_extend(t_list **head, size_t index, t_list *list);
void		*list_to_array(t_list *head, size_t data_size);
t_list		*array_to_list(const void *arr, size_t size, size_t data_size);

// linked_list_removal.c
void		lst_delete(t_list **head, size_t index, void (*func)(void *data));
t_list		*lst_slice(t_list **head, size_t start, size_t end);
t_list		*lst_pop(t_list **head, size_t index);

// linked_list_misc.c
void		lst_sort(t_list *head, int (*cmp)(void *data1, void *data2));
void		lst_rev(t_list *head);
t_list		*cut_node(t_list *node);
size_t		lst_len(t_list *head);

// linked_list_helper.c
void		ft_swap(void **ptr1, void **ptr2);
t_list		*get_node(t_list *head, size_t index);
t_list		*last_node(t_list *head);
t_list2		*get_node2(t_list2 *head, size_t index);
t_list2		*last_node2(t_list2 *head);

// utils.c
void		*ft_memdup(const void *data, size_t data_size);
void		ft_memcpy(void *dest, const void *source, size_t data_size);

// linked_list_addition2.c
void		lst_insert2(t_list2 **head, t_list2 *node, size_t index);
void		lst_append2(t_list2 **head, t_list2 *node);
void		lst_extend2(t_list2 **head, size_t index, t_list2 *list);
void		*list_to_array2(t_list2 *head, size_t data_size);
t_list2		*array_to_list2(const void *arr, size_t size, size_t data_size);

// linked_list_misc2.c
void		lst_rev2(t_list2 *head);
void		lst_sort2(t_list2 *head, int (*cmp)(void *data1, void *data2));
void		link_node2(t_list2 *node1, t_list2 *node2);
size_t		lst_len2(t_list2 *head);
t_list2		*cut_node2(t_list2 *node);

// linked_list_removal2.c
void		lst_delete2(t_list2 **head, size_t index, void (*func)(void *data));
t_list2		*lst_pop2(t_list2 **head, size_t index);
t_list2		*lst_slice2(t_list2 **head, size_t start, size_t size);

#endif
