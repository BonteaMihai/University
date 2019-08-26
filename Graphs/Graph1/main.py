from Graph import Graph
from COLORS import bcolors

class Console():
    def __init__(self, fileName):
        self.__fileName = fileName
        self.__commands = {"0": self.__loadFromFile, "1": self.__getNumberOfVertices,
                           "2": self.__printAllVertices, "3": self.__edgeFromXToY,
                           "4": self.__getDegrees, "5": self.__modifyCost,
                           "6": self.__addVertex, "7": self.__addEdge,
                           "8": self.__removeVertex, "9": self.__removeEdge,
                           "10": self.__copyGraph, "11": self.__printGraph, "12": self.__printGraphCopy,
                           "13": self.__parseOut,
                           "14": self.__isolatedVertices}

    #print(bcolors.FAIL + something + bcolors.ENDC)
    def printMenu(self):
        print(bcolors.OKBLUE + "Options:\n" + bcolors.ENDC)
        print("0) Loads the graph from file")
        print("1) Gets the number of vertices")
        print("2) See all vertices")
        print("3) See if there is an edge from <x> to <y>")
        print("4) Print the out degree and in degree of a vertex")
        print("5) Modify the cost of an edge")
        print(bcolors.OKBLUE + "Graph modifiers:" + bcolors.ENDC)
        print("6) Add a vertex")
        print("7) Add an edge")
        print("8) Remove a vertex")
        print("9) Remove an edge")
        print("10) Make a copy of the graph. The copy will be stored in the main class as a property.")
        print("11) Print the graph vertices and edges.")
        print("12) Print the copy of the graph with its vertices and edges.")
        print(bcolors.FAIL + "Type quit to exit the program\n\n" + bcolors.ENDC)

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
            print(bcolors.OKGREEN + "Graph loaded." + bcolors.ENDC)
        except IOError:
            raise Exception(bcolors.FAIL + "File Reading Error" + bcolors.ENDC)

    def __getNumberOfVertices(self):
        print(self.__graph.nrVertices())

    def __printAllVertices(self):
        print(self.__graph.Keys())

    def __edgeFromXToY(self):
        print(bcolors.WARNING + "Input vertices x and y:" + bcolors.ENDC)
        start = int(input())
        end = int(input())
        result = {True: "Yes", False: "No"}
        print(result[self.__graph.isEdge(start, end)])

    def __getDegrees(self):
        print(bcolors.WARNING + "Input vertex:" + bcolors.ENDC)
        vertex = int(input())
        print("Out degree: " + str(self.__graph.outDegree(vertex)))
        print("In degree: " + str(self.__graph.inDegree(vertex)))

    def __modifyCost(self):
        print(bcolors.WARNING + "Input edge start:" + bcolors.ENDC)
        start = int(input())
        print("Give edge end:")
        end = int(input())
        print(self.__graph.retrieveCost(start, end))
        print("Give new cost:")
        cost = int(input())
        self.__graph.modifyCost(start, end, cost)

    def __addVertex(self):
        print("A new vertex is added")
        self.__graph.addVertex()

    def __isolatedVertices(self):
        print(self.__graph.isolatedVertices())

    def __parseOut(self):
        print("Get vertex:")
        x = int(input())
        out = self.__graph.neighboursOfXOut(x)
        print(out)
        inZ = self.__graph.neighboursOfXIn(x)
        print(inZ)

    def __addEdge(self):
        print(bcolors.WARNING + "Input edge start: " + bcolors.ENDC)
        start = int(input())
        print(bcolors.WARNING + "Input edge end: " + bcolors.ENDC)
        end = int(input())
        print(bcolors.WARNING + "Input edge cost: " + bcolors.ENDC)
        cost = int(input())
        self.__graph.addEdge(start, end, cost)

    def __removeEdge(self):
        print(bcolors.WARNING + "Input edge start:" + bcolors.ENDC)
        start = int(input())
        print(bcolors.WARNING + "Input edge end:" + bcolors.ENDC)
        end = int(input())
        self.__graph.removeEdge(start, end)

    def __removeVertex(self):
        print(bcolors.WARNING + "Input vertex for removal:" + bcolors.ENDC)
        vertex = int(input())
        self.__graph.removeVertex(vertex)

    def __copyGraph(self):
        print(bcolors.OKGREEN + "Copying the graph..." + bcolors.ENDC)
        self.__graphCopy = self.__graph.copyGraph()
        print(bcolors.OKGREEN + "The graph is now copied and stored in __graphCopy" + bcolors.ENDC)
        print(self.__graphCopy.Keys())
        print(self.__graphCopy.Edges())

    def __printGraphCopy(self):
        print(self.__graphCopy.Keys())
        print(self.__graphCopy.Edges())

    def __printGraph(self):
        print(bcolors.OKGREEN + "The vertices of the graph are: " + bcolors.ENDC)
        print(self.__graph.Keys())
        print(bcolors.OKGREEN + "The edges of the graph are: " + bcolors.ENDC)
        print(self.__graph.Edges())

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
                print(bcolors.WARNING + "Wrong cmd" + bcolors.ENDC)


c = Console("example.txt")
c.run()