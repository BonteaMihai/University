from myException import myException

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

    def min_cost_walk(self, start_node, destination_node):
        ABSOLUTE_MIN = -999999999999999999999
        ABSOLUTE_MAX = 9999999

        #Initializing the matrix with a really high cost
        d = []
        for i in range(0, len(self.__dictEdges)):
            d.append([])
            for j in range(0, len(self.__dictEdges)):
                d[i].append(ABSOLUTE_MAX)
        
        #Initializing the first column of the matrix
        for i in range(0, len(self.__dictEdges)):
            if (start_node, i) in self.__cost.keys():
                d[i][0] = self.__cost[(start_node, i)]
                if (d[i][0] < 0):
                    d[i][0] = ABSOLUTE_MIN
        
        for j in range(1, len(self.__dictEdges)):
            for i in range(0, len(self.__dictEdges)):
                minimum_val = ABSOLUTE_MAX
                for x in range(0, len(self.__dictEdges)):
                    if (i, x) in self.__cost.keys():    #there is a walk between i and x
                        if ( d[x][j - 1] + self.__cost[(i, x)] ) < minimum_val :
                            minimum_val = d[x][j - 1] + self.__cost[(i, x)]
                d[i][j] = minimum_val

        negative_exists = False
        minimum_val = ABSOLUTE_MAX
        walk_length = 0
        #Matrix has been fully generated, now printing the results
        for j in range(0, len(self.__dictEdges)):
            if d[destination_node][j] < 0:
                negative_exists = True
            if d[destination_node][j] < minimum_val:
                minimum_val = d[destination_node][j]
                walk_length = j

        if negative_exists == True:
            print("There are negative cost cycles accessible from the starting vertex!")
            return

        if minimum_val == ABSOLUTE_MAX:
            print("Destination node is impossible to reach!")
            return 

        print("The minimum cost walk between " + str(start_node) + " and " + str(destination_node) + " is " + str(minimum_val) )
         
        walk = [destination_node]
        current_length = walk_length
        #current_value = minimum_val
        current_node = destination_node

        """
        for j in range(current_length - 1, -1, -1):
            for i in range(0, len(self.__dictEdges)):
                if (i, current_node) in self.__cost.keys():
                    if d[i][j] + self.__cost[(i, current_node)] == d[current_node][current_length]:
                        walk.append(i)
                        current_node = i
                        break
        """
        while current_length > 0:
            for i in range(0, len(self.__dictEdges)):
                if (i, current_node) in self.__cost.keys():
                    if d[i][current_length - 1] + self.__cost[(i, current_node)] == d[current_node][current_length]:
                        walk.append(i)
                        current_node = i
                        current_length -= 1
                        break 

        walk.append(start_node)
        walk.reverse()
        print(walk)

        """
        for i in range(0, len(self.__dictEdges)):
            print(d[i])
        """

    def parseNeighbours(self,x):
        return self.__dictEdges[x]
    
    def parseKeys(self):
        return list(self.__dictEdges.keys())
        