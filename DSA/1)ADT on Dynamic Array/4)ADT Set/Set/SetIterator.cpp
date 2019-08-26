#include "SetIterator.h"

SetIterator::SetIterator(Set &set) : set{ set }, current_position{ 0 }
{

}

void SetIterator::first()
{
	current_position = 0;
}

void SetIterator::next()
{
	if (!valid())
		throw std::runtime_error("error");
	
	current_position++;
}

bool SetIterator::valid() const
{
	return 0 <= current_position && current_position < set.elems.size();
}

TElem SetIterator::getCurrent()
{
	return set.elems.getElement(current_position);
}