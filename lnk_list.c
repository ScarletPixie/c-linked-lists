#include "linked_lists.h"

t_list      *lst_insert(t_list **head, t_list *node, size_t index)
{
	t_list	*curr;
	size_t	i;

	if (!*head)
	{
		*head = node;
		return (*head);
	}
	curr = *head;
	i = 0;
	while (curr)
	{
		if (i == index)
		{
			node->next = curr->next;
			if (index == 0)
				*head = node
			else
				curr->next = node;
			break ;
		}
		curr = curr->next;
		i++;
	}
	return (*head);
}

t_list      *lst_delete(t_list **head, size_t index);
{
	t_list	*curr;
	t_list	*next;
	size_t	i;

	if (!*head)
		return (NULL);
	curr = *head;
	i = 0;
	while (curr)
	{
		next = curr->next;
		if (i == index)
		{
			if (index == 0)
				*head = next;
			free(curr);
			curr = next;
			break ;
		}
		curr = curr->next;
		i++;
	}
	return (*head)
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
	while (curr)
	{
		next = curr->next;;
		if (i == index)
		{
			if (index == 0)
				*head = (*head)->next;
			pop = curr;
			curr = next;
			pop->next = NULL;
			return (pop);
		}
		i++;
		curr = curr->next;
	}
	return (NULL);
}
t_list	*lst_slice(t_list **head, size_t start, size_t end)
{
	t_list	*curr;
	t_list	*next;
	t_list	*subl;
	size_t	i;

	i = 0;
	curr = *head;
	while (curr)
	{
		if (i == start)
		{
			subl = curr;
			next = get_node(curr, end);
			curr = NULL;
			if (next && next->next)
				curr = (next->next)->next;
			next->next = NULL;
			if (start == 0)
				*head = curr;
			return (subl);
		}
		curr = curr->next;
		i++;
	}
	return (NULL);
}

t_list      *lst_extend(t_list **head, size_t index, t_list	*list)
{
	t_list	*curr;
	t_list	*next;
	size_t	i;

	i = 0;
	curr = *head;
	if (!list)
		return (*head);
	while (curr)
	{
		next = curr->next;
		if (i == index)
		{
			curr->next = list;
			(last_node(list))->next = next;
			if (index == 0)
				*head = list;
			return (*head);
		}
		curr = curr->next;
		i++;
	}
	return (head);
}
