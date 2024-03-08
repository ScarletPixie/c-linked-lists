#include "linked_lists.h"

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
	if (!head || !*head || !from)
		return ;

}
