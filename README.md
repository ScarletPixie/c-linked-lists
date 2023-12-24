# c-linked-lists
This repository contains useful linked lists prototypes and functions.
<br><br><br><br>
# Initialization
## t_list *new_node()
Returns a pointer to an initialized t_list struct. Returns NULL on failure.
## t_dblist *new_node2()
Returns a pointer to an initialized t_dblist struct. Returns NULL on failure.
## t_stack *init_stack()
Returns a pointer to an initialized t_stack struct. Returns NULL on failure.
## t_stack2	*init_stack2()
Returns a pointer to an initialized t_stack2 struct. Returns NULL on failure.
<br><br><br><br>
# Free memory:
## t_list clear_list(t_list *head)
Receives a t_list pointer to the start of the list and clears all nodes present in the list, returns NULL.

## t_dblist clear_list2(t_dblist *head)
The same as clear list but for doubly linked lists (t_dblist).

## t_stack clear_stack(t_stack *stack)
Receives a t_stack pointer to a stack, calls clear list to empty the list it contains and set its size to 0.

## t_stack2 clear_stack2(t_stack2 *stack)
The same as clear_stack but for stacks that contain doubly linked lists (t_stack2)

