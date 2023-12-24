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
t_list		*clear_list(t_list *head);
t_dblist	*clear_list2(t_dblist *head);
t_stack		*clear_stack(t_stack *stack);
t_stack2	*clear_stack2(t_stack2 *stack);

// new_struct.c
t_list		new_node();
t_dblist	new_node2();
t_stack		init_stack();
t_stack2	init_stack2();

#endif