#include "linked_lists.h"

void	*ft_memdup(void *data, size_t data_size)
{
	size_t			i;
	unsigned char	*dup;
	unsigned char	*tpd;

	if (!data || !data_size)
		return (NULL);
	dup = malloc(data_size);
	if (!dup)
		return (NULL);
	i = 0;
	tpd = (unsigned char *)data;
	while (i < data_size)
	{
		dup[i] = tpd[i];
		i++;
	}
	return ((void *)dup);
}

t_list	*get_node(t_list *head, size_t index)
{
	t_list	*curr;
	size_t	i;

	i = 0;
	curr = head;
	while (curr)
	{
		if (i == index)
			return (curr);
		i++;
		curr = curr->next;
	}
	return (curr);
}

t_list	*last_node(t_list *head)
{
	if (!head)
		return (NULL);
	while(head->next)
		head = head->next;
	return (head);
}

void	ft_swap(void **ptr1, void **ptr2)
{
	void *tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
