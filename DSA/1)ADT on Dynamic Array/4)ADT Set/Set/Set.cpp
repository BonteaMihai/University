#include "Set.h"

Set::Set()
{

}

Set::~Set()
{

}

bool Set::add(TElem elem)
{
	for (int index = 0; index < elems.size(); ++index)
		if (elems.getElement(index) == elem)
			return false;

	elems.addToEnd(elem);
	return true;
}

bool Set::remove(TElem elem)
{
	for (int index = 0 ; index < elems.size() ; ++index)
		if (elems.getElement(index) == elem)
		{
			elems.deleteFromPosition(index);
			return true;
		}
	return false;
}

bool Set::search(TElem elem) const
{
	for (int index = 0; index < elems.size(); ++index)
		if (elems.getElement(index) == elem)
			return true;
	return false;
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