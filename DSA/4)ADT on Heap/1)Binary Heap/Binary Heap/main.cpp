#include <iostream>
#include <Windows.h>
#include <cassert>
#include "Heap.h"

bool Max_heap(TPriority p1, TPriority p2)
{
	return p1 <= p2;
}

bool Min_heap(TPriority p1, TPriority p2)
{
	return p1 >= p2;
}

void test_max_heap()
{
	Heap heap = Heap(Max_heap);
	assert(heap.isEmpty() == true);
	assert(heap.size() == 0);

	for (int i = 1; i <= 10; ++i)
	{
		heap.add(std::make_pair(i, i));
		assert(heap.size() == i);
	}
	for (int i = 1; i <= 10; ++i)
	{
		assert(heap.get_root().first == i);
		assert(heap.remove().first == i);
		assert(heap.size() == 10 - i);
	}
	assert(heap.isEmpty() == true);
	assert(heap.size() == 0);
}

void test_min_heap()
{
	Heap heap = Heap(Min_heap);
	assert(heap.isEmpty() == true);
	assert(heap.size() == 0);

	for (int i = 1; i <= 10; ++i)
	{
		heap.add(std::make_pair(i, i));
		assert(heap.size() == i);
	}
	for (int i = 1; i <= 10; ++i)
	{
		assert(heap.get_root().first == 10 - i + 1);
		assert(heap.remove().first == 10 - i + 1);
		assert(heap.size() == 10 - i);
	}
	assert(heap.isEmpty() == true);
	assert(heap.size() == 0);
}

int main()
{
	test_max_heap();

	test_min_heap();

	std::cout << "All tests passed!\n";

	system("pause");
	return 0;
}