#include "MapIterator.h"

MapIterator::MapIterator(Map &map) : map{ map }, current_position{ 0 }
{

}

void MapIterator::first()
{
	current_position = 0;
}

void MapIterator::next()
{
	if (!valid())
		throw std::runtime_error("error");

	current_position++;
}

bool MapIterator::valid() const
{
	return 0 <= current_position && current_position < map.size();
}

TElem MapIterator::getCurrent()
{
	return map.elems.getElement(current_position);
}