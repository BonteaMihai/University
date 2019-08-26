#include <iostream>
#include <Windows.h>
#include <cassert>
#include "Queue.h"


void test_basic()
{
	Queue<int> q;
	assert(q.isEmpty() == true);

	for (int index = 1; index < 100; ++index)
		q.push(index);

	assert(q.isEmpty() == false);

	for (int index = 1; index < 100; ++index)
	{
		assert(q.top() == index);
		assert(q.pop() == index);
	}
	assert(q.isEmpty() == true);
}

int main()
{
	test_basic();
	system("pause");
	return 0;
}