#pragma once
#include "Queue.h"

class Maze
{
private:
	/*
	*	map[i][j] == 0(empty non-visited)
	*	map[i][j] == <non zero positive number> (visited)
	*	map[i][j] == -1(wall)
	*	will be dynamically allocated when the user inputs the maze layout
	*/
	int **map;
	std::pair<int, int> start_pos;
	int nr_lines, nr_columns;

	std::pair<int, int> end_pos;

	bool is_valid(int i, int j) const;
	/*
		Description: checks whether position (i, j) is a valid position
					 in the maze(inside the borders and unobstructed
					 by walls) and unvisited
		Best Case = Worst Case = Average Case = O(1)
	*/

	bool escaped(int i, int j) const;
	/*
		Description: checks whether position (i, j) is an escape point
					 from the maze(on the margins of the maze)
		Best Case = Worst Case = Average Case = O(1)
	*/

	void pathfind_lee();
	/*
		Description: uses a fill algorithm on the maze, updates way_out
					 boolean variable 'way_out'
		Best Case = Worst Case = Average Case = O(number of lines * number of columns)
	*/

	void print_shortest_rec(std::ostream &stream, int i, int j) const;
	/*
		Description: prints recursively the way from the end position
					 to the beginning position
		Best Case = Worst Case = Average Case = O(dist(start, end))
	*/

public:
	Maze();

	~Maze();

	int nrLines() const;
	/*
		Description: returns the number of lines
		throws: exception if no maze was read
		Best Case = Worst Case = Average Case = O(1)
	*/

	int nrColumns() const;
	/*
		Description: returns the number of columns
		throws: exception if no maze was read
		Best Case = Worst Case = Average Case = O(1)
	*/

	void Read(std::istream &stream);
	/*
		Description: reads the number of lines, number of columns,
					 then the layout of the maze, and runs a pathfinding
					 algorithm on the resulting maze
					 Valid characters are: 'X' - wall
										   '*' - empty space
										   'R' - starting position
		throws: exception if number of lines, or number of columns is negative or 0
				or if an invalid character is read
		Best Case = Worst Case = Average Case = O(number of lines * number of columns)
	*/

	bool can_escape() const;
	/*
		Description: tells whether there exists a way out of the maze
		throws: exception if no maze was read
		Best Case = Worst Case = Average Case = O(1)
	*/

	void print_shortest_path(std::ostream &stream) const;
	/*
		Description: outputs the shortest path of escaping the maze
					 (if one exists)
		throws: exeption if no maze was read
		Best Case = Worst Case = Average Case = O(number of lines * number of columns)
	*/

	void print_maze(std::ostream &stream) const;
	/*
		Description: outputs the maze(under the format it was inputed)
		throws: exception if no maze was read
		Best Case = Worst Case = Average Case = O(number of lines * number of columns)
	*/
};