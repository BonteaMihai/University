#pragma once
#include "DynArray.h"
#include "SortedBagIterator.h"

typedef int TComp;
typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);

class SortedBagIterator;

class SortedBag
{
	friend class SortedBagIterator;

private:

	/*representation of SortedBag*/
	Array < std::pair<TComp, int> >elems;
	Relation r;
	int elem_count;

public:

	SortedBag(Relation r);

	void add(TComp elem);
	/*
		Description: adds an element to the sorted bag

		Best Case = theta(1)
		Worst Case = theta(n)
		Average Case = theta(n)
	*/

	bool remove(TComp elem);
	/*
		Description: removes one occurence of an element from the sorted bag
					 returns true if an element was removed, false otherwise
					 (if elem was not part of the sorted bag)

		Best Case = theta(1)
		Worst Case = theta(n)
		Average Case = theta(n)
	*/

	bool search(TComp elem) const;
	/*
		Description: checks if an element is part of the sorted bag

		Best Case = theta(1)
		Worst Case = theta(log n)
		Average Case = theta(log n)
	*/

	int nrOccurrences(TComp elem) const;
	/*
		Description: returns the number of occurences for an element in the sorted bag

		Best Case = theta(1)
		Worst Case = theta(log n)
		Average Case = theta(log n)
	*/

	//returns the number of elements from the sorted bag
	int size() const;
	/*
		Description: returns the number of elements from the sorted bag
		
		Best Case = Worst Case = Average Case = theta(1)
	*/

	//returns an iterator for this sorted bag
	SortedBagIterator iterator();
	/*
		Description: returns an iterator for this sorted bag

		Best Case = Worst Case = Average Case = theta(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks if the sorted bag is empty

		Best Case = Worst Case = Average Case = theta(1)
	*/

	~SortedBag();
};