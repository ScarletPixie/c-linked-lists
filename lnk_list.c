#include "linked_lists.h"

t_list      *lst_insert(t_list *head, t_list *node, size_t index)
{
	t_list	*curr;
	size_t	i;

	if (!head || !node)
		return (node);
	curr = head;
	i = 0;
	while (curr)
	{
		if (i == index)
		{
			node->next = curr->next;
			if (index == 0)
				head = node
			else
				curr->next = node;
			break ;
		}
		curr = curr->next;
		i++;
	}
	return (head);
}

t_list      *lst_delete(t_list *head, size_t index);
{
	t_list	*curr;
	t_list	*next;
	size_t	i;

	if (!head)
		return (NULL);
	curr = head;
	i = 0;
	while (curr)
	{
		next = curr->next;
		if (i == index)
		{
			if (index == 0)
				head = next;
			free(curr);
			curr = next;
			break ;
		}
		curr = curr->next;
		i++;
	}
	return (head)
}

t_list      *lst_pop(t_list **head, size_t index)
{
	t_list	*curr;
	t_list	*next;
	t_list	*pop;
	size_t	i;

	if (!head)
		return (NULL);
	curr = *head;
	i = 0;
	if (index == 0)
		*head = (*head)->next;
	while (curr->next)
	{
		next = (curr->next)->next;;
		if ((i + 1) == index)
		{
			pop = ft_memdup(curr->next, sizeof(t_list));
			curr->next = next;
			pop->next = NULL;
			return (pop);
		}
		i++;
		curr = curr-next;
	}
	return (NULL);
}
t_list      *lst_slice(t_list *head, size_t start, size_t end)
{
	
}
t_list      *lst_extend(t_list *head, size_t index);
