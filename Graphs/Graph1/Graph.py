import copy


class Graph(object):
    def __init__(self, vertices):
        self.__in = {}
        self.__out = {}
        self.__cost = {}
        for i in range(vertices):
            self.__out[i] = []
            self.__in[i] = []
        self.__vertices = vertices

    def Keys(self):
        """returns a copy of all the vertex keys"""
        """
        Theta(n) n - number of vertices
        """
        return list(self.__out.keys())

    # def lenV(self):
    #     return len(list(self.__out.keys()))

    def neighboursOfXOut(self, x):
        """
        returns a copy of all out neighbours of x"""
        """
        Theta(n) n - number of vertices
        """
        try:
            return list(self.__out[x])
        except KeyError:
            raise Exception("No such vertex")

    def neighboursOfXIn(self, x):
        """
        return a copy of all in neighbours of x"""
        """
        Theta(n) n - number of vertices
        """
        try:
            return list(self.__in[x])
        except KeyError:
            raise Exception("No such vertex")

    def isEdge(self,start,end):
        """
        Returns True if there is an edge from x to y, False otherwise"""
        """ Theta(1) """
        try:
            return end in self.__out[start]
        except KeyError:
            raise Exception("No such pair of verticees in the graph")

    def addEdge(self,start,end,cost):
        """adds an edge (start,end) that has that cost to the graph
            precondition: the edge mustn't already exist and the vertices need to be valid
            in case it doesn't exist or the vertices aren't valid the error is handled and the user is informed"""
        """ Theta(1) """

        exceptions = ""
        if self.isEdge(start,end):
            exceptions += "Already exist;"
        if len(exceptions):
            raise Exception(exceptions)
        self.__out[start].append(end)
        self.__in[end].append(start)
        self.__cost[(start, end)] = cost

    def retrieveCost(self, start, end):

        if self.isEdge(start, end):
            return self.__cost[(start, end)]

    def addVertex(self):
        """adds the vertex x to the graph, as an isolated vertex
            precondition: x mustn't already be a vertex in the graph
            if it is, the errors is handled and the user is informed"""
        """Theta(1)"""
        self.__vertices += 1
        d = self.__vertices-1
        self.__out[d] = []
        self.__in[d] = []

    def removeVertex(self, vertice):
        """
        Delete the given vertice
        """
        if vertice > self.__vertices - 1:
            return False
        if vertice == self.__vertices - 1:
            del self.__in[self.__vertices - 1]
            del self.__out[self.__vertices - 1]
            for key in list(self.__cost.keys()):
                if vertice in key:
                    del self.__cost[key]
            for value in self.__in.values():
                if len(value) > 0:
                    i = 0
                    while i < len(value):
                        if value[i] == vertice:
                            value.pop(i)
                            i -= 1
                        i += 1
            for value in self.__out.values():
                if len(value) > 0:
                    i = 0
                    while i < len(value):
                        if value[i] == vertice:
                            value.pop(i)
                            i -= 1
                        i += 1
            self.__vertices -= 1
        else:
            edgesIn = self.__in[self.__vertices - 1]
            edgesOut = self.__out[self.__vertices - 1]
            del self.__out[self.__vertices - 1]
            del self.__in[self.__vertices - 1]
            del self.__in[vertice]
            del self.__out[vertice]
            self.__in[vertice] = edgesIn
            self.__out[vertice] = edgesOut
            for key in self.__in.keys():
                if vertice in self.__in[key]:
                    self.__in[key].remove(vertice)
                if self.__vertices - 1 in self.__in[key]:
                    self.__in[key].remove(self.__vertices - 1)
                    self.__in[key].append(vertice)
            for key in self.__out.keys():
                if vertice in self.__out[key]:
                    self.__out[key].remove(vertice)
                if self.__vertices - 1 in self.__out[key]:
                    self.__out[key].remove(self.__vertices - 1)
                    self.__out[key].append(vertice)
            for key in range(0, self.__vertices - 1):
                if (key, vertice) in self.__cost.keys():
                    del self.__cost[(key, vertice)]
                if (vertice, key) in self.__cost.keys():
                    del self.__cost[(vertice, key)]
                if (key, self.__vertices - 1) in self.__cost.keys():
                    cost = self.__cost[(key,self.__vertices - 1)]
                    del self.__cost[(key, self.__vertices - 1)]
                    self.__cost[(key, vertice)] = cost
                if (self.__vertices - 1, key) in self.__cost.keys():
                    cost = self.__cost[(self.__vertices - 1, key)]
                    del self.__cost[(self.__vertices - 1, key)]
                    self.__cost[(vertice, key)] = cost
            self.__vertices -= 1

    def removeEdge(self, start, end):
        """removes the edge (x,y) from the graph
        precondition: (x,y) needs to be a valid edge in the graph
        if it isn't, the error is handled and the user is informed """
        """Theta(1)"""
        if not self.isEdge(start, end):
            raise Exception("This edge does not exist")
        del self.__cost[(start, end)]
        self.__out[start].remove(end)
        self.__in[end].remove(start)

    def nrVertices(self):
        """
        return an integer containing the number of vertices in the graph
        """
        """Theta(1)"""
        return len(self.Keys())

    def outDegree(self,x):
        """return an integer representing the out degree of the vertex x
        precondition: x needs to be a valid vertex in the graph
        in case it isn't, the error is handled and the user is informed"""
        """Theta(1)"""
        try:
            return len(self.__out[x])
        except KeyError:
            raise Exception("No such vertex")

    def inDegree(self, x):
        """return an integer representing the in degree of the vertex x
            precondition: x needs to be a valid vertex in the graph
            in case it isn't, the error is handled and the user is informed"""
        """Theta(1)"""
        try:
            return len(self.__in[x])
        except KeyError:
            raise Exception("No such vertex")

    def modifyCost(self,x,y,new_cost):
        """modifies the cost of an edge
            precondition: (x,y) needs to be a valid edge in the graph
            if it isn't, the error is handled and the user is informed"""
        "Theta(1)"
        if(x,y) in self.__cost:
            self.__cost[(x,y)] = new_cost
        else:
            raise Exception("No such edge")

    def isolatedVertices(self):
        """Returns a list of all isolated vertices"""
        """Theta(n)"""
        vertices = []
        for k in self.Keys():
            if self.__in[k]==[]and self.__out[k]==[]:
                vertices.append(k)
        return vertices[:]

    def copyGraph(self):
        """Creates a copy of the current graph"""
        newGraph = Graph(self.__vertices)
        newGraph.__in = copy.deepcopy(self.__in)
        newGraph.__out = copy.deepcopy(self.__out)
        newGraph.__cost = copy.deepcopy(self.__cost)
        return newGraph

    def Edges(self):
        """return a list containing all the edges"""
        """Theta(n)"""
        edges = []
        for edge in self.__cost:
            edges.append(edge)
        return edges[:]

    def Costs(self):
        """return a list containing all the costs"""
        """Theta(n)"""
        costs = []
        for cost in self.__cost:
            costs.append(self.__cost[cost])
        return costs[:]


def tests():
    g = Graph(5)
    g.addVertex()
    assert g.nrVertices() == 6


tests()