# C-LINKED-LISTS
This repository contains useful linked list functions.
<br><br><br><br>

# Overview

# Initialization ([new\_struct.c](new_struct.c))
## t\_list \*new\_node()
Returns a pointer to an initialized t\_list struct. Returns NULL on failure.
## t\_list2 \*new\_node2()
Returns a pointer to an initialized t\_list2 struct. Returns NULL on failure.
<br><br><br><br>

# Free memory ([free\_struct.c](free_struct.c))
## void clear\_list(t\_list \*\*head, void (\*f)(void *data))
Receives the address of the pointer to the start of the list and a function to be used in every node's data, for example: free. If no free function is provided then no function will be applied to each node's data and only the nodes will be freed. The start of the list pointer will be set to NULL.
```c
t_list *my_list = make_list();

clear_list(&my_list, NULL);
clear_list(&my_list, free);
clear_list(&my_list, my_custom_free_function);
```
<br>

## void clear\_list2(t\_list2 \*\*head, void (*f)(void *data))
Receives the address of the pointer to the start of the list and a function to be used in every node's data, for example: free. If no free function is provided then no function will be applied to each node's data and only the nodes will be freed. The start of the list pointer will be set to NULL.
```c
t_list2 *my_list = make_list();

clear_list2(&my_list, NULL);
clear_list2(&my_list, free);
clear_list2(&my_list, my_custom_free_function);
```
<br>
