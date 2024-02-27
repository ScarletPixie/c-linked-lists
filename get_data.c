/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:27:18 by paulhenr          #+#    #+#             */
/*   Updated: 2024/02/27 10:38:33 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

char	*str_from_data(void *data)
{
	return ((char *)data);
}

int	*int_from_data(void *data)
{
	return ((int *)data);
}

float	*float_from_data(void *data)
{
	return ((float *)data);
}

double	*double_from_data(void *data)
{
	return ((double *)data);
}

size_t	*zu_from_data(void *data)
{
	return ((size_t *)data);
}
