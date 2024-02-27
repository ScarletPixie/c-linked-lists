#include "linked_lists.h"

size_t	lst_len2(t_list2 *head)
{
	size_t	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void    lst_sort2(t_list2 *head, int (*cmp)(void *data1, void *data2))
{
	t_list2  *inner;
	t_list2  *outer;

	if (!cmp || !head)
		return ;
	inner = head;
	outer = head;
	while (outer)
	{
		inner = inner->next;
		while (inner)
		{
			if (cmp(outer->data, inner->data) > 0)
				ft_swap(&outer->data, &inner->data);
			inner = inner->next;
		}
		outer = outer->next;
		inner = outer;
	}
}

void    lst_rev2(t_list2 *head)
{
	size_t  i;
	t_list2  *tmp;
	t_list2  *tmp2;
	size_t  len;

	i = 0;
	if (!head)
		return ;
	len = lst_len2(head);
	if (!len)
		return ;
	tmp = head;
	while (i < len / 2)
	{
		tmp2 = get_node2(head, lst_len(head) - 1 - i);
		ft_swap(&tmp->data, &tmp2->data);
		tmp = tmp->next;
		i++;
	}
}

t_list2	*cut_node2(t_list2 *node)
{
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (NULL);
}
