#include <iostream>
#include <cassert>
#include <Windows.h>
#include "DLL.h"


using namespace std;

void test_create()
{
	DLL<int> a;
}

void test_search_insertFirst()
{
	DLL<int> a;
	for (int i = 1; i <= 10; ++i)
		a.insertFirst(i);
	for (int i = 1; i <= 10; ++i)
		assert(a.search(i) != NULL);
	for (int i = 11; i <= 20; ++i)
		assert(a.search(i) == NULL);
}

void test_search_insertLast()
{
	DLL<int> a;
	for (int i = 1; i <= 10; ++i)
		a.insertLast(i);
	for (int i = 1; i <= 10; ++i)
		assert(a.search(i) != NULL);
	for (int i = 11; i <= 20; ++i)
		assert(a.search(i) == NULL);
}

void test_search_insertAfter()
{
	DLL<int> a;
	a.insertFirst(1);
	a.insertAfter(a.search(1), 2);
	a.insertAfter(a.search(2), 3);

	assert(a.search(1) != NULL);
	assert(a.search(2) != NULL);
	assert(a.search(3) != NULL);

	assert(a.search(4) == NULL);
}

void test_search_insertPosition()
{
	DLL<int> a;
	a.insertPosition(0, 1);
	assert(a.search(1) != NULL);

	a.insertPosition(1, 2);
	assert(a.search(2) != NULL);

	a.insertPosition(1, 3);

	assert(a.search(1) != NULL);
	assert(a.search(2) != NULL);
	assert(a.search(3) != NULL);
}

void test_getPosition()
{
	DLL<int> a;
	for (int i = 0; i < 10; ++i)
		a.insertLast(i);
	for (int i = 0; i < 10; ++i)
	{
		assert(a.getPosition(i) == i);
	}
}

void test_deleteFirst()
{
	DLL<int> a;
	for (int i = 1; i <= 10; ++i)
		a.insertLast(i);
	for (int i = 1; i <= 10; ++i)
	{
		a.deleteFirst();
		assert(a.search(i) == NULL);
		for (int j = i + 1; j <= 10; ++j)
			assert(a.search(j) != NULL);
	}
	for (int i = 1; i <= 10; ++i)
		assert(a.search(i) == NULL);
}

void test_deleteLast()
{
	DLL<int> a;
	for (int i = 1; i <= 10; ++i)
		a.insertLast(i);

	for (int i = 10; i >= 1; --i)
	{
		a.deleteLast();
		assert(a.search(i) == NULL);
		for (int j = 1; j < i; ++j)
			assert(a.search(j) != NULL);
	}

}

void test_deleteElement()
{
	DLL <int> a;
	for (int i = 1; i <= 10; ++i)
		a.insertLast(i);
	a.deleteElement(5);
	assert(a.search(5) == NULL);
	for (int i = 1; i <= 10; ++i)
		if (i != 5)
			assert(a.search(i) != NULL);

}

void test_isEmpty()
{
	DLL<int>a;
	assert(a.isEmpty());
	a.insertFirst(1);
	assert(!a.isEmpty());
}

void test_size()
{
	DLL<int> a;
	assert(a.size() == 0);
	for (int i = 1; i <= 10; ++i)
		a.insertFirst(i);
	assert(a.size() == 10);

	DLL<int> b;
	b.insertLast(1);
	assert(b.size() == 1);
}

void test_setPosition()
{
	DLL<int> a;
	for (int i = 0; i < 9; ++i)
		a.insertLast(i);
	for (int i = 0; i < 9; ++i)
		a.setPosition(i, 10);

	for (int i = 0; i < 9; ++i)
		assert(a.search(i) == NULL);
	assert(a.search(10) != NULL);
}

int main()
{
	test_create();
	test_search_insertFirst();
	test_search_insertLast();
	test_search_insertAfter();
	test_search_insertPosition();
	test_getPosition();
	test_deleteFirst();
	test_deleteLast();
	test_deleteElement();
	test_isEmpty();
	test_size();
	test_setPosition();
	system("pause");
	return 0;
}