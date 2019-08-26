from Graph import Graph

class Console():
    def __init__(self, fileName):
        self.__fileName = fileName
        self.__commands = {"0": self.__loadFromFile, "1": self.__num_distinct_walks}

    def printMenu(self):
        print("Options:\n")
        print("0) Loads the graph from file")
        print("1) Prints the number of distinct walks between 2 given vertices")
        print("Type quit to exit the program\n\n")

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
    
    def __num_distinct_walks(self):
        print("Insert the starting node")
        x = int(input())
        print("Insert the destination node")
        y = int(input())
        res = self.__graph.modified_BFS(x, y)
        if res == 0:
            print("No walk between vertex " + str(x) + " to vertex " + str(y))
        else:
            print("There are " + str(res) + " distinct walks between vertex " + str(x) + " and vertex " + str(y)) 

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