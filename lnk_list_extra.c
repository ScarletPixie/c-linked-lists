#include "linked_lists.h"

void	lst_append(t_list **head, t_list *node)
{
	t_list	*last;

	if (!node || !head)
		return ;
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

void	lst_rev(t_list **head)
{
	t_list	*tmp;
	t_list	*og_head;
	size_t	len;
	size_t	i;

	i = 0;
	if (!head || !*head)
		return ;
	len = lst_len(*head);
	if (!len)
		return ;
	og_head = *head;
	*head = NULL;
	while (i < len)
	{
		tmp = lst_pop(&og_head, lst_len(og_head) - 1);
		lst_append(head, tmp);
		i++;
	}
}

void      lst_extend(t_list **head, size_t index, t_list *list)                         {
    t_list  *curr;
    t_list  *next;
    size_t  i;                                                                          

	i = 0;
	if (!list || !head)
		return ;
	curr = *head;
	while (curr)
    {
		next = curr->next;
		if (i == index)
		{
			curr->next = list;
			(last_node(list))->next = next;
			if (index == 0)
				*head = list;
			return ;
		}
		curr = curr->next;
		i++;
    }
	if (!*head)
		*head = list;
}
