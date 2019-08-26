#include "SetIterator.h"

SetIterator::SetIterator(Set &set) : set{ set }, it{set.elems.iterator()}
{

}

void SetIterator::first()
{
	it.first();
}

void SetIterator::next()
{
	if (!valid())
		throw std::runtime_error("error");

	it.next();
}

bool SetIterator::valid() const
{
	return it.valid();
}

TElem SetIterator::getCurrent()
{
	if (!valid())
		throw std::runtime_error("error");

	return it.getCurrent()->info;
}