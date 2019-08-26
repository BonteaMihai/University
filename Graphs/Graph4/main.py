from Graph import Graph

class Console():
    def __init__(self, fileName):
        self.__fileName = fileName
        self.__commands = {"0": self.__loadFromFile, "1": self.__toposort, "2": self.__highest_cost_path_DAG}

    def printMenu(self):
        print("Options:\n")
        print("0) Loads the graph from file")
        print("1) Does a topological sorting")
        print("2) Prints the maximum cost walk between 2 given vertices")
        print("Type quit to exit the program\n\n")
    
    """
    def __loadFromFile(self):
        try:
            with open(self.__fileName, "r") as file:
                firstLine = file.readline()
                firstLine = firstLine.strip().split()
                vertices, edges = int(firstLine[0]), int(firstLine[1])
                self.__graph = Graph(vertices)
                for times in range(edges):
                    line = file.readline()
                    line = line.strip().split()
                    start, end, cost = int(line[0]), int(line[1]), int(line[2])
                    self.__graph.addEdge(start, end, cost)
            print("Graph loaded.")
        except IOError:
            raise Exception("File Reading Error")
    """
    
    def __loadFromFile(self):
        try:
            with open(self.__fileName, "r") as file:
                firstLine = file.readline()
                firstLine = firstLine.strip().split()
                vertices = int(firstLine[0])
                self.__graph = Graph(vertices)
                for i in range(vertices):
                    line = file.readline()
                    line = line.strip().split()
                    activity_index, previous_activities = int(line[0]), int(line[1])
                    pos = 2
                    for j in range(previous_activities):
                        activity = int(line[pos])
                        pos += 1
                        duration = int(line[pos])
                        pos += 1
                        
                        self.__graph.addEdge(activity, activity_index, duration)
            print("Graph loaded.")
        except IOError:
            raise Exception("File Reading Error")
    

    def __toposort(self):
        result = self.__graph.toposort()
        if result == None:
            print("There are cycles in the graph")
        else:
            print (result)
    
    def __highest_cost_path_DAG(self):
        print("Insert the starting node")
        x = int(input())
        print("Insert the destination node")
        y = int(input())
        cost, walk = self.__graph.highest_cost_path_DAG(x, y)
        if cost == None:
            print("The graph given is not a DAG or destination node cannot be reached!")
        else:
            print("The maximum cost from vertex " + str(x) + " to vertex " + str(y) + " is: " + str(cost))
            print(walk)

    def run(self):
        while True:
            self.printMenu()
            print(">>")
            cmd = input()
            if cmd == "quit":
                return
            elif cmd in self.__commands:
                try:
                    self.__commands[cmd]()
                except Exception as e:
                    print(e)
            else:
                print("Wrong cmd")


c = Console("example.txt")
c.run()