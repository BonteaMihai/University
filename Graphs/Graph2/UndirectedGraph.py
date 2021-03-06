from myException import myException

class UndirectedGraph:
    
    def __init__(self,vertices):
        self.__dictEdges = {}
        for i in range(0,vertices):
            self.__dictEdges[i]=[]
  
    def addEdge(self,x,y):
        if x not in self.__dictEdges[y] and y not in self.__dictEdges[x]:
            self.__dictEdges[x].append(y)
            self.__dictEdges[y].append(x)
        else: 
            raise myException("edge already exists")
    
    def addVertex(self,x):
        if x in self.__dictEdges:
            raise myException("vertex already exists")
        self.__dictEdges[x] = []
        
    def parseNeighbours(self,x):
        return self.__dictEdges[x]
    
    def parseKeys(self):
        return list(self.__dictEdges.keys())
    
    def __storeAsSubgraph(self,connectedComponent):
        g = UndirectedGraph(0)
        for v in connectedComponent:
            g.addVertex(v)
        for v in connectedComponent:
            for x in self.__dictEdges[v]:
                try: 
                    g.addEdge(v,x)
                except myException:
                    continue
        self.__subgraphs.append(g) 
        
    def connectedComponents(self):
        #will hold the connected components as subgraphs
        self.__subgraphs = [] 

        #list that tells whether a vertex has been visited
        visited = []
        for i in range(0,len(self.__dictEdges)):
            visited.append(False)

        #if vertex i is not visited, we go over the connected component containing it
        for i in range(0,len(self.__dictEdges)):
            if visited[i] == False:
                connectedComponent = self.bfs(i)
                self.__storeAsSubgraph(connectedComponent)
                for x in connectedComponent:
                    visited[x] = True
                    
    def dfs(self,start):
        explored=[]
        stack = [start]
        visited = [start]
        while stack:
            node = stack.pop()
            explored.append(node)
            neighbours = self.parseNeighbours(node)
            for neighbour in neighbours:
                if neighbour not in visited:
                    stack.append(neighbour)
                    visited.append(neighbour)
        return explored[:]
    
    def bfs(self, start):
        #initialize the queue and visited array with the starting node
        explored = []
        queue = [start]
        visited = [start]
        #while queue is not empty, pop the front of the queue and add its unvisited neighbours to the back
        while queue:
            node = queue.pop(0);
            explored.append(node)
            neighbours = self.parseNeighbours(node)
            for neighbour in neighbours:
                if neighbour not in visited:
                    queue.append(neighbour)
                    visited.append(neighbour)
        return explored
    
    def printSubgraphs(self):
        for sg in self.__subgraphs:
            print(sg.parseKeys())
