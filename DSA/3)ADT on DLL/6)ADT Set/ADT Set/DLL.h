#pragma once
#include <iostream>

template<typename T>
class DLLIterator;

template <class T>
struct DLLNode
{
	T info;
	DLLNode *next;
	DLLNode *prev;
};

template <class T>
class DLL
{
private:
	friend class DLLIterator<T>;

	DLLNode<T> *head;
	DLLNode<T> *tail;
	int elem_count;
public:

	DLL();

	DLLNode<T> *search(T elem) const;
	/*
		Description: returns the node which uses elem as info, or NULL
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	void insertFirst(T elem);
	/*
		Description: the given element will be inserted at the beginning of the DLL
		Best Case = Worst Case = Average Case = O(1)
	*/

	void insertLast(T elem);
	/*
		Description: the given element will be inserted at the end of the SLL
		Best Case = Worst Case = Average Case = O(1)
	*/

	void insertAfter(DLLNode<T> *currentNode, T elem);
	/*
		Description: a node containing elem will be inserted after currentNode
		Best Case = Worst Case = Average Case = O(1)
	*/

	void insertPosition(size_t position, T elem);
	/*
		Description: a node containig elem will be inserted after position
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	T getPosition(size_t position) const;
	/*
		Description: returns the element at the given position in the list
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	void setPosition(size_t position, T elem);
	/*
		Description: sets the information of the node at position to elem
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	DLLNode<T> *deleteFirst();
	/*
		Description: the head of the DLL is removed and a pointer to the
					 node is returned
		Best Case = Worst Case = Average Case = O(1)
	*/

	DLLNode<T> *deleteLast();
	/*
		Description: the tail of the DLL is removed and a pointer to the
					 node is returned
		Best Case = Worst Case = Average Case = O(1)
	*/

	DLLNode<T> *deleteElement(T elem);
	/*
		Description: the node containing elem is removed from the DLL and
					 a pointer to the node is returned
		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
	*/

	bool isEmpty() const;
	/*
		Description: checks whether the DLL is empty or not
		Best Case = Worst Case = Average Case = O(1)
	*/

	size_t size() const;
	/*
		Description: returns the number of elements in the DLL
		Best Case = Worst Case = Average Case = O(1)
	*/

	DLLIterator<T> iterator();
	/*
		Description: returns an iterator for the DLL
		Best Case = Worst Case = Average Case = O(1)
	*/
};