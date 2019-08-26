#include <iostream>
#include <Windows.h>
#include <cassert>
#include "SLL.h"

void test_basic1()
{
	SLL<int> sll;
	assert(sll.isEmpty() == true);
	assert(sll.size() == 0);

	for (int i = 1; i <= 10; ++i)
	{
		sll.insertFirst(i);
		assert(sll.size() == i);
	}
	assert(sll.isEmpty() == false);

	for (int i = 1; i <= 10; ++i)
	{
		assert(sll.search(i) != NULL);
	}
	assert(sll.search(1000) == NULL);
}

void test_basic2()
{
	SLL<int> sll;
	
	for (int i = 1; i <= 10; ++i)
	{
		sll.insertLast(i);
		assert(sll.size() == i);
	}
	sll.insertPosition(0, 0);
	sll.insertPosition(11, 11);

	assert(sll.size() == 12);
	for (int i = 0; i <= 11; ++i)
	{
		assert(sll.search(i) != NULL);
	}
}

void test_basic3()
{
	SLL<int> sll;

	for (int i = 1; i <= 10; ++i)
	{
		sll.insertPosition(i - 1, i);
		assert(sll.size() == i);
	}
	sll.insertPosition(5, 11);

	for (int i = 1; i <= 11; ++i)
	{
		SLLNode<int> *search_result = sll.search(i);
		assert(search_result != NULL);

		delete sll.deleteElement(i);

		search_result = sll.search(i);
		assert(search_result == NULL);
	}
}

void test_basic4()
{
	SLL<int> sll;

	for (int i = 1; i <= 10; ++i)
		sll.insertLast(i);

	delete sll.deleteFirst();
	assert(sll.search(1) == NULL);

	delete sll.deleteLast();
	assert(sll.search(10) == NULL);

	for (int i = 2; i <= 9; ++i)
		assert(sll.search(i) != NULL);
}

void test_basic5()
{
	SLL<int> sll;

	for (int i = 1; i <= 10; ++i)
		sll.insertLast(i);

	for (int i = 1; i <= 10; ++i)
	{
		assert(sll.getPosition(i - 1) == i);
	}
}

int main()
{
	test_basic1();
	test_basic2();
	test_basic3();
	test_basic4();
	test_basic5();
	system("pause");
	return 0;
}