#include <iostream>
#include <Windows.h>
#include <cassert>
#include "Trie.h"

void test_add_search()
{
	Trie trie;
	assert(trie.isEmpty() == true);
	assert(trie.size() == 0);
	
	char s1[25], s2[25], s3[25], s4[25], s5[25], s6[25];
	strcpy(s1, "reverse");
	trie.add_wrapper(s1);
	trie.add_wrapper(s1);

	strcpy(s2, "transcriptase");
	trie.add_wrapper(s2);
	trie.add_wrapper(s2);

	strcpy(s3, "nucleotide");
	trie.add_wrapper(s3);

	strcpy(s4, "synthesis");
	trie.add_wrapper(s4);

	strcpy(s5, "unrequited");
	trie.add_wrapper(s5);
	
	strcpy(s6, "love");
	trie.add_wrapper(s6);

	assert(trie.isEmpty() == false);
	assert(trie.size() == 6);

	assert(trie.search_wrapper(s1) == true);
	assert(trie.search_wrapper(s2) == true);
	assert(trie.search_wrapper(s3) == true);
	assert(trie.search_wrapper(s4) == true);
	assert(trie.search_wrapper(s5) == true);
	assert(trie.search_wrapper(s6) == true);

	strcpy(s1, "gotterdammerung");
	strcpy(s2, "lebensabschnittpartner");

	assert(trie.search_wrapper(s1) == false);
	assert(trie.search_wrapper(s2) == false);
}

void test_remove()
{
	Trie trie;
	char s1[25], s2[25], s3[25], s4[25], s5[25], s6[25];

	strcpy(s1, "ante");
	strcpy(s2, "antebellum");
	strcpy(s3, "antediluvian");
	strcpy(s4, "anterior");
	strcpy(s5, "antelucan");
	strcpy(s6, "antechamber");

	trie.add_wrapper(s1);
	trie.add_wrapper(s2);
	trie.add_wrapper(s3);
	trie.add_wrapper(s4);
	trie.add_wrapper(s5);
	trie.add_wrapper(s6);

	trie.remove_wrapper(s1);
	assert(trie.search_wrapper(s1) == false);
	assert(trie.search_wrapper(s2) == true);
	assert(trie.search_wrapper(s3) == true);
	assert(trie.search_wrapper(s4) == true);
	assert(trie.search_wrapper(s5) == true);
	assert(trie.search_wrapper(s6) == true);
	assert(trie.size() == 5);

	trie.remove_wrapper(s2);
	assert(trie.search_wrapper(s1) == false);
	assert(trie.search_wrapper(s2) == false);
	assert(trie.search_wrapper(s3) == true);
	assert(trie.search_wrapper(s4) == true);
	assert(trie.search_wrapper(s5) == true);
	assert(trie.search_wrapper(s6) == true);
	assert(trie.size() == 4);

	trie.remove_wrapper(s3);
	assert(trie.search_wrapper(s1) == false);
	assert(trie.search_wrapper(s2) == false);
	assert(trie.search_wrapper(s3) == false);
	assert(trie.search_wrapper(s4) == true);
	assert(trie.search_wrapper(s5) == true);
	assert(trie.search_wrapper(s6) == true);
	assert(trie.size() == 3);

	trie.remove_wrapper(s4);
	assert(trie.search_wrapper(s1) == false);
	assert(trie.search_wrapper(s2) == false);
	assert(trie.search_wrapper(s3) == false);
	assert(trie.search_wrapper(s4) == false);
	assert(trie.search_wrapper(s5) == true);
	assert(trie.search_wrapper(s6) == true);
	assert(trie.size() == 2);
	
	trie.remove_wrapper(s5);
	assert(trie.search_wrapper(s1) == false);
	assert(trie.search_wrapper(s2) == false);
	assert(trie.search_wrapper(s3) == false);
	assert(trie.search_wrapper(s4) == false);
	assert(trie.search_wrapper(s5) == false);
	assert(trie.search_wrapper(s6) == true);
	assert(trie.size() == 1);

	trie.remove_wrapper(s6);
	assert(trie.search_wrapper(s1) == false);
	assert(trie.search_wrapper(s2) == false);
	assert(trie.search_wrapper(s3) == false);
	assert(trie.search_wrapper(s4) == false);
	assert(trie.search_wrapper(s5) == false);
	assert(trie.search_wrapper(s6) == false);
	assert(trie.size() == 0);
}

void test_common_prefix()
{
	Trie trie;
	char s1[25], s2[25], s3[25], s4[25], s5[25], s6[25];

	strcpy(s1, "ante");

	strcpy(s2, "antebellum");
	strcpy(s3, "antediluvian");
	strcpy(s4, "anterior");
	strcpy(s5, "antelucan");
	strcpy(s6, "antechamber");

	trie.add_wrapper(s2);
	trie.add_wrapper(s3);
	trie.add_wrapper(s4);
	trie.add_wrapper(s5);
	trie.add_wrapper(s6);

	assert(trie.common_prefix_wrapper(s1) == 4);

	strcpy(s1, "postfix");
	assert(trie.common_prefix_wrapper(s1) == 0);

	strcpy(s1, "antic");
	assert(trie.common_prefix_wrapper(s1) == 3);
}

int main()
{
	test_add_search();
	test_remove();
	test_common_prefix();
	std::cout << "All tests passed!\n";
	system("pause");
	return 0;
}