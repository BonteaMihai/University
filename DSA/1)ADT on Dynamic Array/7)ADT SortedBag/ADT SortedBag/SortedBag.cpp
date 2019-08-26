#include "SortedBag.h"

SortedBag::SortedBag(Relation r) : r{ r }
{
	elem_count = 0;
}

SortedBag::~SortedBag()
{

}

void SortedBag::add(TComp elem)
{
	elem_count++;
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
		// Found the element
		if (elems.getElement(Mid).first == elem)
		{
			position = Mid;
			break;
		}
		else if (r(elems.getElement(Mid).first, elem))
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
		elems.addToEnd(std::make_pair(elem, 1));
		return;
	}

	// If we found the exact element, increase its frequency
	std::pair<TComp, int> aux = elems.getElement(position);
	if (aux.first == elem)
	{
		aux.second++;
		elems.setElement(position, aux);
	}
	// Else, insert the new pair before the position
	else
	{
		elems.addToPosition(position, std::make_pair(elem, 1));
	}
}

bool SortedBag::remove(TComp elem)
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
		// Found the element
		if (elems.getElement(Mid).first == elem)
		{
			position = Mid;
			break;
		}
		else if (r(elems.getElement(Mid).first, elem))
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

	// If position = -1, elem is not in the array, so we return false
	if (position == -1)
		return false;
	// Else, we found elem
	else
	{
		std::pair<TComp, int> aux = elems.getElement(position);

		// Only one occurence, we remove it altogether
		if (aux.second == 1)
			elems.deleteFromPosition(position);
		else
		{
			aux.second--;
			elems.setElement(position, aux);
		}
		elem_count--;
		return true;
	}
}

bool SortedBag::search(TComp elem) const
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
		// Found the element
		if (elems.getElement(Mid).first == elem)
		{
			position = Mid;
			break;
		}
		else if (r(elems.getElement(Mid).first, elem))
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

	return position != -1;
}

int SortedBag::nrOccurrences(TComp elem) const
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
		// Found the element
		if (elems.getElement(Mid).first == elem)
		{
			position = Mid;
			break;
		}
		else if (r(elems.getElement(Mid).first, elem))
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

	// Element not found, return 0
	if (position == -1)
		return 0;
	else
	{
		std::pair<TComp, int> aux = elems.getElement(position);
		return aux.second;
	}
}

int SortedBag::size() const
{
	return elem_count;
}

SortedBagIterator SortedBag::iterator()
{
	return SortedBagIterator{ *this };
}

bool SortedBag::isEmpty() const
{
	return elem_count == 0;
}