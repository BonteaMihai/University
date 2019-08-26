#include <iostream>
#include <cassert>
#include "DLL.h"
#include "DLLIterator.h"

void test_forward()
{
	DLL<int> dll;
	DLLIterator<int> it = dll.iterator();
	assert(it.valid() == false);

	for (int index = 1; index <= 50; ++index)
	{
		dll.insertLast(index);
	}

	it.first();
	for (int index = 1; index <= 50; ++index)
	{
		assert(it.valid() == true);
		assert(it.getCurrent()->info == index);
		it.next();
	}
	assert(it.valid() == false);
}

void test_backward()
{
	DLL<int> dll;
	DLLIterator<int> it = dll.iterator();
	assert(it.valid() == false);

	for (int index = 1; index <= 50; ++index)
	{
		dll.insertFirst(index);
	}

	it.last();
	for (int index = 1; index <= 50; ++index)
	{
		assert(it.valid() == true);
		assert(it.getCurrent()->info == index);
		it.prev();
	}
	assert(it.valid() == false);
}

int main()
{
	test_forward();
	test_backward();
	std::cout << "Tests passed!\n";
	system("pause");
}