#pragma once
#include <iostream>
#include <string>

#define BF 26 // Branching Factor: number of distinct characters
			  // in a dictionary

struct NODE
{
	bool is_word;

	int nr_children;
	NODE *children[BF];

	NODE()
	{
		nr_children = 0;
		is_word = false;
		memset(children, 0, sizeof(children));
	}
};

class Trie
{
private:

	NODE *root;
	int nr_words;

	void postorder_delete(NODE *node);
	/*
		Description: recursive function responsible for cleaning up the memory when
					 the destructor is called
	*/

	void add(NODE *node, char *s);
	/*
		Description: recursive function responsible for adding a word to the dictionary

		Best Case = Worst Case = Average Case = O(n) where n is the
		length of the word
	*/

	bool search(NODE *node, char *s) const;
	/*
		Description: recursive function responsible for checking if a word appears in the
					 dictionary

		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
		where n is the length of the word
	*/

	bool remove(NODE *node, char *s);
	/*
		Description: recursive function responsible for removing a word from the
					 dictionary

		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
		where n is the length of the word
	*/

	int common_prefix(NODE *node, char *s, int k) const;
	/*
		Description: recursive function responsible for returning
					 the longest common prefix of the word given and the longest
					 word from the list

		Best Case = O(1)
		Worst Case = O(n)
		Average Case = O(n)
		where n is the length of the word
	*/

public:

	Trie();
	/*
		Description: the constructor of the container
	*/

	~Trie();
	/*
		Description: the destructor of the container
		cleans up the memory
	*/

	void add_wrapper(char *word);
	/*
		Description: adds the given word to the dictionary
					 does nothing if the word is already in the dictionary
		throws: exception if the word contains illegal characters
				legal characters are the letters from a to z, lowercased

		Best Case = Worst Case = Average Case = O(n) where n is the
		length of the word
	*/

	bool search_wrapper(char *word) const;
	/*
		Description: checks whether a word exists in the dictionary
		throws: exception if the word contains illegal characters
				legal characters are the letters from a to z, lowercased


		Best Case = Worst Case = Average Case = O(n) where n is the
		length of the word
	*/

	void remove_wrapper(char *word);
	/*
		Description: removes a word from the dictionary
					 does nothing if the world was already removed
		throws: exception if the word contains illegal characters
				legal characters are the letters from a to z, lowercased


		Best Case = Worst Case = Average Case = O(n) where n is the
		length of the word
	*/

	int common_prefix_wrapper(char *word) const;
	/*
		Description: returns the length of the longest common prefix of the word
					 given and any word from the list
		throws: exception if the word contains illegal characters
				legal characters are the letters from a to z, lowercased

		Best Case = Worst Case = Average Case = O(n) where n is the
		length of the word
	*/

	int size() const;
	/*
		Description: returns the number of words in the dictionary

		Best Case = Worst Case = Average Case = O(1)
	*/

	bool isEmpty() const;
	/*
		Description: checks whether the dictionary is empty or not

		Best Case = Worst Case = Average Case = O(1)
	*/
};