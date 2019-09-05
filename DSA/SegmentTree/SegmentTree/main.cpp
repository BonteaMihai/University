#include <fstream>
#include <Windows.h>
#include "SegmentTree.h"

bool Ascending(const int &p1, const int &p2)
{
	return p1 <= p2;
}

int main()
{
	std::ifstream fin("file.in");
	SegmentTree<int> it(Ascending); //will store the minimum of the intervals
	it.Read(fin);

	int query_nr, type, a, b;
	fin >> query_nr;

	while (query_nr)
	{
		fin >> type >> a >> b;
		if (type == 1) // Query
		{
			std::cout << it.Query(a, b) << std::endl;
		}
		else //Update
		{
			it.Update(a, b);
		}
		--query_nr;
	}
	system("pause");
	return 0;
}