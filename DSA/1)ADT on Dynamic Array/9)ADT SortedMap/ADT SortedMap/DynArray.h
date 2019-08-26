#ifndef  ARRAY_H_
#define ARRAY_H_

#include <iostream>

template <class T>
class Array
{
public:
	Array();
	~Array();

	size_t size() const;
	/*
		Description: returns the size(number of elements) of the DynamicArray
		Best Case = Worst Case = Average Case = theta(1)
	*/

	T getElement(size_t index) const;
	/*
		Description: returns the element from a position from the DynamicArray
		pre: 0 <= index < len
		throws: an exception if index is not a valid position
		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: O(n)
	*/

	T setElement(size_t index, T value);
	/*
		Description: changes the element from a position to another value
		pre: 0 <= index < len
		throws: an exception if index is not a valid position
		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: O(n)
	*/

	void addToEnd(T value);
	/*
		Description: adds an element to the end of the DynamicArray
					 If the array is full, it will be resized
		Best Case = Worst Case = Average Case = theta(1)
		-if it exceeds the capacity, the complexity of resize() is added
	*/

	void addToPosition(size_t index, T value);
	/*
		Description: adds an element to a given position in the DynamicArray
					 If the array is full, it will be resized
		pre: 0 <= index <= len(len is a valid position when adding a new element)
		throws: an exception if index is not a valid position
		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: O(n)
		-if it exceeds the capacity, the complexity of resize() is added
	*/

	T deleteFromPosition(size_t index);
	/*
		Description: deletes an element from a given position from the DynamicArray
					 Retuns the deleted element
		pre: 0 <= index < len
		throws: an exception if index is not a valid position
		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: O(n)
	*/

	void deleteAll();
	/*
		Description: deletes all the elements from the DynamicArray

		Best Case = Worst Case = Average Case = theta(1)
	*/

	bool isEmpty() const;
	/*
		Description: retuns true if the DynamicArray is empty, false otherwise
		Best Case = Worst Case = Average Case = theta(1)
	*/

	void deleteElement(T value);
	/*
		Description: deletes a given element from the DynamicArray
		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: O(n)
	*/

	bool doesElementAppear(T value) const;
	/*
		Description: returns true if the given element appears in the DynamicArray,
					 false otherwise
		Best Case: theta(1)
		Worst Case: theta(n)
		Average Case: O(n)
	*/

	T removeFromEnd();
	/*
		Description: removes the last element in the DynamicArray
		pre: the DynamicArray is not empty
		throws: exception if the DynamicArray is empty
		Best Case = Worst Case = Average Case = theta(1)
	*/
private:
	size_t m_size;
	size_t m_capacity;
	T * m_data;
	void resize();
	/*
		Description: increases the capacity of the DynamicArray
		Best Case = Worst Case = Average Case ~ theta(n)
	*/
};


#endif 