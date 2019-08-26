The ADT Matrix is a container that represents a two-dimensional array.
Each element has a unique position determined by two indexes: line and column.

In this example, the matrix contains more values of 0/NULL, thus it is a sparse matrix.
For efficiency, we store the non-zero/NULL elements as (line, column, value) triples,
ordered lexicographically in a dynamic array, which enables us to binary search (line, column) pairs.