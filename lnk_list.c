#include "linked_lists.h"

void	lst_insert(t_list **head, t_list *node, size_t index)
{
	t_list	*curr;
	size_t	i;

	i = 0;
	if (!node)
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
	t_list	*next;
	size_t	i;

	i = 0;
	curr = *head;
	if (*head && index == 0)
	{
		*head = curr->next;
		free(curr);
		return ;
	}
	while (curr && curr->next)
	{
		next = (curr->next)->next;
		if ((i + 1) == index)
		{
			free(curr->next);
			curr->next = next;
			return ;
		}
		curr = curr->next;
		i++;
	}
}

static t_list	*cut_node(t_list *node);
t_list      *lst_pop(t_list **head, size_t index)
{
	t_list	*curr;
	t_list	*next;
	t_list	*pop;
	size_t	i;

	curr = *head;
	pop = NULL;
	if (*head && index == 0)
	{
		pop = cut_node(*head);
		*head = (*head)->next;
	}
	i = 0;
	while (i < index && curr && curr->next)
	{
		next = (curr->next)->next;
		if ((i + 1) == index)
		{
			pop = cut_node(curr->next);
			curr->next = next;
		}
		i++;
		curr = curr->next;
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

t_list	*lst_slice(t_list **head, size_t start, size_t end)
{
	t_list	*curr;
	t_list	*next;
	t_list	*sub_list;

	if (!head || !*head)
		return (NULL);
	curr = *head;
	sub_list = get_node(*head, start);
	curr->next = NULL;
	if (!sub_list)
		return (NULL);
	next = get_node(sub_list, end);
	if (start == 0)
		*head = curr->next
	next->next = NULL;
	return (sub_list);
}
