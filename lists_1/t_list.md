# Overview
## structure
```h
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;
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

<br>

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
t_list	*node0 = lst_pop(&head, 0);
t_list	*node10 = lst_pop(&head, 10);
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

<br>

# Helper Functions
## t_list	\*get_node(t_list \*head, size_t index)
Takes as argument the pointer to the start of the list and returns the index-th node. If index is out of bounds, NULL is returned.

## t_list	\*last_node(t_list \*head)
Takes as argument the pointer to the start of the list and returns it's first node.

## t_list	\*cut_node(t_list \*node)
Takes as argument a pointer to a node and set its next field to NULL, will not do anything if node is NULL.

## void	link_node(t_list \*node1, t_list \*node2)
Takes as arguments two pointer to ndoes