/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:35:25 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/15 15:49:23 by paulhenr         ###   ########.fr       */
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
void		lst_prepend(t_list **head, t_list *node);
void		lst_extend(t_list **head, t_list *list, size_t index);
void		lst_insert(t_list **head, t_list *node, size_t index);
void		lst_insert_next(t_list **head, t_list *new_node, t_list *node);

// linked_list_removal.c
void		lst_del_at(t_list **head, size_t index, void (*del)(void *data));
void		del_node(t_list *node, void (*del)(void *data));
t_list		*lst_destroy(t_list *head, void (*del)(void *data));
t_list		*lst_slice(t_list **head, size_t start, size_t end);
t_list		*lst_pop(t_list **head, size_t index);

// linked_list_removal_extra.c
void		lst_del_node(t_list **head, t_list *node, void (*del)(void *data));

void		lst_del_if(t_list **head,
				int (*cmp)(void *dt), void (*del)(void *dt));

void		lst_del_from(t_list **head, t_list *from,
				t_list *to, void (*f)(void *dt));

// linked_list_misc.c
void		lst_sort(t_list *head, int (*cmp)(void *data1, void *data2));
void		lst_rev(t_list *head);
void		lst_print(t_list *head, void (*print_data)(void *dt));
size_t		lst_len(const t_list *head);
t_list		*get_node_if(t_list *head, int (*func)(void *data));

// linked_list_nodes.c
void		link_node(t_list *node1, t_list *node2);
t_list		*get_node(t_list *head, size_t index);
t_list		*last_node(t_list *head);
t_list		*cut_node(t_list *node);

// linked_list_creation.c
void		lst_foreach(t_list *head, void (*func)(t_list *node));
t_list		*lst_map(t_list *head, t_list *(*func)(void *dt));

t_list		*new_node(void *data, void (*failsafe)(void *data));

t_list		*new_list(size_t size, void *(*gen)(void),
				void (*gen_failsafe)(void *dt));

/*****************************************************************************/

/*****************************************************************************/
// DOUBLY LINKED LISTS

// linked_list_addition2.c
void		lst_append2(t_list2 **head, t_list2 *node);
void		lst_prepend2(t_list2 **head, t_list2 *node);
void		lst_extend2(t_list2 **head, t_list2 *list, size_t index);
void		lst_insert2(t_list2 **head, t_list2 *node, size_t index);
void		lst_insert_next2(t_list2 **head, t_list2 *new_node, t_list2 *node);

// linked_list_removal2.c
void		lst_del_at2(t_list2 **head, size_t index, void (*del)(void *data));
void		del_node2(t_list2 *node, void (*del)(void *data));
t_list2		*lst_destroy2(t_list2 *head, void (*del)(void *data));
t_list2		*lst_pop2(t_list2 **head, size_t index);
t_list2		*lst_slice2(t_list2 **head, size_t start, size_t size);

// linked_list_removal_extra2.c
void		lst_del_node2(t_list2 **head, t_list2 *node, void (*del)(void *dt));

void		lst_del_if2(t_list2 **head,
				int (*cmp)(void *d), void (*del)(void *d));

void		lst_del_from2(t_list2 **head, t_list2 *from,
				t_list2 *to, void (*f)(void *dt));

// linked_list_nodes2.c
void		link_node2(t_list2 *node1, t_list2 *node2);
t_list2		*first_node(t_list2 *last);
t_list2		*cut_node2(t_list2 *node);
t_list2		*get_node2(t_list2 *head, size_t index);
t_list2		*last_node2(t_list2 *head);

// linked_list_creation2.c
void		lst_foreach2(t_list2 *head, void (*func)(t_list2 *node));
t_list2		*lst_map2(t_list2 *head, t_list2 *(*func)(void *dt));

t_list2		*new_node2(void *data, void (*failsafe)(void *data));

t_list2		*new_list2(size_t size, void *(*gen)(void),
				void (*gen_failsafe)(void *dt));

// linked_list_misc2.c
void		lst_rev2(t_list2 *head);
void		lst_sort2(t_list2 *head, int (*cmp)(void *data1, void *data2));
void		lst_print2(t_list2 *head, void (*print_data)(void *dt));
size_t		lst_len2(const t_list2 *head);
t_list2		*get_node_if2(t_list2 *head, int (*func)(void *data));

/*****************************************************************************/

/*****************************************************************************/
// OTHER

// utils.c
void		*lst_ft_memdup(const void *data, size_t data_size);
void		lst_ft_memcpy(void *dest, const void *source, size_t data_size);
void		lst_ft_swap(void **ptr1, void **ptr2);

/*****************************************************************************/

#endif
