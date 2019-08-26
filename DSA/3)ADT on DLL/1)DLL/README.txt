A linked list is a data structure where the order of the elements is determined by pointers to the next elements, 
as the list does not occupy a contiguous memory block. This makes insertions and deletions faster, but nodes
(besides the first and the last) cannot be accessed in O(1) (pointer arithmetic is impossible to do on linked lists). It takes
an average of O(n) to access the node at a certain position.
The first node of the list is called head and the last node is called tail.
In a doubly linked list(DLL) each node contains data and the address of the next node and previous node.