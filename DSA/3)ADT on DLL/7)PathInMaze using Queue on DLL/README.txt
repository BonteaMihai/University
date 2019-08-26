Path in a Maze:

A maze is a grid of empty and occupied positions.
We have a starting position somewhere inside the maze.

-Test whether there is a path which leads to the margin(an exit from the maze).
-Find the shortest path out of the maze(if one exists).

* = empty space
X = occupied 
R = starting position

For the pathfinding, Lee(fill) algorithm was used on the maze. For this algorithm, a
fully templated Queue represented on a doubly linked list(DLL) was used.