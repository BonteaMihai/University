from Graph import Graph

class Console():
    def __init__(self, fileName):
        self.__fileName = fileName
        self.__commands = {"0": self.__loadFromFile, "1": self.__toposort, "2": self.__nr_distinct_walks_1}

    def printMenu(self):
        print("Options:\n")
        print("0) Loads the graph from file")
        print("1) Does a topological sorting")
        print("2) Prints the number of distinct walks between 2 given vertices with modified BFS")
        print("Type quit to exit the program\n\n")

    def __loadFromFile(self):
        try:
            with open(self.__fileName, "r") as file:
                firstLine = file.readline()
                firstLine = firstLine.strip().split()
                vertices = int(firstLine[0])
                self.__graph = Graph(vertices)
                for times in range(vertices):
                    line = file.readline()
                    line = line.strip().split()
                    activity_index, previous_activities = int(line[0]), int(line[1])
                    for i in range(previous_activities):
                        self.__graph.addEdge(int(line[i + 2]), activity_index, 0)

            print("Graph loaded.")
        except IOError:
            raise Exception("File Reading Error")

    def __toposort(self):
        result = self.__graph.toposort()
        if result == None:
            print("There are cycles in the graph")
        else:
            print (result)
    
    def __nr_distinct_walks_1(self):
        print("Insert the starting node")
        x = int(input())
        print("Insert the destination node")
        y = int(input())
        result = self.__graph.modified_BFS(x, y)
        if result == None:
            print("The graph given is not a DAG!")
        else:
            print("There are " + str(result) + " distinct walks between " + str(x) + " and " + str(y))
    
    def __nr_distinct_walks_2(self):
        print("Insert the starting node")
        x = int(input())
        print("Insert the destination node")
        y = int(input())
        

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