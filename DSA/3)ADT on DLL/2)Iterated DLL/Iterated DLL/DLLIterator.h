#pragma once

template<typename T>
class DLL;

template<typename T>
class DLLNode;

template<typename T>
class DLLIterator
{
private:
	friend class DLL<T>;

	DLLIterator(const DLL<T>& container);

	const DLL<T>& container;

	DLLNode<T>* current;

public:

	void first();
	/*
		Description: sets the current element from the iterator to the head
					 of the DLL

		Best Case = Worst Case = Average Case = O(1)
	*/

	void next();
	/*
		Description: moves the current element of the DLL to the next
					 element or makes the iterator invalid if no elements
					 are left

		pre: iterator is valid
		throws: an exception if iterator is not valid
		Best Case = Worst Case = Average Case = O(1)
	*/

	void last();
	/*
		Description: sets the current element from the iterator to the tail
				     of the DLL

		Best Case = Worst Case = Average Case = O(1)

	*/

	void prev();
	/*
		Description: moves the current element of the DLL to the previous
					 element or makes the iterator invalid if no elements
					 are left

		pre: iterator is valid
		throws: an exception if iterator is not valid
		Best Case = Worst Case = Average Case = O(1)
	*/

	bool valid() const;
	/*
		Description: verifies if the iterator is valid

		Best Case = Worst Case = Average Case = O(1)
	*/

	DLLNode<T>* getCurrent() const;
	/*
		Description: returns the current element from the iterator
		pre: iterator is valid
		throws: an exception if iterator is not valid

		Best Case = Worst Case = Average Case = O(1)
	*/

};