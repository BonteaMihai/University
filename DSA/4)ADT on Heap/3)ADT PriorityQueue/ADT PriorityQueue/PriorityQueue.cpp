#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(Relation r) :
	r{ r },
	heap{ TripleHeap(r) }
{
}

PriorityQueue::~PriorityQueue()
{

}

void PriorityQueue::push(TElem e, TPriority p)
{
	Element element;
	element.first = e;
	element.second = p;
	heap.add(element);
}

Element PriorityQueue::top()  const
{
	if (isEmpty())
		throw std::exception();

	return heap.get_root();
}

Element PriorityQueue::pop()
{
	if (isEmpty())
		throw std::exception();
	else
	{
		return heap.remove();
	}
}

bool PriorityQueue::isEmpty() const
{
	return heap.isEmpty();
}

