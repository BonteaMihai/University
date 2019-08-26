#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Maze.h"
#include <cassert>

int main()
{
	Maze maze;

	std::ifstream fin("data.in");

	maze.Read(fin);

	assert(maze.nrLines() == 8);
	assert(maze.nrColumns() == 9);
	assert(maze.can_escape() == true);

	maze.print_maze(std::cout);

	maze.print_shortest_path(std::cout);

	system("pause");
	return 0;
}