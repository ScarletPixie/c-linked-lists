# C-LINKED-LISTS
This repository contains useful linked list functions.
<br><br><br><br>

# Overview

# Initialization ([new\_struct.c](new_struct.c))
## t\_list \*new\_node(void \*data, void (\*failsafe)(void *data))
Receives the new node's data and a failsafe function which shall be used on the data if the memory allocation for the new node fails. If no failsafe function is provided the function just returns NULL on failure and does nothing to the data provided.
Returns the new initialized node on success and NULL on failure.
```c
t_list *my_node = new_node((void *)"something", NULL);
t_list *my_node = new_node((void *)strdup("something"), free);
```

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

## t_list	\*get_node(t_list \*head, size_t index)
Returns the node at index position from the list (next field is not modified and still points to it's original address).

 <br>

## t_list	\*last_node(t_list \*head)
Returns the last node of the list.

<br>

## void	lst_insert(t_list \*\*head, t_list \*node, size_t index)
Receives the address of the pointer to the start of the list, the node to be inserted in the list and the index in which said node will be inserted. The function will return without doing anything in the following cases: node is null, head argument or \*head is null or if *head points to the same address as node. If the list is null or if the index is 0 *head will point to the new node, if the index is beyond the length of the list, node will be added to the end of the list.

<br>

## void	lst_delete(t_list \*\*head, size_t index)
Receives the address of the pointer to the start of the list and the index to delete the node at position index. The function will not do anything if head or *head is null, if the index is beyond the length of the list no nodes will be deleted (it will still iterate through the list).

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

## t_list	\*lst_slice(t_list \*\*head, size_t start, size_t size)
This function cuts list by size size starting from the start index. It won't do anything if head or *head is NULL or if the start index is beyond the len the of list.