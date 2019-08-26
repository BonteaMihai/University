#include "Queue.h"
#include <stdexcept>

template <class T>
Queue<T>::Queue()
{

}

template <class T>
Queue<T>::~Queue()
{

}

template <class T>
void Queue<T>::push(T elem)
{
	elems.insertLast(elem);
}

template <class T>
T Queue<T>::top() const
{
	if (elems.isEmpty())
		throw std::exception();

	return elems.getPosition(0);
}

template <class T>
T Queue<T>::pop()
{
	if (elems.isEmpty())
		throw std::exception();

	DLLNode<T> *head = elems.deleteFirst();
	T value = head->info;
	delete head;
	return value;
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return elems.isEmpty();
}

template class Queue<int>;
template class Queue<float>;
template class Queue<char>;
template class Queue<std::string>;
template class Queue<std::pair<int, int> >;