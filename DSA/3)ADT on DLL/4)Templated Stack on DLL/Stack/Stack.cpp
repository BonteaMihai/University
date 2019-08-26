#include "Stack.h"
#include <stdexcept>

template <class T>
Stack<T>::Stack()
{

}

template <class T>
Stack<T>::~Stack()
{

}

template <class T>
void Stack<T>::push(T elem)
{
	elems.insertFirst(elem);
}

template <class T>
T Stack<T>::top() const
{
	if (elems.isEmpty())
		throw std::exception();

	return elems.getPosition(0);
}

template <class T>
T Stack<T>::pop()
{
	if (elems.isEmpty())
		throw std::exception();

	DLLNode<T> *head = elems.deleteFirst();
	T value = head->info;
	delete head;
	return value;
}

template <class T>
bool Stack<T>::isEmpty() const
{
	return elems.isEmpty();
}

template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
template class Stack<std::string>;
template class Stack<std::pair<int, int> >;