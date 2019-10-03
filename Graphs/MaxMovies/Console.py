from Graph import Graph
from myException import myException

class Console:
    
    def __init__(self):
        self.__filename = "example.txt"
        self.__options = {"1":self.__loadGraph, "2": self.__maxMovies}
            
    def __printMenu(self): 
        print("Options: ")
        print("1)Load the movie graph from example.txt")
        print("2)Print the maximum amount of movies one can see")
        print("exit-to quit the program")

    def __loadGraph(self):
        try:
            with open(self.__filename, "r") as file:
                firstLine = file.readline()
                nr_movies = int(firstLine)

                self.__graph = Graph(nr_movies)
                self.__movie_list = []

                for i in range(nr_movies):
                    line = file.readline()
                    line = line.strip().split()
                    movie_name, start, end = line[0] ,int(line[1]), int(line[2])
                    self.__movie_list.append((movie_name, start, end))

                    for j in range(i):
                        if self.__movie_list[j][1] < start and self.__movie_list[j][2] <= start:
                            self.__graph.addEdge(j, i)
                        elif start < self.__movie_list[j][1] and end <= self.__movie_list[j][1]:
                            self.__graph.addEdge(i, j)
            print("Graph loaded.")
        except IOError:
            raise myException("File Reading Error")
    
    def __maxMovies(self):

        max_list = list(self.__graph.maximum_nodes())
        print("The maximum number of movies one can view is " + str(len(max_list)))
        print("The movies, in order are: ")
        for i in range(len(max_list)):
            print( self.__movie_list[max_list[i]][0] , end = ", ") 
        print("\n\n")

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