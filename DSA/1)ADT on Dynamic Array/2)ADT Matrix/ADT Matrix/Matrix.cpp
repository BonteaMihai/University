#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(int nrLines, int nrCols)
{
	if (nrLines <= 0 || nrCols <= 0)
		throw std::exception();

	nr_lines = nrLines;
	nr_cols = nrCols;
}

int Matrix::nrLines() const
{
	return nr_lines;
}

int Matrix::nrColumns() const
{
	return nr_cols;
}

TElem Matrix::element(int i, int j) const
{
	// Throw exception if (i, j) is an invalid position in the matrix
	if (i < 0 || i >= nr_lines || j < 0 || j >= nr_cols)
		throw std::exception();

	// Binary search the (i, j) position, as the <line, col, val> triples
	// are sorted lexicographically

	int Left = 0;
	int Right = elems.size() - 1;
	int Mid = (Left + Right) / 2;

	Triple aux = Triple(i, j, NULL_TELEM);

	while (Left <= Right)
	{
		Triple Mid_val = elems.getElement(Mid);

		if (Mid_val == aux)
		{
			return Mid_val.val;
		}
		else if (Mid_val < aux)
		{
			Left = Mid + 1;
			Mid = (Left + Right) / 2;
		}
		else
		{
			Right = Mid - 1;
			Mid = (Left + Right) / 2;
		}
	}
	
	// Position, not found but not invalid => value is NULL_TELEM
	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem elem)
{
	// Throw exception if (i, j) is an invalid position in the matrix
	if (i < 0 || i >= nr_lines || j < 0 || j >= nr_cols)
		throw std::exception();

	// Binary search the first >= (i, j) position, as the <line, col, val> triples
	// are sorted lexicographically

	int Left = 0;
	int Right = elems.size() - 1;
	int Mid = (Left + Right) / 2;

	Triple aux = Triple(i, j, elem);

	// This will be the first >= (i, j) position. If it is -1, there are none
	// such positions, therefore it will be added to the end
	int position = -1;

	while (Left <= Right)
	{
		Triple Mid_val = elems.getElement(Mid);

		if (Mid_val == aux)
		{
			position = Mid;
			break;
		}
		else if (Mid_val < aux)
		{
			Left = Mid + 1;
			Mid = (Left + Right) / 2;
		}
		else
		{
			position = Mid;
			Right = Mid - 1;
			Mid = (Left + Right) / 2;
		}
	}

	// If position = -1, add to the end of the array and return NULL_TELEM
	if (position == -1)
	{
		elems.addToEnd(aux);
		return NULL_TELEM;
	}

	// If we found the position, modify it and return the old value
	Triple elem_at_pos = elems.getElement(position);
	if (aux == elem_at_pos)
	{
		TElem old_value = elem_at_pos.val;

		elem_at_pos.val = elem;
		elems.setElement(position, elem_at_pos);
		
		return old_value;
	}
	// Else, insert the new triple before the position and return NULL_TELEM
	else
	{
		elems.addToPosition(position, aux);
		return NULL_TELEM;
	}
}