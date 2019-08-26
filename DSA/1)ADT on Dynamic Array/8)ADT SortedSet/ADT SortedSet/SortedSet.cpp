#include "SortedSet.h"

SortedSet::SortedSet(Relation r) : r{ r }
{

}

SortedSet::~SortedSet()
{

}

bool SortedSet::add(TComp elem)
{
	// Binary search the first element greater or equal to elem
	// as the array is sorted

	int Left = 0;
	int Right = elems.size() - 1;
	int Mid = (Left + Right) / 2;

	// This will be the first >= elem position. If it is -1, there are none
	// such positions, therefore it will be aded to the end

	int position = -1;

	while (Left <= Right)
	{
		// Element already appears, return false
		if (elems.getElement(Mid) == elem)
		{
			return false;
		}
		else if (r(elems.getElement(Mid), elem))
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

	// If position = -1, there are no greater elements according to the relation,
	// so we add it to the end of the array
	if (position == -1)
	{
		elems.addToEnd(elem);
	}
	// Else, insert the new element before the position
	else
	{
		elems.addToPosition(position, elem);
	}
	return true;
}

bool SortedSet::remove(TComp elem)
{
	// Binary search elem, as the array is sorted

	int Left = 0;
	int Right = elems.size() - 1;
	int Mid = (Left + Right) / 2;

	// This will be the position resulting from the binary search.
	// If it is -1, elem doesn't appear in the array
	int position = -1;

	while (Left <= Right)
	{
		if (elems.getElement(Mid) == elem)
		{
			position = Mid;
			break;
		}
		else if (r(elems.getElement(Mid), elem))
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

	// Element not found, return false
	if (position == -1)
		return false;
	else
	{
		elems.deleteFromPosition(position);
		return true;
	}
}

bool SortedSet::search(TElem elem) const
{
	// Binary search elem, as the array is sorted

	int Left = 0;
	int Right = elems.size() - 1;
	int Mid = (Left + Right) / 2;

	while (Left <= Right)
	{
		if (elems.getElement(Mid) == elem)
		{
			return true;
		}
		else if (r(elems.getElement(Mid), elem))
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
	return false;
}

int SortedSet::size() const
{
	return elems.size();
}

bool SortedSet::isEmpty() const
{
	return elems.size() == 0;
}

SortedSetIterator SortedSet::iterator()
{
	return SortedSetIterator{ *this };
}