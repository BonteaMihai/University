#pragma once
#define NULL_TVALUE -1
#include "DynArray.h"
#include "MapIterator.h"

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class MapIterator;

class Map
{
	friend class MapIterator;

private:

	// representation of Map
	Array<TElem> elems;

	int find_key_pos(TKey c) const;
	/*
		Description: utility function, returns the position in the Dynamic Array
					 where key is found, or -1 if it doesn't appear

		Best Case = theta(1)
		Wort Case = theta(n)
		Average Case = theta(n)
	*/

public:

	Map();

	TValue add(TKey c, TValue v);
	/*
		Description: adds a pair <key, value> to the map
					 if the key already exists in the map, then the value associated
					 to the key is replaced by the new value and the old value
					 is returned. If the key does not exist, a new pair is added and 
					 the value null is returned

		Best Case = theta(1)
		Worst Case = theta(n)
		Average Case = theta(n)
	*/

	TValue search(TKey c) const;
	/*
		Description: searches for the key and returns the value associated with the key
					 if the map contains the key, or null otherwise

		Best Case = theta(1)
		Wort Case = theta(n)
		Average Case = theta(n)
	*/

	TValue remove(TKey c);
	/*
		Description: removes a key from the map and returns the value associated
					 with the key if the key existed, or null otherwise

		Best Case = Worst Case = Average Case = theta(n)
	*/

	int size() const;
	/*
		Description: returns the number of pairs <key, value> from the map

		Best Case = Worst Case = Average Case = theta(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks whether the map is empty or not

		Best Case = Worst Case = Average Case = theta(1)
	*/

	MapIterator iterator();
	/*
		Description: returns an iterator for the map

		Best Case = Worst Case = Average Case = theta(1)
	*/

	~Map();
};


