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
	int 	num = 10;
	int		i = 0;

	while (num-- > 0)
	{
		node = new_node();
		if (!node)
			clear_list(&list, 1);
		node->data = ft_memdup(&num, sizeof(int));
		//lst_append(&list, node);
		lst_insert(&list, node, 0);
		i++;
	}
	print_list(list);
	printf("\n");
//	printf("len: %zu\n", lst_len(list));
	t_list	*piece = lst_slice(&list, 0, 3);
	print_list(piece);
	printf("\n");
	print_list(list);
	clear_list(&list, 1);
}

static void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", *((int *)list->data));
		list = list->next;
	}
}
