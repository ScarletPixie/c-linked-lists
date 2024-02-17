# C-LINKED-LISTS
This repository contains useful linked list functions.
<br><br><br><br>

# Overview

# Initialization ([new\_struct.c](new_struct.c))
## t\_list \*new\_node()
Returns a pointer to an initialized t\_list struct. Returns NULL on failure.
## t\_dblist \*new\_node2()
Returns a pointer to an initialized t\_dblist struct. Returns NULL on failure.
<br><br><br><br>

# Free memory ([free\_struct.c](free_struct.c))
## t\_list clear\_list(t\_list \*head)
Receives a t\_list pointer to the start of the list and clears all nodes present in the list, returns NULL.

## t\_dblist clear\_list2(t\_dblist \*head)
