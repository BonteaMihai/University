#pragma once
#include "SLL.h"

template <class T>
class Queue
{
private:

	/*representation of Queue*/
	SLL<T> elems;
public:

	Queue();

	void push(T elem);
	/*
		Description: pushes an element to the end of the queue
		Best Case = Worst Case = Average Case = O(1)
	*/

	T top() const;
	/*
		Description: returns the element from the front of the queue
		throws: exception if the queue is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	T pop();
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