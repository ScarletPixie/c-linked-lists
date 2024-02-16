#include "linked_lists.h"

void	lst_insert(t_list **head, t_list *node, size_t index)
{
	t_list	*curr;
	size_t	i;

	i = 0;
	if (!node || !head)
		return ;
	curr = *head;
	if (!*head || index == 0)
	{
		node->next = *head;
		*head = node;
		return ;
	}
	while (i <= index && curr)
	{
		if (i == index)
		{
			node->next = curr->next;
			curr->next = node;
		}
		curr = curr->next;
		i++;
	}
}

void	lst_delete(t_list **head, size_t index)
{
	t_list	*curr;
	t_list	*prev;
	size_t	i;

	if (!head || !*head)
		return ;
	i = 0;
	prev = *head;
	curr = *head;
	while (curr)
	{
		if (i == index)
		{
			prev->next = curr->next;
			if (index == 0)
				*head = curr->next;
			free(curr);
			return ;
		}
		curr = next->next;
		if (i > 0)
			prev = prev->next;
		i++;
	}
}

static t_list	*cut_node(t_list *node);
t_list      *lst_pop(t_list **head, size_t index)
{
	size_t	i;
	t_list	*curr;
	t_list	*prev;

	i = 0;
	if (!head || !*head)
		return (NULL);
	curr = *head;
	prev = *head;
	while (i <= index && curr)
	{
		if (i == index)
		{
			if (index == 0)
				*head = (*head)->next;
			else
				prev->next = curr->next;
			return (cut_node(curr));
		}
		curr = curr->next;
		if (i > 0)
			prev = prev->next;
	}
	return (pop);
}

static t_list	*cut_node(t_list *node)
{
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}

t_list	*lst_slice(t_list **head, size_t start, size_t size)
{
	t_list	*curr;
	t_list	*next;
	t_list	*sub_list;

	if (!head || !*head)
		return (NULL);
	curr = *head;
	sub_list = get_node(*head, start)
	if (!sub_list)
		return (NULL);
	while (curr && curr->next != sub_list)
		curr = curr->next;
	curr = cut_node(curr);
	next = get_node(sub_list, size);
	if (next)
	{
		if (start == 0)
			(*head)->next = next->next;
		curr->next = next->next;
	}
	next = cut_node(next);
	return (sub_list);
}
