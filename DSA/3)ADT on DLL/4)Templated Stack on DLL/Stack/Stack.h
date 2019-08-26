#pragma once
#include "DLL.h"

template <class T>
class Stack
{
private:

	/*representation of Stack*/
	DLL<T> elems;
public:

	Stack();

	void push(T elem);
	/*
		Description: pushes an element to the top of the stack
		Best Case = Worst Case = Average Case = O(1)
	*/

	T top() const;
	/*
		Description: returns the element from the top of the stack
		throws: exception if the stack is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	T pop();
	/*
		Description: removes and returns the element from the top of the stack
		throws: exception if the stack is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks if the stack is empty
		Best Case = Worst Case = Average Case = O(1)
	*/

	~Stack();
};