#include "linked_lists.h"
#include <string.h>
#include <stdio.h>

int cmp(void *d1, void *d2)
{
	int *a = (int *)d1;
	int *b = (int *)d2;

	return (*a - *b);
}

static void	print_list(t_list *list);
int	main(void)
{
	t_list	*list;
	t_list	*node;
	int 	num = 1;
	int		i = 0;

	while (num-- > 0)
	{
		node = new_node();
		if (!node)
			return (clear_list(&list, free), 1);
		node->data = ft_memdup(&num, sizeof(int));
		//lst_append(&list, node);
		lst_insert(&list, node, 0);
		i++;
	}
	printf("BEFORE\n");
	print_list(list);
	printf("\n");
	lst_delete(&list, 0);
	printf("AFTER\n");
	print_list(list);
	clear_list(&list, free);
}

static void	print_list(t_list *list)
{
	if (!list)
		printf("list is null\n");
	while (list)
	{
		if (list->data)
			printf("%d\n", *((int *)list->data));
		else
			printf("NULL\n");
		list = list->next;
	}
}
