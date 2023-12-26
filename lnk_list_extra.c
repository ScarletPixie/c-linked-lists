#include "linked_lists.h"

t_list      *lst_append(t_list **head, t_list *node)
{
	t_list	*last;

	if (!*head)
	{
		*head = node
		return (*head);
	}
	last = last_node(*head);
	last->next = node;
	return (*head);
}

size_t      *lst_len(t_list *head)
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

void	*lst_sort(t_list *head, int (*cmp(void *data1, void *data2)));
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

t_list      *lst_rev(t_list **head)
{
	t_list	*tmp;

	og_head = *head;
	while (last_node(*head) != og_head)
	{
		insert(head, 0, last_node(*head));		
	}
}
