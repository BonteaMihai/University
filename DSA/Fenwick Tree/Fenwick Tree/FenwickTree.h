#pragma once
#include <iostream>

typedef int TElem;

class FenwickTree
{
private:
	/*
		Though Fenwick trees are trees in concept, they are implemented 
		using a regular array, similar to how heaps/segment trees are implemented
	*/
	TElem *elems;
	unsigned length;

	TElem Query(unsigned position) const;
	/*
		Description: calculates and returns the sum of the elements from
					 position 1(beginning) to position

		Average Case = O(log n)
	*/

public:

	FenwickTree();

	~FenwickTree();

	void Read(std::istream &stream);
	/*
		Description: reads the length of an array, then its elements
		throws: exception if the length is negative or zero

		Best Case = Worst Case = Average Case = O(n)
	*/

	void Update(unsigned position, TElem value);
	/*
		Description: adds the given value to the element found at position
		throws: exception if the position is not valid

		Average Case = O(log n)
	*/
	
	TElem Query_wrapper(unsigned position_a, unsigned position_b) const;
	/*
		Description: returns the sum of the values between position_a
					 and position_b
		throws: exeption if any of the positions is not valid
				position_b must be greater or equal than position_a
		
		Average Case = O(log n)
	*/

	unsigned Search(TElem sum) const;
	/*
		Description: returns the minimum position such that the sum
					 of the first elements until that position is equal to the sum
					that was given, or 0 if no such position exists
	*/

};