#include "Queue.h"
#include <stdexcept>

Queue::Queue()
{
	front = rear = -1;
	capacity = CAPACITY;
	elems = new TElem[capacity];
}

Queue::~Queue()
{
	delete[] elems;
}

void Queue::push(TElem elem)
{
	// When rear and front are next to each other, it needs to be resized
	if ((front == 0 && rear == capacity - 1) || (rear == front - 1))
	{
		resize();
		++rear;
		elems[rear] = elem;
	}
	// Queue is empty, insert first element
	else if (front == -1)
	{
		front = rear = 0;
		elems[rear] = elem;
	}
	// There is room at the beginning of the queue
	else if (rear == capacity - 1 && front != 0)
	{
		rear = 0;
		elems[rear] = elem;
	}
	else
	{
		rear++;
		elems[rear] = elem;
	}
}

TElem Queue::top() const
{
	if (front == -1)
		throw std::exception();

	return elems[front];
}

TElem Queue::pop()
{
	if (front == -1)
		throw std::exception();

	TElem data = elems[front];

	if (front == rear)
		front = rear = -1;

	else if (front == capacity - 1)
		front = 0;
	else
		front++;

	return data;
}

bool Queue::isEmpty() const
{
	return front == -1;
}

void Queue::resize()
{
	// Allocate a new array with increased capacity
	int new_capacity = capacity * GROWTH_FACTOR;

	TElem *new_elems = new TElem[new_capacity];

	if (!new_elems)
		throw std::bad_alloc();

	// Simply copying the old elements
	if (front == 0 && rear == capacity - 1)
	{
		for (int index = 0; index < capacity; ++index)
			new_elems[index] = elems[index];
	}
	// 'Straightening' the queue
	else
	{
		// Copying [front, capacity) range
		for (int index = front; index < capacity; ++index)
			new_elems[index - front] = elems[index];

		// Copying [0, rear] range
		for (int index = 0; index <= rear; ++index)
			new_elems[index + (capacity - front)] = elems[index];

	}

	delete[] elems;

	front = 0;
	rear = capacity - 1;

	elems = new_elems;
	capacity = new_capacity;
}