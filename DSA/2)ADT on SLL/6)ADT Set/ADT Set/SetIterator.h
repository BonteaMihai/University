#pragma once

#include "Set.h"
#include "SLLIterator.h"

class Set;
typedef int TElem;

template <class T>
class SLLIterator;

class SetIterator
{
	friend class Set;

private:
	Set &set;
	SLLIterator<TElem> it;
	SetIterator(Set& set);
public:
	void first();
	/*
		Description: sets the current element from the iterator to the first element
					 of the container
		Best Case = Worst Case = Average Case = theta(1)
	*/

	void next();
	/*
		Description: moves the current element from the container to the next
					 element or makes the iterator invalid if no elements
					 are left
		pre: iterator is valid
		throws: an exception if iterator is not valid
		Best Case = Worst Case = Average Case = theta(1)
	*/

	bool valid() const;
	/*
		Description: verifies if the iterator is valid
		Best Case = Worst Case = Average Case = theta(1)
	*/


	TElem getCurrent();
	/*
		Description: returns the current element from the iterator
		pre: iterator is valid
		throws: an exception if iterator is not valid
		Best Case = Worst Case = Average Case = theta(1)
	*/
};