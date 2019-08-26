#include "SLL.h"
#include <stdexcept>

template <class T>
SLL<T>::SLL()
{
	head = tail = NULL;
	elem_count = 0;
}

template <class T>
SLL<T>::~SLL()
{
	SLLNode<T> *current_node = head;
	SLLNode<T> *prev_node = NULL;

	while (current_node != NULL)
	{
		prev_node = current_node;
		current_node = current_node->next;
		delete prev_node;
	}
}

template <class T>
SLLNode<T> * SLL<T>::search(T elem) const
{
	SLLNode<T> *current_node = head;
	while (current_node != NULL && current_node->info != elem)
		current_node = current_node->next;

	return current_node;
}

template <class T>
void SLL<T>::insertFirst(T elem)
{
	++elem_count;
	SLLNode<T> *node = new SLLNode<T>;	// allocated on heap

	node->info = elem;	// set information
	node->next = head;	// set next

	if (head == NULL) //empty list => head == NULL && tail == NULL
		tail = node;

	head = node;
}

template <class T>
void SLL<T>::insertLast(T elem)
{
	++elem_count;
	SLLNode<T> *node = new SLLNode<T>;	// allocated on heap

	node->info = elem;	// set information
	node->next = NULL;	// set next to NULL

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
void SLL<T>::insertAfter(SLLNode<T> *currentNode, T elem)
{
	++elem_count;
	SLLNode<T> *node = new SLLNode<T>;	// allocated on heap

	node->info = elem;
	node->next = currentNode->next;

	if (currentNode->next == NULL)
		tail = node;

	currentNode->next = node;
}

template <class T>
void SLL<T>::insertPosition(int position, T elem)
{
	if (position < 0)
		throw std::exception();

	else if (position == 0)
		insertFirst(elem);

	else if (position == elem_count)
		insertLast(elem);

	else
	{
		SLLNode<T> *currentNode = head;
		int currentPos = 0;

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
T SLL<T>::getPosition(int position) const
{
	if (position < 0 || head == NULL)
		throw std::exception();
	else if (position == 0)
	{
		return head->info;
	}
	else
	{
		SLLNode<T> *currentNode = head;
		int currentPos = 0;

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
void SLL<T>::setPosition(int position, T elem)
{
	if (position < 0 || head == NULL)
		throw std::exception();

	else if (position == 0)
	{
		head->info = elem;
	}
	else
	{
		SLLNode<T> *currentNode = head;
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
SLLNode<T> *SLL<T>::deleteFirst()
{
	SLLNode<T> *node_copy;
	node_copy = head;

	if (!node_copy)
		throw std::exception();

	if (head->next == NULL)
	{
		head = NULL;
		tail = NULL;
	}
	else
		head = head->next;

	--elem_count;
	return node_copy;
}

template <class T>
SLLNode<T> *SLL<T>::deleteLast()
{
	SLLNode<T> *node_copy;
	node_copy = tail;

	if (!node_copy)
		throw std::exception();

	SLLNode<T> *current_node = head;
	SLLNode<T> *prev_node = NULL;

	while (current_node != NULL && current_node != tail)
	{
		prev_node = current_node;
		current_node = current_node->next;
	}

	prev_node->next = NULL;
	tail = prev_node;

	--elem_count;
	return node_copy;
}

template <class T>
SLLNode<T> *SLL<T>::deleteElement(T elem)
{
	if (head->info == elem)
		return deleteFirst();

	if (tail->info == elem)
		return deleteLast();

	SLLNode<T> *current_node = head;
	SLLNode<T> *prev_node = NULL;

	while (current_node != NULL && current_node->info != elem)
	{
		prev_node = current_node;
		current_node = current_node->next;
	}
	SLLNode<T> *deletedNode = current_node;

	if (current_node != NULL)
	{
		prev_node->next = current_node->next;
		--elem_count;
	}
	return deletedNode;
}

template <class T>
bool SLL<T>::isEmpty() const
{
	return elem_count == 0;
}

template <class T>
int SLL<T>::size() const
{
	return elem_count;
}

template class SLL<int>;
template class SLL<float>;
template class SLL<char>;
template class SLL<std::string>;