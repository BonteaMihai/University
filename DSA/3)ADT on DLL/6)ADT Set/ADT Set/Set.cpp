#include "Set.h"

Set::Set()
{

}

Set::~Set()
{

}

bool Set::add(TElem elem)
{
	DLLNode<TElem> *elem_p = elems.search(elem);

	// If pointer is NULL, element does not appear in the set
	// It is added, and true is returned
	if (elem_p == NULL)
	{
		elems.insertLast(elem);
		return true;
	}
	// Else, elemt appears, false is returned
	else
		return false;
}

bool Set::remove(TElem elem)
{
	DLLNode<TElem> *elem_p = elems.deleteElement(elem);

	// If pointer is NULL, element does not appear in the set
	// return false
	if (elem_p == NULL)
		return false;
	// Else, return true and delete the pointer
	else
	{
		delete elem_p;
		return true;
	}
}

bool Set::search(TElem elem) const
{
	DLLNode<TElem> *elem_p = elems.search(elem);

	// If pointer is NULL, element does not appear in the set
	// return false
	// Else, return true

	return (elem_p != NULL);
}

int Set::size() const
{
	return elems.size();
}

bool Set::isEmpty() const
{
	return elems.size() == 0;
}

SetIterator Set::iterator()
{
	return SetIterator{ *this };
}