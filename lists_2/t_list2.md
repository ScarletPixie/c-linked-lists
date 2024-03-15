# Overview
## structure
```h
typedef struct s_list2
{
	void		*data;
	struct s_list2	*next;
	struct s_list2	*prev;
}			t_list2;
```

<br>

# Adding Nodes ([linked_list_addition2.c](linked_list_addition.c))
## void	lst_insert2(t_list2 \*\*head, t_list2 \*node, size_t index);
Inserts a node at the index provided.
Takes a double pointer to the start of a list, a node to be added and the index at which this node will be added. This function will not do anything if:
node or head argument is NULL, if the node's next field is NOT NULL or if node pointer is the same as the start of the list.
If the the list is empty, then *head will be set to node. If the index is out of bounds then the new node will be added to the end of the list

<br>

## void	lst_insert_next2(t_list2 \*\*head, t_list2 \*new_node, t_list2 \*node)
Inserts new_node next to the node provided.
Takes a double pointer to the start of a list, the new node to be added and the node at which the new node will be appended to. This function will not do anything if:
head or new_node is NULL, new_node's next field is not NULL, list is empty but node is not NULL or if new_node is the first node in the list pointed by head. The new node is put after the node specified by the node argument. It's not possible to insert the new node at the beginning.

## void	lst_append2(t_list2 \*\*head, t_list2 \*node)
Inserts a node at the end of the list.
Takes a double pointer to the start of a list and the new node or list to be added at the end. This function will not do anything if:
node or head argument is null or if node points to the same address as the start of the list.
If the list is empty *head will be set to node.

<br>

## void	lst_prepend2(t_list2 \*\*head, t_list2 \*node)
Inserts a node at the beginning of the list and updates the list pointer.
Takes a double pointer to the start of a list and the new node or list to be added at the beginning of the list. This function will not do anything if:
node or head argument is null or if node points to the same list as head.
This function will search for the last node in node argument and connect it to the list then head will be updated to point to the new start of the list. If the list is empty *head will be set to node.

<br>

## void	lst_extend2(t_list2 \*\*head, t_list2 \*list, size_t index)
Adds a node/list at the index provided.
Takes a double pointer to the start of a list, the new list to be added and the index at which the list will be added. This function will not do anything if:
head or list argument is NULL or if list points to the same list as head.
If the list is head list is empty or index is 0 *head will be set to list after proper connections. If the index is out of bounds then the list will be appended to the list pointed by *head. Beware of double free.

<br><br><br>

# Removing Nodes ([linked_list_removal2.c](linked_list_removal.c))
## void	lst_del_at2(t_list2 \*\*head, size_t index, void (\*func)(void \*data))
Deletes a node at the specified index.
Takes a double pointer to the start of a list, the index at which the node will be deleted and a function to be applied to the node's data field. This function will not do anything if:
head argument is NULL or the list is empty.
if no function is provided then only the node will be freed, if index is 0 *head will be set to the next node.
```c
lst_delete2(&list, free);
lst_delete2(&list, custom_free);
lst_delete2(&list, NULL);
```

<br>

## t_list2	\*lst_pop2(t_list2 \*\*head, size_t index)
Remove and return a node specified at index.
Takes a double pointer to the start of a list and the index at which the node will be removed. This function will have no effect if:
head is NULL or list is empty. This function works similar to lst_delete but instead of deleting the node it will just be removed from the list and returned, the node's next and prev fields will be set to NULL and proper linking will be made. If the index is out of bounds or the arguments are invalid then the function will return NULL otherwise it will return the node at index with its next field set to NULL.
```c
t_list2	*list = NULL;
t_list2	*other_list = NULL;
int i = 10;
while (--i) // creates a list of size 10;
	lst_insert2(&list, new_node2(ft_memdup(&i, sizeof(int)), free), 0);
int i = 5;
while (--i) // will remove the first 5 nodes from list and insert into other_list
	lst_insert2(&other_list, lst_pop2(&list, 0), 0);
lst_clear2(&list, free);
lst_clear2(&other_list, free);
```

<br>

## t_list2	\*lst_slice2(t_list2 \*\*head, size_t start, size_t size)
Removes size - start nodes and return.
Takes a double pointer to the start of a list, the start index at which the list will be cut and how many nodes will be cut from start index. This function will have no effect if:
head is NULL, list is empty or start index is out of bounds.
This function works similarly to lst_pop but instead of poping one node this function "pops" (size - start) nodes. It will return a new list or NULL on failure
```c
t_list2	*sub_list = lst_slice2(&list, 0, 5);
lst_clear2(&list, free);
lst_clear2(&sub_list, free);
```

<br>

## void	del_node2(t_list2 \*node, void (\*del)(void \*data))
Deletes a node and apply del function to the node's data, if node is NULL nothing is done, if del is NULL then it will simply free the node.

<br>

## t_list	\*lst_destroy2(t_list2 \*head, void (\*del)(void \*data))
Uses del_node to destroy the whole list, if head is NULL nothing is done.

<br>

<br><br><br>

# Extra Removal Functions ([linked_list_removal_extra2.c](linked_list_removal_extra2.c))
## void	lst_del_if2(t_list2 \*\*head, int (\*cmp)(void \*dt), void (\*del)(void \*dt))
Deletes all nodes in which cmp returns true.
Takes a double pointer to the start of a list, a function that will be used to determine which nodes to delete and a delete function to be applied to the nodes' data. This function will not do anything if:
head is NULL, list is empty or if cmp is NULL.

<br>

## void	lst_del_from2(t_list2 \*\*head, t_list2 \*from, t_list2 \*to, void (\*f)(void \*dt))
Deletes all nodes ranging from the node 'from' to the node 'to' (non inclusive).
Takes a double pointer to the start of a list, the node at which the deleting will start, the node at which the deletion will stop (non inclusive) and a delete function to be applied to the nodes' data. This function will not do anything if:
head is empty, list is empty of from is NULL.

<br>

## void	lst_del_node2(t_list2 \*\*head, t_list2 \*node, void (\*del)(void \*data))
Deletes the node specified in node arguemnt.
Takes a double pointer to the start of a list, the node in the list that will be deleted and the function to be applied to the node's data. This function will not do anything if:
head or node is NULL, or if the list is already empty.

<br><br><br>

# Helper Functions ([linked_list_nodes2.c](linked_list_nodes.c))
## t_list2	\*get_node2(t_list2 \*head, size_t index)
Takes as argument the pointer to the start of the list and returns the index-th node. If index is out of bounds, NULL is returned.

## t_list2	\*last_node2(t_list2 \*head)
Takes as argument the pointer to the start of the list and returns it's first node.

## t_list2	\*cut_node2(t_list2 \*node)
Takes as argument a pointer to a node and set its next an prev fields to NULL, will not do anything if node is NULL.

## void	link_node2(t_list2 \*node1, t_list2 \*node2)
Takes as arguments two node pointers and set node1's next field to node2, will not do anything if node1 is NULL or if node1 is equal to node2.

<br><br><br>

# Other functions ([linked_list_misc2.c](linked_list_misc.c))
## size_t	lst_len2(const t_list2 \*head)
Takes as argument a pointer to the start of the list and returns how many nodes are in the list, if the list is empty it wlll return 0.

<br>

## t_list2	\*get_node_if2(t_list2 \*head, int (\*func)(void \*data))
Get the first node in which the function func returns true.
Takes as argument a pointer to the start of the list and a function to be applied to each node's data. This function will not do anything if list is empty or if func is NULL.
If the function func returns a non zero value then the node will be returned similar to get_node. if it reaches the end of the list then NULL is returned.

<br>

## void	lst_sort2(t_list2 \*head, int (\*cmp)(void \*data1, void \*data2))
Sorts the list with selection sort.
Takes as argument a pointer to the start of the list and a function that will compare 2 nodes' datas. If the list is empty of cmp is NULL then nothing will be done otherwise the list will be sorted (insertion sort) in ascending order.
```c
int cmp(void *d1, void *d2)
{
	int *a = (int *)d1;
	int *b = (int *)d2;

	return (*a - *b);
}
lst_sort2(unsorted_list, cmp);
```

<br>

## void	lst_rev2(t_list2 \*head)
Takes as argument a pointer to the start of the list, if list is empty nothing will be done, it inverts a list by swapping the nodes' data field.

## void	lst_print2(t_list2 \*head, void (\*print_data)(void \*dt))
Takes a pointer to the start of the list and a function that will be applied to each node's data.

<br><br><br>

# List Creation ([linked_list_creation2.c](linked_list_creation2.c))
## t_list2	\*new_node2(void \*data, void (\*failsafe)(void \*data))
Creates a new node and assign the new node's data to data argument, if the memory allocation for the new node fails then the failsafe is called on the data provided.

## t_list2	\*new_list2(size_t size, void \*(\*gen)(void), void (\*gen_failsafe)(void \*dt))
Creates a list of size size, each node's data is assigned to the return of the function gen, if no gen function is provided then NULL is assingned to each node's data.

## void	lst_foreach2(t_list2 \*head, void (\*func)(t_list2 \*node))
Applies function func to each node in the list. Won't do anything if list or func is NULL.

<br><br><br>
