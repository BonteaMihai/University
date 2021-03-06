from UndirectedGraph import UndirectedGraph
from myException import myException

class Console:
    
    def __init__(self):
        self.__fileName = "example.txt"
        self.__options={"1":self.__loadGraph, "2":self.__connectedComponentsWithBFS,
                        "3":self.__addEdge,"4":self.__addVertex}
            
    def __printMenu(self): 
        print("Options: ")
        print("1)Load graph")
        print("2)Print the connected components using depth first search")
        print("3)Add edge")
        print("4)Add vertex")
        print("exit-to quit the program")
    
    def __loadGraph(self):
        try:
            with open(self.__fileName,"r") as file:
                firstLine = file.readline()
                firstLine = firstLine.strip().split()
                vertices,edges = int(firstLine[0]),int(firstLine[1])
                self.__graph = UndirectedGraph(vertices)
                for times in range(edges): 
                    line = file.readline()
                    line = line.strip().split()
                    start,end,cost = int(line[0]),int(line[1]),int(line[2])
                    try:
                        self.__graph.addEdge(start, end)
                    except myException as me:
                        continue
            print("Graph loaded.")
        except IOError:
            raise myException("File Reading Error")
            
    def __connectedComponentsWithBFS(self):
        self.__graph.connectedComponents()
        print("The connected components consist of the following lists of vertices:")
        self.__graph.printSubgraphs()
        print("Each list of vertices is now a subgraph, stored in a list of subgraphs as a private field of the Undirected Graph class")
        
    def __addEdge(self):
        print("x:")
        x = int(input())
        print("y:")
        y = int(input())
        try:
            self.__graph.addEdge(x, y)
        except myException as me:
            print(me)
            
    def __addVertex(self):
        print("x:")
        x = int(input())
        try:
            self.__graph.addVertex(x)
        except myException as me: 
            print(me)
            
    def main(self):
        print(">>")
        while True:
            self.__printMenu()
            
            cmd = input()
            
            if cmd == "exit":
                return 
            elif cmd in self.__options:
                self.__options[cmd]()
        
c = Console()
c.main()
