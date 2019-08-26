#include <iostream>
#include <Windows.h>
#include "ShortTest.h"
#include "ExtendedTest.h"

int main()
{
	testAll();
	std::cout << "Passed the short test!\n";

	testAllExtended();
	std::cout << "Passed the extended test!\n";

	system("pause");
	return 0;
}