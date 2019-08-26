#include <iostream>
#include "DynArray.h"
#include <Windows.h>
#include <cassert>

using namespace std; 

void test_basic()
{
	Array<int> array;
	for (int i = 0; i < 1000; ++i)
		array.addToEnd(i);

	for (int i = 0; i < array.size(); ++i)
		assert(array.getElement(i) == i);

	assert(array.size() == 1000);
	assert(array.isEmpty() == false);
}

int main()
{
	test_basic();

	system("pause");
	return 0;
}