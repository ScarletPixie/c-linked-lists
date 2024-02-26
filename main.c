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
	t_list	*list = NULL;
	t_list	*node = NULL;
	int 	num = 5;
	int		i = 0;
	int		random = 89;

	while (num-- > 0)
	{
		node = new_node(ft_memdup(&num, sizeof(int)), free);
		if (!node)
			return (clear_list(&list, free), 1);

		lst_insert(&list, node, 0);
		i++;
	}
	printf("BEFORE\n");
	print_list(list);

	node = new_node(ft_memdup(&random, sizeof(int)), free);

	lst_insert(&list, node, 6);

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
	printf("\n");
}
