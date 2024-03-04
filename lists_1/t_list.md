# Overview
## structure
```h
typedef struct s_list
{
	void		*data;
	struct s_list	*next;
}			t_list;
```

<br>

# Adding Nodes ([linked_list_addition.c](linked_list_addition.c))
## void	lst_insert(t_list \*\*head, t_list \*node, size_t index);
Takes as argument the address of a pointer to the start of the list, a node to be added and the index at which this node will be added. This function will not do anything if:
node or head argument is NULL, if the node's next field is NOT NULL or if node pointer is the same as the start of the list.
If the the list is empty, then *head will be set to node. If the index is out of bounds then the new node will be added to the end of the list

<br>

## void	lst_append(t_list \*\*head, t_list \*node)
Takes as argument the address of a pointer to the start of the list and the new node or list to be added at the end. This function will not do anything if:
node or head argument is null or if node points to the same address as the start of the list.
If the list is empty *head will be set to node.

<br>

## void	lst_prepend(t_list \*\*head, t_list \*node)
Takes as argument the address of a pointer to the start of the list and the new node or list to be added at the beginning of the list. This function will not do anything if:
node or head argument is null or if node points to the same list as head.
This function will search for the last node in node argument and connect it to the list then head will be updated to point to the new start of the list. If the list is empty *head will be set to node.

<br>

## void	lst_extend(t_list \*\*head, t_list \*list, size_t index)
Takes as argument the address of a pointer to the start of the list, the new list to be added and the index at which the list will be added. This function will not do anything if:
head or list argument is NULL or if list points to the same list as head.
If the list is head list is empty or index is 0 *head will be set to list after proper connections. If the index is out of bounds then the list will be appended to the list pointed by *head. Beware of double free.

<br><br><br>

# Removing Nodes ([linked_list_removal.c](linked_list_removal.c))
## void	lst_delete(t_list \*\*head, size_t index, void (\*func)(void \*data))
Takes as argument the address of a pointer to the start of the list, the index at which the node will be deleted and a function to be applied to the node's data field. This function will not do anything if:
head argument is NULL or the list is empty.
if no function is provided then only the node will be freed, if index is 0 *head will be set to the next node.
```c
lst_delete(&list, free);
lst_delete(&list, custom_free);
lst_delete(&list, NULL);
```

<br>

## t_list	\*lst_pop(t_list \*\*head, size_t index)
Takes as argument the address of a pointer to the start of the list and the index at which the node will be removed. This function will have no effect if:
head is NULL or list is empty. This function works similar to lst_delete but instead of deleting the node it will just be removed from the list and returned, the node's next field will be set to NULL and proper linking will be made. If the index is out of bounds or the arguments are invalid then the function will return NULL otherwise it will return the node at index with its next field set to NULL.
```c
t_list	*list = NULL;
t_list	*other_list = NULL;
int i = 10;
while (--i) // creates a list of size 10;
	lst_insert(&list, new_node(ft_memdup(&i, sizeof(int)), free), 0);
int i = 5;
while (--i) // will remove the first 5 nodes from list and insert into other_list
	lst_insert(&other_list, lst_pop(&list, 0), 0);
clear_list(&list, free);
clear_list(&other_list, free);
```

<br>

## t_list	\*lst_slice(t_list \*\*head, size_t start, size_t size)
Takes as argument the address of a pointer to the start of the list, the start index at which the list will be cut and how many nodes will be cut from start index. This function will have no effect if:
head is NULL, list is empty or start index is out of bounds.
This function works similarly to lst_pop but instead of poping one node this function "pops" (size - start) nodes. It will return a new list or NULL on failure
```c
t_list	*sub_list = lst_slice(&list, 0, 5);
lst_clear(&list, free);
lst_clear(&sub_list, free);
```

<br><br><br>

# Helper Functions ([linked_list_nodes.c](linked_list_nodes.c))
## t_list	\*get_node(t_list \*head, size_t index)
Takes as argument the pointer to the start of the list and returns the index-th node. If index is out of bounds, NULL is returned.

## t_list	\*last_node(t_list \*head)
Takes as argument the pointer to the start of the list and returns it's first node.

## t_list	\*cut_node(t_list \*node)
Takes as argument a pointer to a node and set its next field to NULL, will not do anything if node is NULL.

## void	link_node(t_list \*node1, t_list \*node2)
Takes as arguments two node pointers and set node1's next field to node2, will not do anything if node1 is NULL or if node1 is equal to node2.

<br><br><br>

# Other functions ([linked_list_misc.c](linked_list_misc.c))
## size_t	lst_len(const t_list \*head)
Takes as argument a pointer to the start of the list and returns how many nodes are in the list, if the list is empty it wlll return 0.

<br>

## t_list	\*get_node_if(t_list \*head, int (\*func)(void \*data))
Takes as argument a pointer to the start of the list and a function to be applied to each node's data. This function will not do anything if list is empty or if func is NULL.
If the function func returns a non zero value then the node will be returned similar to get_node. if it reaches the end of the list then NULL is returned.

<br>

## void	lst_sort(t_list \*head, int (\*cmp)(void \*data1, void \*data2))
Takes as argument a pointer to the start of the list and a function that will compare 2 nodes' datas. If the list is empty of cmp is NULL then nothing will be done otherwise the list will be sorted (insertion sort) in ascending order.
```c
int cmp(void *d1, void *d2)
{
	int *a = (int *)d1;
	int *b = (int *)d2;

	return (*a - *b);
}
lst_sort(unsorted_list, cmp);
```

<br>

## void	lst_rev(t_list \*head)
Takes as argument a pointer to the start of the list, if list is empty nothing will be done, it inverts a list by swapping the nodes' data field.

<br><br><br>

# List Conversions ([linked_list_creation.c](linked_list_creation.c))
Warning, the following functions still need to be tested.

## t_list	\*lst_from_arr(cosnt void \*arr, size_t size, size_t data_size)
Takes as argument a void array, the array size and the size of each data in the array, if any argument is equal to 0//NULL, NULL is returned. Each node's data field will recieve a copy of their respective array element. On success the new list is returned, on failure NULL is returned.
```c
int arr = {1, 2, 3, 4};
t_list	*list = lst_from_arr(arr, 4, sizeof(int));
lst_clear(&list);
```

<br>

## t_list	\*arr_to_lst(void \*arr, size_t size, size_t data_size)
The same as lst_from_arr, but array is freed.

<br>

## void	\*arr_from_lst(const t_list \*head, size_t data_size)
Takes as argument a pointer to the start of a list and the data size of the node's data field. This function will not do anything if the list is empty or data_size is 0. On success a void array is returned, each index containing a node's data value, on failure NULL is returned.
```c
void	*arr = arr_from_list(list, sizeof(int));
free(arr);
```

<br><br><br>