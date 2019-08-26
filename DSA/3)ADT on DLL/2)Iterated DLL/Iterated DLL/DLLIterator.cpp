#include "DLLIterator.h"
#include "DLL.h"

template<typename T>
DLLIterator<T>::DLLIterator(const DLL<T>& container) :
	container{ container },
	current{ container.head }
{

}


template<typename T>
void DLLIterator<T>::first()
{
	current = container.head;
}

template<typename T>
void DLLIterator<T>::next()
{
	if (!valid())
	{
		throw std::exception("Invalid iterator!");
	}
	current = current->next;
}

template <typename T>
void DLLIterator<T>::last()
{
	current = container.tail;
}

template <typename T>
void DLLIterator<T>::prev()
{
	if (!valid())
	{
		throw std::exception("Invalid iterator!");
	}
	current = current->prev;
}

template<typename T>
bool DLLIterator<T>::valid() const
{
	return current != nullptr;
}

template<typename T>
DLLNode<T>* DLLIterator<T>::getCurrent() const
{
	if (!valid())
	{
		throw std::exception("Invalid iterator!");
	}
	return current;
}

template class DLLIterator<int>;
template class DLLIterator<float>;
template class DLLIterator<char>;
template class DLLIterator<std::string>;