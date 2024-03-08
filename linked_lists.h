/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:35:25 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/08 16:51:01 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H

# include "typedefs.h"
# include <stdlib.h>

/*****************************************************************************/
// SINGLY LINKED LISTS

// linked_list_addition.c
void		lst_append(t_list **head, t_list *node);
void		lst_extend(t_list **head, t_list *list, size_t index);
void		lst_insert(t_list **head, t_list *node, size_t index);
void		lst_prepend(t_list **head, t_list *node);

// linked_list_removal.c
void		lst_delete(t_list **head, size_t index, void (*func)(void *data));
t_list		*lst_slice(t_list **head, size_t start, size_t end);
t_list		*lst_pop(t_list **head, size_t index);

// linked_list_removal_extra.c
void		lst_del_if(t_list **head,
				int (*cmp)(void *dt), void (*del)(void *dt));

void		lst_del_from(t_list **head, t_list *from,
				t_list *to, void (*f)(void *dt));

void		lst_del_node(t_list **head, t_list *node, void (*del)(void *data));

// linked_list_misc.c
void		lst_sort(t_list *head, int (*cmp)(void *data1, void *data2));
void		lst_rev(t_list *head);
size_t		lst_len(const t_list *head);
t_list		*get_node_if(t_list *head, int (*func)(void *data));

// linked_list_nodes.c
void		link_node(t_list *node1, t_list *node2);
t_list		*get_node(t_list *head, size_t index);
t_list		*last_node(t_list *head);
t_list		*cut_node(t_list *node);

// linked_list_creation.c
void		*arr_from_lst(const t_list *head, size_t data_size);
t_list		*arr_to_lst(void *arr, size_t size, size_t data_size);
t_list		*lst_from_arr(const void *arr, size_t size, size_t data_size);

// linked_list_helper.c
void		del_node(t_list *node, void (*del)(void *data));

/*****************************************************************************/

/*****************************************************************************/
// DOUBLY LINKED LISTS

// linked_list_addition2.c
void		lst_append2(t_list2 **head, t_list2 *node);
void		lst_extend2(t_list2 **head, t_list2 *list, size_t index);
void		lst_insert2(t_list2 **head, t_list2 *node, size_t index);
void		lst_prepend2(t_list2 **head, t_list2 *node);

// linked_list_removal2.c
void		lst_delete2(t_list2 **head, size_t index, void (*func)(void *data));
t_list2		*lst_pop2(t_list2 **head, size_t index);
t_list2		*lst_slice2(t_list2 **head, size_t start, size_t size);

// linked_list_removal_extra2.c
void		lst_del_if2(t_list2 **head,
				int (*cmp)(void *d), void (*del)(void *d));

void		lst_del_from2(t_list2 **head, t_list2 *from,
				t_list2 *to, void (*f)(void *dt));

void		lst_del_node(t_list2 **head, t_list2 *node, void (*del)(void *dt));

// linked_list_nodes2.c
void		link_node2(t_list2 *node1, t_list2 *node2);
t_list2		*first_node(t_list2 *last);
t_list2		*cut_node2(t_list2 *node);
t_list2		*get_node2(t_list2 *head, size_t index);
t_list2		*last_node2(t_list2 *head);

// linked_list_creation2.c
void		*lst_from_arr2(const t_list2 *head, size_t data_size);
t_list2		*arr_to_list2(void *arr, size_t size, size_t data_size);
t_list2		*list_from_arr2(const void *arr, size_t size, size_t data_size);

// linked_list_misc2.c
void		lst_rev2(t_list2 *head);
void		lst_sort2(t_list2 *head, int (*cmp)(void *data1, void *data2));
size_t		lst_len2(const t_list2 *head);
t_list2		*get_node_if2(t_list2 *head, int (*func)(void *data));

// linked_list_helper2.c
void		del_node2(t_list2 *node, void (*del)(void *data));

/*****************************************************************************/

/*****************************************************************************/
// OTHER

// get_data.c / get_data_extra.c
int			*int_from_data(void *data);
char		*str_from_data(void *data);
long		*long_from_data(void *data);
float		*float_from_data(void *data);
double		*double_from_data(void *data);
size_t		*zu_from_data(void *data);
t_list		*t_list_from_data(void *data);
t_list2		*t_list2_from_data(void *data);

// utils.c
void		*lst_ft_memdup(const void *data, size_t data_size);
void		lst_ft_memcpy(void *dest, const void *source, size_t data_size);
void		lst_ft_swap(void **ptr1, void **ptr2);

// structs.c
void		lst_clear(t_list **head, void (*func)(void *data));
void		lst_clear2(t_list2 **head, void (*func)(void *data));
t_list		*new_node(void *data, void (*failsafe)(void *data));
t_list2		*new_node2(void *data, void (*failsafe)(void *data));

/*****************************************************************************/

#endif
