/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:30:54 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/27 10:37:12 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

t_list	*t_list_from_data(void *data)
{
	return ((t_list *)data);
}

t_list2	*t_list2_from_data(void *data)
{
	return ((t_list2 *)data);
}

long	*long_from_data(void *data)
{
	return ((long *)data);
}
