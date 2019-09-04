#pragma once
#include <utility>
#include "Heap.h"

using namespace std;

typedef int TElem;
typedef int TPriority;

typedef std::pair<TElem, TPriority> Element;

typedef bool(*Relation)(TPriority p1, TPriority p2);

class PriorityQueue {
private:
	Relation r;
	Heap heap;

public:
	PriorityQueue(Relation r);

	void push(TElem e, TPriority p);
	/*
		Description: adds an element to the priority queue
		Best Case: O(1)
		Worst Case: O(log n)
		Average Case: O(log n)
	*/

	Element top()  const;
	/*
		Description: returns the element with the highest priority with respect
					 to the order relation
		throws: excepton if the queue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	Element pop();
	/*
		Description: removes and returns the element with the highest priority
		throws: exception if the queue is empty
		Best Case: O(1)
		Worst Case: O(log n)
		Average Case: O(log n)
	*/

	bool isEmpty() const;
	/*
		Description: checks whether queue is empty or not
		Best Case = Worst Case = Average Case = O(1)
	*/

	~PriorityQueue();

};