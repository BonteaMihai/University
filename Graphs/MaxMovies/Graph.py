from myException import myException

import copy

class Graph(object):
    def __init__(self, vertices):
        self.__in = {}
        self.__out = {}
        for i in range(vertices):
            self.__out[i] = []
            self.__in[i] = []
        self.__vertices = vertices

    def Keys(self):
        """
            Description: returns a copy of all the vertex keys
        """
        return list(self.__out.keys())

    def neighboursOfXOut(self, x):
        """
            Description: returns a copy of all out neighbours of x
        """
        try:
            return list(self.__out[x])
        except KeyError:
            raise Exception("No such vertex")

    def neighboursOfXIn(self, x):
        """
            Description: returns a copy of all in neighbours of x
        """
        try:
            return list(self.__in[x])
        except KeyError:
            raise Exception("No such vertex")

    def isEdge(self,start,end):
        """
            Description: returns True if there is an edge from x to y, False otherwise

            Time complexity: O(1)
        """
        try:
            return end in self.__out[start]
        except KeyError:
            raise Exception("No such pair of verticees in the graph")

    def addEdge(self,start,end):
        """
        adds an edge (start,end) that has that cost to the graph
            precondition: the edge mustn't already exist and the vertices need to be valid
            in case it doesn't exist or the vertices aren't valid the error is handled and the user is informed
        """ 

        exceptions = ""
        if self.isEdge(start,end):
            exceptions += "Already exist;"
        if len(exceptions):
            raise Exception(exceptions)
        self.__out[start].append(end)
        self.__in[end].append(start)

    def addVertex(self):
        """
            Description: adds the vertex x to the graph, as an isolated vertex

            Precondition: x mustn't already be a vertex in the graph
                          if it is, the errors is handled and the user is informed

            Time complexity: O(1)
        """
        self.__vertices += 1
        d = self.__vertices-1
        self.__out[d] = []
        self.__in[d] = []

    def nrVertices(self):
        """
            Description: returns an integer containing the number of vertices in the graph

            Time complexity: O(1)
        """
        return len(self.Keys())

    def outDegree(self,x):
        """
            Description: return an integer representing the out degree of the vertex x
            precondition: x needs to be a valid vertex in the graph
            in case it isn't, the error is handled and the user is informed
        
            Time complexity: O(1)
        """
        try:
            return len(self.__out[x])
        except KeyError:
            raise Exception("No such vertex")

    def inDegree(self, x):
        """
            Description: returns an integer representing the in degree of the vertex x
                         precondition: x needs to be a valid vertex in the graph
                         in case it isn't, the error is handled and the user is informed
            
            Time complexity: O(1)
            """
        try:
            return len(self.__in[x])
        except KeyError:
            raise Exception("No such vertex")

    def toposort(self):
        """
        Description: returns a list containing the vertices of the graph sorted in topological order
                     or none if it has cycles(not a DAG)
        
        Time complexity: O(V + E)
        """
        vertices = self.Keys()
        q = []
        sorted_list = []
        count = {}
        for v in vertices:
            count[v] = len(list(self.neighboursOfXIn(v)))
            if count[v] == 0:
                q.append(v)

        while len(q) != 0:
            x = q.pop(0)
            sorted_list.append(x)
            for y in self.neighboursOfXOut(x):
                count[y] -= 1
                if count[y] == 0:
                    q.append(y)
        
        if len(sorted_list) < len(vertices):
            sorted_list = None
        
        return sorted_list
    
    def maximum_nodes(self):
        """
            Description: returns the maximum amount of nodes that we can visit starting from a fixed node

            Time complexity: O(n^2)
        """
        
        # This variable will hold the position in dp and items where the path containing the maximum amount of nodes ends
        pos_max = 0

        # topo_list will hold the vertices of the graph, topologically sorted
        topo_list = list(self.toposort())
        # dp will store the maximum amount of nodes that we can visit until reaching a specific node
        dp = []
        items = []

        # Initialize dp with 1(the maximum amount of nodes that we can visit until reaching a specific node is at least 1)
        for i in range(len(topo_list)):
            dp.append(1)
            items.append([topo_list[i]])
        
        # dp[i] will be either dp[i] or dp[j] + 1 where dp[j] is the maximum amount of nodes that we can visit until reaching j
        # provided that there is an edge from j to i
        for i in range(1, len(topo_list)):
            for j in range(i, -1, -1):
                if self.isEdge(topo_list[j], topo_list[i]):
                    new = max(dp[i], dp[j] + 1)
                    if new > dp[i]:
                        dp[i] = new
                        items[i] = copy.deepcopy(items[j])
                        items[i].append(topo_list[i])

                    if (dp[pos_max] < dp[i]):
                        pos_max = i
        
        return items[pos_max]
