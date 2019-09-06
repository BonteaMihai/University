A Fenwick tree or binary indexed tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.
It achieves a balance between updating an element and prefix calculation, both of those operations being done in O(log n).
It is seen as a tree where the value of each node is the sum of the numbers in that subtree. However, it is represented on a regular array, just
like a heap/segment tree.

