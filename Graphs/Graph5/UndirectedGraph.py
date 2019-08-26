from myException import myException
from copy import deepcopy

class UndirectedGraph:
    
    def __init__(self,vertices):
        self.__dictEdges = {}
        self.__cost = {}
        for i in range(0,vertices):
            self.__dictEdges[i]=[]
  
    def addEdge(self,x,y, cost):
        if x not in self.__dictEdges[y] and y not in self.__dictEdges[x]:
            self.__dictEdges[x].append(y)
            self.__dictEdges[y].append(x)

            self.__cost[(x, y)] = cost
            self.__cost[(y, x)] = cost
        else: 
            raise myException("edge already exists")
    
    def addVertex(self,x):
        if x in self.__dictEdges:
            raise myException("vertex already exists")
        self.__dictEdges[x] = []
    
    def Back(self, stack):
        if self.__solution_found == False:
            if len(stack) == len(self.__dictEdges.keys()):
                if stack[0] in self.__dictEdges[ stack[len(stack) - 1] ]:
                    self.__solution_found = True
                    stack.append(stack[0])
                    self.__solution = deepcopy(stack)
            else:
                #ordering adjacent vertices by cost of (last element on stack, vertex)
                #so that the first choice will be a minimum cost edge
                v = self.__dictEdges[stack[len(stack) - 1]]     #the neighbours of the last vertex on the stack
                for i in range(len(v) - 1):
                    for j in range(len(v)):
                        if self.__cost[( stack[len(stack) - 1] , v[i])] > self.__cost[( stack[len(stack) - 1], v[j])]:
                            aux = v[i]
                            v[i] = v[j]
                            v[j] = aux
                #taking the lower cost edges first
                for vertex in v:
                    #we only allow a vertex appearing twice in the stack in the special case of it being the last
                    #so that a cycle of length < n is never closed
                    if vertex not in stack:

                            stack.append(vertex)

                            self.Back(stack)

                            stack.pop()


    def hamiltonianCycleBack(self):
        self.__solution_found = False
        self.__solution = []
        for vertex in self.parseKeys():
            if self.__solution_found == False:
                self.Back([vertex])
        
        if self.__solution_found == False:
            return None
        else:
            return self.__solution

    def parseNeighbours(self,x):
        return self.__dictEdges[x]
    
    def parseKeys(self):
        return list(self.__dictEdges.keys())
        