#include "SMIterator.h"

SMIterator::SMIterator(SortedMap &smap) : smap{ smap }, current_position{ 0 }
{

}

void SMIterator::first()
{
	current_position = 0;
}

void SMIterator::next()
{
	if (!valid())
		throw std::runtime_error("error");

	current_position++;
}

bool SMIterator::valid() const
{
	return 0 <= current_position && current_position < smap.size();
}

TElem SMIterator::getCurrent()
{
	return smap.elems.getElement(current_position);
}