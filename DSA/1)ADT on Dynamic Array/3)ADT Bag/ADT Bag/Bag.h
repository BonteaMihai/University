#pragma once
#include "DynArray.h"
#include "BagIterator.h"

typedef int TElem;

class BagIterator;

class Bag
{

	friend class BagIterator;

private:
	/*representation of Bag*/
	Array<std::pair<TElem, int> > elems;

	int elem_count;

public:

	Bag();

	void add(TElem elem);
	/*
		Description: adds an element to the bag

		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: theta(n)
	*/

	bool remove(TElem elem);
	/*
		Description: removes one occurence of an element from the bag
					 returns true if an element was removed, false otherwise

		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: theta(n)
	*/

	bool search(TElem elem) const;
	/*
		Description: returns true if element appears in the bag, false otherwise

		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: theta(n)
	*/


	int nrOccurrences(TElem elem) const;
	/*
		Description: returns the number of occurences for an element in the bag

		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: theta(n)
	*/

	int size() const;
	/*
		Description: returns the number of elements from the bag

		Best Case = Worst Case = Average Case = theta(1)
	*/

	BagIterator iterator();
	/*
		Description: returns an iterator for this bag

		Best Case = Worst Case = Average Case = theta(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks if the bag is empty

		Best Case = Worst Case = Average Case = theta(1)
	*/

	~Bag();
};