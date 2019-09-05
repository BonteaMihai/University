#include "Trie.h"
#include <ctype.h>
#include <stdexcept>
#define CH (*s - 'a')

Trie::Trie()
{
	root = new NODE();
	nr_words = 0;
}

Trie::~Trie()
{
	postorder_delete(root);
}

void Trie::postorder_delete(NODE *node)
{
	for (unsigned index = 0; index < BF; ++index)
		if (node->children[index] != 0)
			postorder_delete(node->children[index]);
	delete node;
}

void Trie::add_wrapper(char *word)
{
	for (unsigned index = 0; index < strlen(word); ++index)
		if (!isalpha(word[index]))
			throw std::exception();

	add(root, word);
}

void Trie::add(NODE *node, char *s)
{

	if (node->children[CH] == 0)
	{
		node->children[CH] = new NODE;
		node->nr_children++;
	}

	if (*(s + 1) != 0)
	{
		add(node->children[CH], s + 1);
	}
	else
		if (node->is_word != true)
		{
			node->is_word = true;
			nr_words++;
		}
}

bool Trie::search_wrapper(char *word) const
{
	for (unsigned index = 0; index < strlen(word); ++index)
		if (!isalpha(word[index]))
			throw std::exception();

	return search(root, word);
}

bool Trie::search(NODE *node, char *s) const
{
	if (*(s + 1) == 0)
	{
		return (node->is_word);
	}

	if (node->children[CH])
		return search(node->children[CH], s + 1);
	return false;
}

void Trie::remove_wrapper(char *word)
{
	for (unsigned index = 0; index < strlen(word); ++index)
		if (!isalpha(word[index]))
			throw std::exception();

	remove(root, word);
}

bool Trie::remove(NODE *node, char *s)
{
	if (*(s + 1) == 0)
	{
		if (node->is_word)
		{
			node->is_word = false;
			nr_words--;
		}
	}
	else if (remove(node->children[CH], s + 1))
	{
		node->children[CH] = 0;
		node->nr_children--;
	}

	if (node->is_word == false && node->nr_children == 0 && node != root)
	{
		delete node;
		return true;
	}
	return false;
}

int Trie::common_prefix_wrapper(char *word) const
{
	for (unsigned index = 0; index < strlen(word); ++index)
		if (!isalpha(word[index]))
			throw std::exception();
	
	return common_prefix(root, word, 0);
}

int Trie::common_prefix(NODE *node, char *s, int k) const
{
	if (*s == 0 || node->children[CH] == 0)
	{
		return k;
	}
	return common_prefix(node->children[CH], s + 1, k + 1);
}

int Trie::size() const
{
	return nr_words;
}

bool Trie::isEmpty() const
{
	return nr_words == 0;
}