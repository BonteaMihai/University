#pragma once
#include "DLL.h"

typedef int TElem;

class Queue
{
private:

	/*representation of Queue*/
	DLL<TElem> elems;
public:

	Queue();

	void push(TElem elem);
	/*
		Description: pushes an element to the end of the queue
		Best Case = Worst Case = Average Case = O(1)
	*/

	TElem top() const;
	/*
		Description: returns the element from the front of the queue
		throws: exception if the queue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	TElem pop();
	/*
		Description: removes and returns the element from the front of the queue
		throws: exception if the queue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks if the queue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	~Queue();
};