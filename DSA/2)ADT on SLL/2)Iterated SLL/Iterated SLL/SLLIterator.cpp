#include "SLLIterator.h"
#include "SLL.h"

template<typename T>
SLLIterator<T>::SLLIterator(const SLL<T>& container) :
	container{ container },
	current{ container.head }
{

}


template<typename T>
void SLLIterator<T>::first()
{
	current = container.head;
}

template<typename T>
void SLLIterator<T>::next()
{
	if (!valid())
	{
		throw std::exception("Invalid iterator!");
	}
	current = current->next;
}

template<typename T>
bool SLLIterator<T>::valid() const
{
	return current != nullptr;
}

template<typename T>
SLLNode<T>* SLLIterator<T>::getCurrent() const
{
	if (!valid())
	{
		throw std::exception("Invalid iterator!");
	}
	return current;
}

template class SLLIterator<int>;
template class SLLIterator<float>;
template class SLLIterator<char>;
template class SLLIterator<std::string>;