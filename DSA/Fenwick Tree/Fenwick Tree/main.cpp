#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cassert>
#include "FenwickTree.h"

void test1()
{
	FenwickTree fw;
	std::ifstream fin("file.in");
	fw.Read(fin);

	assert(fw.Query_wrapper(1, 10) == 170);
	assert(fw.Query_wrapper(5, 7) == 48);
	assert(fw.Query_wrapper(9, 10) == 28);
	assert(fw.Query_wrapper(1, 3) == 48);

	fw.Update(3, 4);
	fw.Update(6, 6);
	fw.Update(10, 1);

	assert(fw.Query_wrapper(1, 10) == 170 + 11);
	assert(fw.Query_wrapper(5, 7) == 48 + 6);
	assert(fw.Query_wrapper(9, 10) == 28 + 1);
	assert(fw.Query_wrapper(1, 3) == 48 + 4);

	assert(fw.Search(1000) == 0);
	assert(fw.Search(52) == 3);
	assert(fw.Search(56) == 4);
	assert(fw.Search(181) == 10);
}

int main()
{
	test1();
	std::cout << "All tests passed!\n";
	system("pause");
	return 0;
}