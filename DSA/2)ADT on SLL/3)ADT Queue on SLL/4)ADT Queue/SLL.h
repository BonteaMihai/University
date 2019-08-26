#pragma once
#include <iostream>

template <class T>
struct SLLNode
{
	T info;
	SLLNode *next;
};

template <class T>
class SLL
{
private:
	SLLNode<T> *head;
	SLLNode<T> *tail;
	int elem_count;
public:

	SLL();

	~SLL();

	SLLNode<T> *search(T elem) const;
	/*
		Description: returns the node which uses elem as info, or NULL
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	void insertFirst(T elem);
	/*
		Description: the given element will be inserted at the beginning of the SLL
		Best Case = Worst Case = Average Case = O(1)
	*/

	void insertLast(T elem);
	/*
		Description: the given element will be inserted at the end of the SLL
		Best Case = Worst Case = Average Case = O(1)
	*/

	void insertAfter(SLLNode<T> *currentNode, T elem);
	/*
		Description: a node containing elem will be inserted after currentNode
		Best Case = Worst Case = Average Case = O(1)
	*/

	void insertPosition(int position, T elem);
	/*
		Description: a node containig elem will be inserted after position
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	T getPosition(int position) const;
	/*
		Description: returns the element at the given position in the list
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	void setPosition(int position, T elem);
	/*
		Description: sets the information of the node at position to elem
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	SLLNode<T> *deleteElement(T elem);
	/*
		Description: the node containing elem is removed from the SLL and
					 a pointer to the node is returned
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	SLLNode<T> *deleteFirst();
	/*
		Description: the head of the SLL is removed and a pointer to the
					 node is returned
		Best Case = Worst Case = Average Case = O(1)
	*/

	SLLNode<T> *deleteLast();
	/*
		Description: the tail of the SLL is removed and a pointer to the
					 node is returned

		Best Case = Worst Case = Average Case = O(n)
	*/

	bool isEmpty() const;
	/*
		Description: checks whether the SLL is empty or not
		Best Case = Worst Case = Average Case = O(1)
	*/

	int size() const;
	/*
		Description: returns the number of elements in the SLL
		Best Case = Worst Case = Average Case = O(1)
	*/
};