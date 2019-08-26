#include <iostream>
#include "SLL.h"
#include "SLLIterator.h"

int main()
{
	SLL<int> sll;
	sll.insertLast(5);
	sll.insertLast(23);
	sll.insertLast(1);
	sll.insertLast(34);
	sll.insertLast(211);
	SLLIterator<int> it = sll.iterator();
	while (it.valid())
	{
		auto x = it.getCurrent()->info;
		it.next();
	}
	system("pause");
}
