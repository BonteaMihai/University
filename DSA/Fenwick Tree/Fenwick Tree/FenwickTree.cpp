#include "FenwickTree.h"
#include <stdexcept>
#include <cstring>

FenwickTree::FenwickTree(): elems{ nullptr }, length{ 0 }
{

}

FenwickTree::~FenwickTree()
{
	delete[] elems;
}

void FenwickTree::Read(std::istream &stream)
{
	// Cleanup
	if (elems != nullptr)
		delete[] elems;

	stream >> length;
	if (length <= 0)
		throw std::exception();

	// Allocate space for the array and set all elements to 0
	elems = new TElem[length + 1];
	memset(elems, 0, sizeof(TElem) * (length + 1));

	TElem aux;
	for (unsigned index = 1; index <= length; ++index)
	{
		stream >> aux;
		Update(index, aux);
	}
}

void FenwickTree::Update(unsigned position, TElem value)
{
	// throw exception if position is not valid
	if (position <= 0 || position > length)
		throw std::exception();

	TElem C = 0;
	while (position <= length)
	{
		elems[position] += value;
		while (!(position & (1 << C)))
			C++;

		position += (1 << C);
		C += 1;
	}
}

TElem FenwickTree::Query_wrapper(unsigned position_a, unsigned position_b) const
{
	// throw exception if any of the positions is not valid
	if (position_a <= 0 || position_b <= 0 || position_a > length || position_b > length)
		throw std::exception();

	if (position_a > position_b)
		throw std::exception();
	
	if (position_a != 1)
		return (Query(position_b) - Query(position_a - 1));
	else
		return Query(position_b);
}

TElem FenwickTree::Query(unsigned position) const
{
	TElem C = 0;
	TElem sum = 0;
	while (position > 0)
	{
		sum += elems[position];
		while (!(position & (1 << C))) C++;
		position -= (1 << C);
		C += 1;
	}

	return sum;
}

unsigned FenwickTree::Search(TElem sum) const
{
	unsigned index, step;

	for (step = 1; step < length; step <<= 1);

	for (index = 0; step; step >>= 1)
	{
		if (index + step <= length)
		{
			if (sum >= elems[index + step])
			{
				index += step, sum -= elems[index];
				if (!sum) return index;
			}
		}
	}

	return 0;
}