/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:46:08 by paulhenr          #+#    #+#             */
/*   Updated: 2023/12/24 10:55:30 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct s_dblist
{
	void			*data;
	struct s_dblist	*next;
	struct s_dblist	*prev;
}					t_dblist;

typedef struct s_stack
{
	size_t			size;
	struct s_list	*top;
	struct s_list	*bottom;
}					t_stack;

typedef struct s_stack2
{
	size_t			size;
	struct s_dblist	*top;
	struct s_dblist	*bottom;
}					t_stack2;

#endif
