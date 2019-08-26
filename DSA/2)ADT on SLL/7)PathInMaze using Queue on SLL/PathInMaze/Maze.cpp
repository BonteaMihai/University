#include "Maze.h"
#include <stdexcept>

Maze::Maze()
{
	map = NULL;
	start_pos.first = -1;
	start_pos.second = -1;
	nr_lines = nr_columns = -1;
}

Maze::~Maze()
{
	if (map != NULL)
	{
		for (int index = nr_lines - 1; index >= 0; --index)
			delete[] map[index];
		delete[] map;
	}
}

int Maze::nrLines() const
{
	if (nr_lines == -1)
		throw std::exception();

	return nr_lines;
}

int Maze::nrColumns() const
{
	if (nr_columns == -1)
		throw std::exception();

	return nr_columns;
}

bool Maze::is_valid(int i, int j) const
{
	if (i < 0 || j < 0 || i >= nr_lines || j >= nr_columns)
		return false;
	
	return (map[i][j] != -1);
}

bool Maze::escaped(int i, int j) const
{
	return (i == 0 || j == 0 || i == nr_lines - 1 || j == nr_columns - 1);
}

void Maze::pathfind_lee()
{
	// Arrays which describe movement inside the maze
	short di[4] = { 0, 0, 1, -1 };
	short dj[4] = { 1, -1, 0, 0 };

	// Initialize boolean value, assume maze has no way out
	end_pos.first = end_pos.second = -1;

	Queue<std::pair<int, int> > q;
	
	int i, j, next_i, next_j;

	// Push the starting position in the queue
	q.push(start_pos);
	map[start_pos.first][start_pos.second] = 1;

	while (!q.isEmpty())
	{
		i = q.top().first;
		j = q.top().second;
		q.pop();

		for (short direction = 0; direction < 4; ++direction)
		{
			next_i = i + di[direction];
			next_j = j + dj[direction];

			if (is_valid(next_i, next_j) && map[next_i][next_j] == 0)
			{
				map[next_i][next_j] = map[i][j] + 1;
				q.push(std::make_pair(next_i, next_j));

				if (escaped(next_i, next_j))
				{
					end_pos.first = next_i;
					end_pos.second = next_j;
					return;
				}
			}
		}
	}
}

void Maze::Read(std::istream &stream)
{
	// Are we overwriting the previous maze?
	if (map != NULL)
	{
		for (int index = nr_lines - 1; index >= 0; --index)
			delete[] map[index];
		delete[] map;

		map = NULL;
		start_pos.first = -1;
		start_pos.second = -1;
		nr_lines = nr_columns = -1;
	}

	stream >> nr_lines >> nr_columns;

	if (nr_lines <= 0 || nr_columns <= 0)
		throw std::exception();

	// Allocating memory for a two dimensional array
	map = new int*[nr_lines];
	for (int index = 0; index < nr_lines; ++index)
		map[index] = new int[nr_columns];

	char character;

	// Reading the contents of the maze, converting it to an integer
	// matrix, for easier pathfinding on its contents, and less waste
	// of memory space
	for (int line_index = 0; line_index < nr_lines ; ++line_index)
		for (int column_index = 0; column_index < nr_columns; ++column_index)
		{
			stream >> character;
			if (character == '*')		// empty space
				map[line_index][column_index] = 0;
			else if (character == 'X')	// wall
				map[line_index][column_index] = -1;
			else if (character == 'R')	// starting position
			{
				start_pos.first = line_index;
				start_pos.second = column_index;
			}
			else
				throw std::exception();
		}

	// Apply a pathfinding algorithm on the maze
	pathfind_lee();
}

bool Maze::can_escape() const
{
	if (map == NULL)
		throw std::exception();

	return end_pos.first != -1;
}

void Maze::print_shortest_rec(std::ostream &stream, int i, int j) const
{
	// Arrays which describe movement inside the maze
	int di[4] = { 0, 0, 1, -1 };
	int dj[4] = { 1, -1, 0, 0 };

	int next_i, next_j;

	if (map[i][j] != 1)
	{
		for (int direction = 0; direction < 4; ++direction)
		{
			next_i = i + di[direction];
			next_j = j + dj[direction];
			if (is_valid(next_i, next_j) && map[next_i][next_j] == map[i][j] - 1)
				break;
		}
		print_shortest_rec(stream, next_i, next_j);
	}
	stream << "(" << i << ", " << j << ") ";
}


void Maze::print_shortest_path(std::ostream &stream) const
{
	if (map == NULL)
		throw std::exception();

	if (end_pos.first == -1)
	{
		stream << "There is no way out of the maze!\n";
	}
	else
	{
		stream << "Shortest path has length " << map[end_pos.first][end_pos.second] - 1 << '\n';
		print_shortest_rec(stream, end_pos.first, end_pos.second);
	}
}

void Maze::print_maze(std::ostream &stream) const
{
	if (map == NULL)
		throw std::exception();

	for (int line_index = 0; line_index < nr_lines; ++line_index)
	{
		for (int column_index = 0; column_index < nr_columns; ++column_index)
		{
			if (map[line_index][column_index] == 1)
				stream << 'R';
			else if (map[line_index][column_index] == -1)
				stream << 'X';
			else stream << '*';
		}
		stream << '\n';
	}
}