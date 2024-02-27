# C-LINKED-LISTS
This repository contains useful linked list functions. Both for singly linked lists and doubly linked lists.
<br><br><br><br>

# Overview

All the functions for singly linked lists also have a doubly linked list version, the only extra function for doubly linked lists is "link_node2".

<br>

# Initialization ([new\_struct.c](new_struct.c))
## t\_list \*new\_node(void \*data, void (\*failsafe)(void *data))
Receives the new node's data and a failsafe function which shall be used on the data if the memory allocation for the new node fails. If no failsafe function is provided the function just returns NULL on failure and does nothing to the data provided.
Returns the new initialized node on success and NULL on failure.
```c
t_list *my_node = new_node((void *)"something", NULL);
t_list *my_node = new_node((void *)strdup("something"), free);
```
<br>

## t\_list2 \*new\_node2(void \*data, void (\*failsafe)(void *data))
Receives the new node's data and a failsafe function which shall be used on the data if the memory allocation for the new node fails. If no failsafe function is provided the function just returns NULL on failure and does nothing to the data provided.
Returns the new pinitialized node on success and NULL on failure.
```c
t_list2 *my_node = new_node2((void *)"something", NULL);
t_list2 *my_node = new_node2((void *)strdup("something"), free);
```
<br><br><br><br>

# Free memory ([free\_struct.c](free_struct.c))
## void clear\_list(t\_list \*\*head, void (\*func)(void *data))
Receives the address of the pointer to the start of the list and a function to be used on every node's data, for example: free. If no free function is provided then no function will be applied to each node's data and only the nodes will be freed. The start of the list pointer will be set to NULL.
```c
t_list *my_list = make_list();

clear_list(&my_list, NULL);
clear_list(&my_list, free);
clear_list(&my_list, my_custom_free_function);
```
<br>

## void clear\_list2(t\_list2 \*\*head, void (*func)(void *data))
Receives the address of the pointer to the start of the list and a function to be used on every node's data, for example: free. If no free function is provided then no function will be applied to each node's data and only the nodes will be freed. The start of the list pointer will be set to NULL.
```c
t_list2 *my_list = make_list();

clear_list2(&my_list, NULL);
clear_list2(&my_list, free);
clear_list2(&my_list, my_custom_free_function);
```
<br><br><br><br>

# Singly Linked Lists Functions

## void	lst_insert(t_list \*\*head, t_list \*node, size_t index)
Receives the address of the pointer to the start of the list, the node to be inserted in the list and the index in which said node will be inserted. The function will return without doing anything in the following cases: node is null, head argument or \*head is null, node's next field is not NULL,or if *head points to the same address as node. If the list is null or if the index is 0 *head will point to the new node, if the index is beyond the length of the list, node will be added to the end of the list.

<br>

## void	lst_append(t_list \*\*head, t_list \*node)
Adds a node to the end of the list, does nothing in the following situations: node is NULL, head or *head is NULL or *head is equal to node.

<br>

## void	lst_extend(t_list \*\*head, size_t index, t_list \*list)
This function extends a list by adding another list at the index passed as argument. It receives the address of the pointer to the start of the list, the index at which the new list will be inserted and the new list to be inserted. Does nothing if the list is equal to head or list or head is NULL. If the index passed is beyond the length of the list, the new list will be appended to the end of the existing list.

<br>

## t_list	\*array_to_list(const void \*arr, size_t size, size_t data_size)
This functions takes a void array, its size and the size of the data containing in each index of the array and creates a linked list from it, the function will return NULL if any of the parameters is 0/NULL. The data is duplicated so you'll need to free both the array and the list. 

<br>

## void	\*list_to_array(t_list \*head, size_t data_size)
This function takes a linked list and the data size and creates an array from it containing the data field of each node, if any of the parameters is 0/NULL the function will return NULL. The data is duplicated so you'll need to free bothe the array and the list.

<br>

## void	\*ft_memdup(const void \*data, size_t data_size)
Takes a void pointer and the size of the memory area the the pointer points to and returns a copy data_size bytes of that memory area. If data or data_size is 0/NULL the function will return NULL.
```c
int	i = 10;
int *ip = ft_memdup(&i, sizeof(int));
free(ip);
```
<br> 

## void	ft_memcpy(void \*dest, const void \*source, size_t data_size)
Takes a pointer to a memory area that will be overwritten by data_size bytes of source pointer. If any parameter is 0/NULL the function doesn't do anything. Make sure dest has the capacity to comport data_size bytes.
```c
int i = 10;
int j;

ft_memcpy(&j, &i, sizeof(int));
```
<br>

## t_list	\*get_node(t_list \*head, size_t index)
Returns the node at index position or NULL if head is NULL or if index is beyond the length of the list. The fields are not modified so the node still points to the next node.

<br>

## t_list	\*last_node(t_list \*head)
Returns the last node of the list of NULL if the list is NULL;

<br>

## void	ft_swap(void \*\*ptr1, void \*\*ptr2)
Takes the address of a pointer and swaps the contents of ptr1 and ptr2. Does nothing if any of the the arguments is NULL.

<br>

## void	lst_delete(t_list \*\*head, size_t index, void (\*func)(void \*data))
Receives the address of the pointer to the start of the list, the index to delete the node at position index and an optional function to apply to each node's data. The function will not do anything if head or *head is null, if the index is beyond tmake_list(0, 0)field to NULL and returns it. Returns NULL if node is NULL.

<br>

## void	lst_sort(t_list \*head, int (\*cmp)(void \*data1, void \*data2))
Sorts the list using insertion sort, it takes the pointer to the list and a function pointer to be used between 2 node's data field, it has to return an integer, the nodes themselves are not moved around it's just their datas that gets swapped. Does nothing if cmp or head is NULL.
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
Reverses a list, this function swaps the data pointer of the first node with the last until the list is reversed.

<br>

## t_list	*lst_pop(t_list \*\*head, size_t index)
Receives the address of the pointer to the start of the list and the index at which the node will be popped from the list. This function will remove and return a clean node from the list at the index position. The function won't do anything if head of *head is NULL. if the index is beyond the length of the list no nodes will be deleted (it will still iterate through the list).
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
This function cuts list by size size starting from the start index. It won't do anything if head or *head is NULL or if the start index is beyond the len the of list or if size is 0. It then returns the cut part of the list.

<br>

## void	link_node2(t_list2 \*node1, t_list2 \*node2)
This function links node1's next field to node2 and node2's prev field to node1, if all arguments are NULL then nothing is done, if one of them is NULL only one operation will be done, for example if node1 is NULL then node2's prev is set to NULL and vice versa.
