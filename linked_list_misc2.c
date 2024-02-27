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

t_list2	*cut_node2(t_list2 *node)
{
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (NULL);
}
