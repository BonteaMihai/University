#pragma once
#include "SLL.h"
#include "SetIterator.h"

typedef int TElem;

class SetIterator;

class Set
{

	friend class SetIterator;

private:

	/* representation of Set*/
	SLL<TElem> elems;

public:

	Set();

	bool add(TElem elem);
	/*
		Description: adds an element to the set. If the element was added, the operation
					 returns true, otherwise(if the element was already in the set)
					 it returns false

		Best Case: O(1)
		Worst Case: O(n)
		Average Case: O(n)
	*/

	bool remove(TElem elem);
	/*
		Description: removes one element from the set
					 returns true if an element was removed, false otherwise

		Best Case: O(1)
		Worst Case: O(n)
		Average Case: O(n)
	*/


	bool search(TElem elem) const;
	/*
		Description: checks if an element is in the set

		Best Case: O(1)
		Worst Case: O(n)
		Average Case: O(n)
	*/

	int size() const;
	/*
		Description: returns the number of elements

		Best Case = Worst Case = Average Case = O(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks if the set is empty

		Best Case = Worst Case = Average Case = O(1)
	*/

	SetIterator iterator();
	/*
		Description: returns an iterator for the set

		Best Case = Worst Case = Average Case = O(1)
	*/

	~Set();
};