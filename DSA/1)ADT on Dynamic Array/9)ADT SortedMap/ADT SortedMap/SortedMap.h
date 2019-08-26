#pragma once
#include "DynArray.h"
#include "SMIterator.h"
#include <utility>
#define NULL_TVALUE -1


typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

typedef bool(*Relation)(TKey, TKey);

class SMIterator;

class SortedMap
{
	friend class SMIterator;

private:

	//representation of SortedMap
	Array<TElem> elems;
	Relation r;

	int find_key_pos(TKey c) const;
	/*
		Description: binary searches the key c, returns the first
					 greater or equal position, or -1 if there are none

		Best Case = O(1)
		Worst Case = O(log n)
		Average Case = O(log n)
	*/
public:

	SortedMap(Relation r);

	TValue add(TKey c, TValue v);
	/*
		Description: adds a pair <key, value> to the map
					 If the key already exists in the map, then the value associated
					 to the key is replaced by the new value and the old one
					 is returned. If the key does not exist, a new pair is added,
					 and the value null is returned

		Best Case = O(log n)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	TValue search(TKey c) const;
	/*
		Description: searches for the key and returns the value associated with the key
		if the map contains it, or null otherwise

		Best Case = O(1)
		Worst Case = O(log n)
		Average Case = O(log n)
	*/

	TValue remove(TKey c);
	/*
		Description: removes a key from the map and returns the value associated
					 with the key if the key existed, or null otherwise

		Best Case = O(log n)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	int size() const;
	/*
		Description: returns the number of pairs <key, value> from the map

		Best Case = Worst Case = Average Case = O(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks whether the map is empty or not

		Best Case = Worst Case = Average Case = O(1)
	*/

	SMIterator iterator();
	/*
		Description: returns the iterator for the map
					 the iterator will return the keys following the order
					 given by the relation

		Best Case = Worst Case = Average Case = O(1)
	*/

	~SortedMap();

};