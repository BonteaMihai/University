#include "SortedSetIterator.h"

SortedSetIterator::SortedSetIterator(SortedSet &sset) : sset{ sset },
												current_position{ 0 }
{

}

void SortedSetIterator::first()
{
	current_position = 0;
}

void SortedSetIterator::next()
{
	if (!valid())
		throw std::runtime_error("error");

	current_position++;
}

bool SortedSetIterator::valid() const
{
	return 0 <= current_position && current_position < sset.elems.size();
}

TElem SortedSetIterator::getCurrent()
{
	return sset.elems.getElement(current_position);
}