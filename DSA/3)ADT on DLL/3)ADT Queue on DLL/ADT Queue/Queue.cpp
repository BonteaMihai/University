#include "Queue.h"
#include <stdexcept>

Queue::Queue()
{

}

Queue::~Queue()
{

}

void Queue::push(TElem elem)
{
	elems.insertLast(elem);
}

TElem Queue::top() const
{
	if (elems.isEmpty())
		throw std::exception();

	return elems.getPosition(0);
}

TElem Queue::pop()
{
	if (elems.isEmpty())
		throw std::exception();

	DLLNode<TElem> *head = elems.deleteFirst();
	TElem value = head->info;
	delete head;
	return value;
}

bool Queue::isEmpty() const
{
	return elems.isEmpty();
}