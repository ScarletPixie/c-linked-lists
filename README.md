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
<br>
