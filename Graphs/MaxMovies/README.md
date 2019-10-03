# Movie Festival

## Problem statement:

You are going to a movie festival. Determine the maximum amount of movies you could watch(and their order).

## Data representation:

We are going to use a graph for representation. Each movie will be a node in the graph, and the graph will be organized based on the time interval each movie is
occupying. More specifically, if the node for movie A has an edge towards the node for movie B, then it can be deduced that movie A starts **(and finishes!)** before movie B
starts. It is obvious that this implies that the graph is a **DAG**(directed acyclic graph), due to the fact that we cannot go back in time.
Having the topological sort list, the maximum number of movies one could watch can be computed using an additional table dp for which we have the following recurrence relation:

dp[i] =

*dp[j] + 1, where j is from {0, ... i - 1} and there exists an edge between j and i and dp[j] + 1 > dp[i]

*dp[i] otherwise

Or in other words, **dp[i] = max(dp[i], dp[j + 1])**, which gets executed for every j from {0, ..., i - 1} if (j, i) is an edge.

![Untitled](https://user-images.githubusercontent.com/51800513/66147914-76e78a00-e618-11e9-9d43-9b8125758015.png)


This algorithm is similar to the O(n^2) dynamic programming way of solving the longest increasing subsequence problem.

## Input

On the first line we will have the number of movies, and on the following lines, triples of **(movie_name, start, end)**, where for simplicity, start and end are integers.
This does not restrain generality, the integer could be hour * 60 + minute.

![Untitled](https://user-images.githubusercontent.com/51800513/66148366-65eb4880-e619-11e9-8f2b-a3451fa5a9b6.png)