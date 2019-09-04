#pragma once
#include "DynArray.h"

typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool(*Relation)(TPriority p1, TPriority p2);

class TripleHeap
{
private:
	Relation r;
	Array<Element> elems;
	void bubble_up(size_t position);
	/*
		Best Case: O(1)
		Worst Case:	O(log n)
		Average Case: O(log n)
	*/

	void bubble_down(size_t position);
	/*
		Best Case: O(1)
		Worst Case: O(log n)
		Average Case: O(log n)
	*/
public:
	TripleHeap() = default;

	TripleHeap(Relation r);

	~TripleHeap();

	void add(Element elem);
	/*
		Description: adds a new element to the heap
		Best Case: O(1)
		Worst Case:	O(log n)
		Average Case: O(log n)
		-if it exceeds the capacity, the complexity of resize() operation is added: O(n)
	*/

	Element remove();
	/*
		Description: removes and returns the top of the heap
		Best Case: O(1)
		Worst Case:	O(log n)
		Average Case: O(log n)
	*/

	Element get_root() const;
	/*
		Description: returns the top of the heap
		Best Case = Worst Case = Average Case = O(1)
	*/

	size_t size() const;
	/*
		Description: returns the number of elements in the heap
		Best Case = Worst Case = Average Case = O(1)
	*/

	bool isEmpty() const;
	/*
		Description: tells whether the heap is empty or not
		Best Case = Worst Case = Average Case = O(1)
	*/
};