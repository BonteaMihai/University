#include <iostream>
#include <Windows.h>
#include <cassert>
#include "Stack.h"

void test_basic()
{
	Stack<int> st;
	assert(st.isEmpty() == true);
	
	for (int index = 100; index >= 1; index--)
	{
		st.push(index);
		assert(st.top() == index);
	}

	assert(st.isEmpty() == false);

	for (int index = 1; index <= 100; ++index)
	{
		assert(st.top() == index);
		assert(st.pop() == index);
	}

	assert(st.isEmpty() == true);
}	


int main()
{
	test_basic();
	system("pause");
	return 0;
}