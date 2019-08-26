#pragma once
#define CAPACITY 100
#define GROWTH_FACTOR 2

typedef int TElem;

class Queue
{
private:

	/*representation of Queue*/

	int capacity;
	TElem *elems;

	int rear, front;

	void resize();
	/*
		Description: increases the capacity of the queue
					 and straightens it if needed

		Best Case = Worst Case = Average Case ~ theta(n)
	*/

public:

	Queue();

	void push(TElem elem);
	/*
		Description: pushes an element to the end of the queue

		Best Case = Worst Case = Average Case = theta(1)
		-if it exceeds the capacity, the complexity of resize() is added
	*/

	TElem top() const;
	/*
		Description: returns the element from the front of the queue
		throws: exception if the queue is empty

		Best Case = Worst Case = Average Case = theta(1)
	*/

	TElem pop();
	/*
		Description: removes and returns the element from the front of the queue
		throws: exception if the queue is empty

		Best Case = Worst Case = Average Case = theta(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks if the queue is empty

		Best Case = Worst Case = Average Case = theta(1)
	*/

	~Queue();
};
