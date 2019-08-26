#include "BagIterator.h"

BagIterator::BagIterator(Bag &bag) : bag{ bag }, current_position{ 0 }, current_freq{ 1 }
{

}

void BagIterator::first()
{
	current_position = 0;
	current_freq = 1;
}


void BagIterator::next()
{
	if (!valid())
		throw std::runtime_error("error");
	
	int freq = bag.elems.getElement(current_position).second;
	if (current_freq < freq)
	{
		current_freq++;
	}
	else
	{
		current_freq = 1;
		current_position++;
	}
}

bool BagIterator::valid() const
{
	return 0 <= current_position && current_position < bag.elems.size();
}

TElem BagIterator::getCurrent()
{
	return bag.elems.getElement(current_position).first;
}