#include "Map.h"

Map::Map()
{

}

Map::~Map()
{

}

int Map::find_key_pos(TKey c) const
{
	for (int index = 0; index < elems.size(); ++index)
		if (elems.getElement(index).first == c)
			return index;
	return -1;
}

TValue Map::add(TKey c, TValue v)
{
	int key_pos = find_key_pos(c);
	TElem aux = std::make_pair(c, v);
	// Key doesn't appear, add pair to end and return NULL_TVALUE
	if (key_pos == -1)
	{
		elems.addToEnd(aux);
		return NULL_TVALUE;
	}
	// Key already appears, update the value and return the old value
	else
	{
		TValue old_value = elems.getElement(key_pos).second;
		elems.setElement(key_pos, aux);
		return old_value;
	}
}

TValue Map::search(TKey c) const
{
	int key_pos = find_key_pos(c);

	// Key doesn't appear, return NULL_TVALUE
	if (key_pos == -1)
		return NULL_TVALUE;
	else
		return elems.getElement(key_pos).second;
}

TValue Map::remove(TKey c)
{
	int key_pos = find_key_pos(c);

	// Key doesn't appear, return NULL_TVALUE
	if (key_pos == -1)
		return NULL_TVALUE;
	else
	{
		TValue old_value = elems.getElement(key_pos).second;
		elems.deleteFromPosition(key_pos);
		return old_value;
	}
}

int Map::size() const
{
	return elems.size();
}

bool Map::isEmpty() const
{
	return elems.size() == 0;
}

MapIterator Map::iterator()
{
	return MapIterator{ *this };
}