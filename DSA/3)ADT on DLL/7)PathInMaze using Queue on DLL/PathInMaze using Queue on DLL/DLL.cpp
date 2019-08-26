#include <iostream>
#include <stdexcept>
#include "DLL.h"

template <class T>
DLL<T>::DLL()
{
	head = NULL;
	tail = NULL;
	elem_count = 0;
}

template <class T>
DLLNode<T> *DLL<T>::search(T elem) const
{
	DLLNode<T> *current = head;
	while (current != NULL && current->info != elem)
		current = current->next;

	if (current != NULL && current->info == elem)
		return current;
	else
		return NULL;
}

template <class T>
void DLL<T>::insertFirst(T elem)
{
	++elem_count;
	DLLNode<T> *node = new DLLNode<T>; // allocated on heap

	node->info = elem; //set information
	node->prev = NULL; //set previous
	node->next = head; //set next

	if (head == NULL) //empty list => head == NULL && tail == NULL
	{
		head = node;
		tail = node;
	}
	else //there are more elements in the list
	{
		head->prev = node;
		head = node;
	}
}

template <class T>
void DLL<T>::insertLast(T elem)
{
	++elem_count;
	DLLNode<T> *node = new DLLNode<T>;

	node->info = elem; //set information
	node->prev = tail; //set previous
	node->next = NULL; //set next

	if (head == NULL) //empty list => head == NULL && tail == NULL
	{
		head = node;
		tail = node;
	}
	else //there are more elements in the list
	{
		tail->next = node;
		tail = node;
	}
}

template <class T>
void DLL<T>::insertAfter(DLLNode<T> *currentNode, T elem)
{
	++elem_count;
	DLLNode<T> *newNode = new DLLNode<T>;

	newNode->info = elem;
	newNode->next = currentNode->next;
	newNode->prev = currentNode;

	if (currentNode->next == NULL)
		tail = newNode;

	currentNode->next = newNode;
}

template <class T>
void DLL<T>::insertPosition(size_t position, T elem)
{
	if (position < 0)
		throw std::exception();

	else if (position == 0)
		insertFirst(elem);

	else
	{
		DLLNode<T> *currentNode = head;
		size_t currentPos = 0;

		while (currentPos < position - 1 && currentNode != NULL)
		{
			currentNode = currentNode->next;
			++currentPos;
		}
		if (currentNode != NULL)
			insertAfter(currentNode, elem);
		else
			throw std::exception();
	}
}

template <class T>
T DLL<T>::getPosition(size_t position) const
{
	if (position < 0 || head == NULL)
		throw std::exception();

	else if (position == 0)
	{
		return head->info;
	}
	else
	{
		DLLNode<T> *currentNode = head;
		size_t currentPos = 0;

		while (currentPos < position && currentNode != NULL)
		{
			currentNode = currentNode->next;
			++currentPos;
		}
		if (currentNode != NULL)
			return currentNode->info;
		else
			throw std::exception();
	}
}

template <class T>
void DLL<T>::setPosition(size_t position, T elem)
{
	if (position < 0 || head == NULL)
		throw std::exception();

	else if (position == 0)
	{
		head->info = elem;
	}
	else
	{
		DLLNode<T> *currentNode = head;
		size_t currentPos = 0;
		while (currentPos < position && currentNode != NULL)
		{
			currentNode = currentNode->next;
			++currentPos;
		}
		if (currentNode != NULL)
			currentNode->info = elem;
		else
			throw std::exception();
	}
}

template <class T>
DLLNode<T>* DLL<T>::deleteFirst()
{
	--elem_count;
	DLLNode<T> *node_copy;
	if (head->next == NULL)
	{
		node_copy = head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		node_copy = head;
		head = head->next;
		head->prev = NULL;
	}
	return node_copy;
}

template <class T>
DLLNode<T>* DLL<T>::deleteLast()
{
	--elem_count;
	DLLNode<T> *node_copy;
	if (tail->prev == NULL)
	{
		node_copy = tail;
		head = NULL;
		tail = NULL;
	}
	else
	{
		node_copy = tail;
		tail = tail->prev;
		tail->next = NULL;
	}
	return node_copy;
}

template <class T>
DLLNode<T>* DLL<T>::deleteElement(T elem)
{
	DLLNode<T> *currentNode = head;

	while (currentNode != NULL && currentNode->info != elem)
		currentNode = currentNode->next;

	DLLNode<T> *deletedNode = currentNode;

	if (currentNode != NULL)
	{

		if (currentNode == head)
			deletedNode = deleteFirst();
		else if (currentNode == tail)
			deletedNode = deleteLast();
		else
		{
			--elem_count;
			currentNode->next->prev = currentNode->prev;
			currentNode->prev->next = currentNode->next;
		}
	}
	return deletedNode;
}

template <class T>
bool DLL<T>::isEmpty() const
{
	return head == NULL;
}

template <class T>
size_t DLL<T>::size() const
{
	return elem_count;
}


template class DLL<int>;
template class DLL<float>;
template class DLL<char>;
template class DLL<std::string>;
template class DLL<std::pair<int, int> >;
