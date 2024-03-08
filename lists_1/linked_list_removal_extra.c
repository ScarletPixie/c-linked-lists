#include "linked_lists.h"

static void	remove(t_list *node, void (*del)(void *dt));

void	lst_remove_if(t_list **head, int (*cmp)(void *dt), void (*del)(void *dt))
{
	t_list	*prev
	t_list	*tmp;
	t_list	*safe;

	if (!head || !*head || !func)
		return ;
	tmp = *head;
	prev = *head;
	while (tmp)
	{
		safe = tmp->next;
		if (prev->next == tmp)
			prev = prev->next;
		if (cmp(tmp->data))
		{
			if (tmp = *head)
				*head = safe;
			del(tmp->data);
			free(tmp);
			link_node(prev, safe);
			tmp = prev;
		}
		else
			tmp = tmp->next;
	}
}

void	lst_del_from(t_list **head, t_list *from, t_list *to, void (*f)(void *dt))
{
	t_list	*safe;
	t_list	*prev;
	t_list	*tmp;

	if (!head || !*head || !from || !f)
		return ;
	tmp = *head;
	prev = *head;
	safe = (*head)->next;
	while (tmp && tmp != from)
	{
		if (prev->next == tmp)
			tmp = tmp->next;
		tmp = tmp->next;
	}
	while (tmp && tmp != to)
	{
		safe = tmp->next;
		if (*head == tmp)
			*head = safe;
		f(tmp->data);
		free(tmp);
		tmp = safe;
	}
	prev->next = safe;
}
