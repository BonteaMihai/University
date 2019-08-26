#include "SortedBagIterator.h"

SortedBagIterator::SortedBagIterator(SortedBag &sbag) : sbag{ sbag }, current_position{ 0 }, current_freq{ 1 }
{

}

void SortedBagIterator::first()
{
	current_position = 0;
	current_freq = 1;
}


void SortedBagIterator::next()
{
	if (!valid())
		throw std::runtime_error("error");

	int freq = sbag.elems.getElement(current_position).second;
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

bool SortedBagIterator::valid() const
{
	return 0 <= current_position && current_position < sbag.elems.size();
}

TElem SortedBagIterator::getCurrent()
{
	return sbag.elems.getElement(current_position).first;
}