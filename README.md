# C-LINKED-LISTS
This repository contains useful linked lists prototypes and functions.
<br><br><br><br>

# Overview

# Initialization ([new\_struct.c](new_struct.c))
## t\_list \*new\_node()
Returns a pointer to an initialized t\_list struct. Returns NULL on failure.
## t\_dblist \*new\_node2()
Returns a pointer to an initialized t\_dblist struct. Returns NULL on failure.
## t\_stack \*init\_stack()
Returns a pointer to an initialized t\_stack struct. Returns NULL on failure.
## t\_stack2	\*init\_stack2()
Returns a pointer to an initialized t\_stack2 struct. Returns NULL on failure.
<br><br><br><br>

# Free memory ([free\_struct.c](free_struct.c))
## t\_list clear\_list(t\_list \*head)
Receives a t\_list pointer to the start of the list and clears all nodes present in the list, returns NULL.

## t\_dblist clear\_list2(t\_dblist \*head)
The same as clear list but for doubly linked lists (t\_dblist).

## t\_stack clear\_stack(t\_stack \*stack)
Receives a t\_stack pointer to a stack, calls clear list to empty the list it contains and set its size to 0.

## t\_stack2 clear\_stack2(t\_stack2 \*stack)
The same as clear\_stack but for stacks that contain doubly linked lists (t\_stack2)

