#include "SortedMap.h"

SortedMap::SortedMap(Relation r) : r{ r }
{

}

SortedMap::~SortedMap()
{

}

int SortedMap::find_key_pos(TKey c) const
{
	// Binary search the first key greater or equal to c
	int Left = 0;
	int Right = elems.size() - 1;
	int Mid = (Left + Right) / 2;

	// This will be the first >= c position. If it is -1,
	// there are none such positions
	int position = -1;

	while (Left <= Right)
	{
		// Found the element
		if (elems.getElement(Mid).first == c)
		{
			position = Mid;
			break;
		}
		else if (r(elems.getElement(Mid).first, c))
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

	return position;
}

TValue SortedMap::add(TKey c, TValue v)
{
	int key_pos = find_key_pos(c);
	TElem aux = std::make_pair(c, v);

	// No greater or equal key, add it to the end
	if (key_pos == -1)
	{
		elems.addToEnd(aux);
		return NULL_TVALUE;
	}
	// Found equal key, change the value and return the old value
	else if (elems.getElement(key_pos).first == c)
	{
		TValue old_val = elems.getElement(key_pos).second;
		elems.setElement(key_pos, aux);
		return old_val;
	}
	// No equal key, insert it before the first greater key
	else
	{
		elems.addToPosition(key_pos, aux);
		return NULL_TVALUE;
	}
}

TValue SortedMap::search(TKey c) const
{
	int key_pos = find_key_pos(c);

	if (key_pos == -1 || elems.getElement(key_pos).first != c)
		return NULL_TVALUE;
	else
	{
		return elems.getElement(key_pos).second;
	}
}

TValue SortedMap::remove(TKey c)
{
	int key_pos = find_key_pos(c);

	if (key_pos == -1 || elems.getElement(key_pos).first != c)
		return NULL_TVALUE;
	else
	{
		TValue deleted_value = elems.getElement(key_pos).second;
		
		elems.deleteFromPosition(key_pos);

		return deleted_value;
	}
}

int SortedMap::size() const
{
	return elems.size();
}

bool SortedMap::isEmpty() const
{
	return elems.size() == 0;
}

SMIterator SortedMap::iterator()
{
	return SMIterator{ *this };
}