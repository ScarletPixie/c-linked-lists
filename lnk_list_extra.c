#include "linked_lists.h"

void	lst_append(t_list **head, t_list *node)
{
	t_list	*last;

	if (!*head)
	{
		*head = node;
		return ;
	}
	last = last_node(*head);
	last->next = node;
}

size_t	lst_len(t_list *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	lst_sort(t_list *head, int (*cmp)(void *data1, void *data2))
{
	t_list	*inner;
	t_list	*outer;

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

void	lst_rev(t_list **head)
{
	t_list	*tmp;
	t_list	*og_head;

	og_head = *head;
	while (last_node(*head) != og_head)
	{
		tmp = lst_pop(head, lst_len(*head) -2);
		lst_insert(head, tmp, 0);				
	}
}
