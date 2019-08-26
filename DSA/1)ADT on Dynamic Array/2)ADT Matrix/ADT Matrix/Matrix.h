#pragma once
#include "DynArray.h"

typedef int TElem;
#define NULL_TELEM 0

class Triple
{
public:
	int line;
	int col;
	TElem val;

	Triple()
	{
		line = col = -1;
		val = NULL_TELEM;
	}

	Triple(int _line, int _col, TElem _val)
	{
		line = _line;
		col = _col;
		val = _val;
	}

	bool operator==(const Triple &other) const
	{
		return ((this->line == other.line) && (this->col == other.col));
	}

	bool operator<(const Triple &other) const
	{
		if (this->line < other.line)
			return true;
		else if (this->line > other.line)
			return false;
		else
			return this->col < other.col;
	}

};


class Matrix
{
private:

	/*representation of the matrix*/
	Array<Triple> elems;
	int nr_lines;
	int nr_cols;

public:

	Matrix(int nrLines, int nrCols);
	/*
		Description: constructor
		throws: exception if nrLines or nrCols is negative or zero
	*/

	int nrLines() const;
	/*
		Description: returns the number of lines

		Best Case = Worst Case = Average Case = theta(1)
	*/

	int nrColumns() const;
	/*
		Description: returns the number of columns

		Best Case = Worst Case = Average Case = theta(1)
	*/

	TElem element(int i, int j) const;
	/*
		Description: returns the element from line i and column j
					 (indexing starts from 0)
		throws: exception if (i, j) is not a valid position in the Matrix

		Best Case = theta(1)
		Worst Case = theta(log n)
		Average Case = theta(log n)
	*/

	TElem modify(int i, int j, TElem elem);
	/*
		Description: modifies the value from line i and column j
					 returns the previous value from the position
		throws: exception if (i, j) is not a valid position in the Matrix

		Best Case = theta(1)
		Worst Case = theta(log n)
		Average Case = theta(log n)
	*/
};
