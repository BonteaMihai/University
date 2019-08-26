#pragma once
#include "DynArray.h"
#include "SortedSetIterator.h"

typedef int TElem;

typedef TElem TComp;

typedef bool(*Relation)(TComp, TComp);

class SortedSetIterator;

class SortedSet
{
	friend class SortedSetIterator;

private:

	/*Representation of the SortedSet*/

	Array<TComp> elems;
	Relation r;

public:

	SortedSet(Relation r);

	bool add(TComp elem);
	/*
		Description: adds an element to the sorted set
					 if the element was added, the operation returns true
					 otherwise(if the element was already in the set)
					 it returns false

		Best Case = theta(1)
		Worst Case = theta(n)
		Average Case = theta(n)
	*/

	bool remove(TComp elem);
	/*
		Description: removes an element from the sorted set
					 if the element was removed, it returns true,
					 otherwise false

		Best Case = theta(log n)
		Worst Case = theta(n)
		Average Case = theta(n)

	*/

	bool search(TElem elem) const;
	/*
		Description: checks if an element is in the sorted set

		Best Case = theta(1)
		Worst Case = theta(log n)
		Average Case = theta(log n)
	*/

	int size() const;
	/*
		Description: returns the number of elements from the sorted set

		Best Case = Worst Case = Average Case = theta(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks if the sorted set is empty

		Best Case = Worst Case = Average Case = theta(1)
	*/

	SortedSetIterator iterator();
	/*
		Description: returns an iterator for th sorted set

		Best Case = Worst Case = Average Case = theta(1)
	*/

	~SortedSet();

};
