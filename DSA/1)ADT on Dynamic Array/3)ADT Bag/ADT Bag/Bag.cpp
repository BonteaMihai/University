#include "Bag.h"

Bag::Bag()
{
	this->elem_count = 0;
}

Bag::~Bag()
{

}

void Bag::add(TElem elem)
{
	for (int index = 0 ; index < elems.size() ; ++index)
		if (elems.getElement(index).first == elem)
		{
			std::pair<TElem, int> aux = elems.getElement(index);
			aux.second++;

			elem_count++;
			elems.setElement(index, aux);
			return;
		}
	
	std::pair<TElem, int> aux = std::make_pair(elem, 1);
	elems.addToEnd(aux);
	
	elem_count++;
}

bool Bag::remove(TElem elem)
{
	for (int index = 0 ; index < elems.size() ; ++index)
		if (elems.getElement(index).first == elem)
		{
			std::pair<TElem, int> aux = elems.getElement(index);
			aux.second--;

			if (aux.second == 0)
				elems.deleteFromPosition(index);
			else
				elems.setElement(index, aux);
			
			elem_count--;
			return true;
		}
	return false;
}

bool Bag::search(TElem elem) const
{
	for (int index = 0; index < elems.size(); ++index)
		if (elems.getElement(index).first == elem)
			return true;
	return false;
	
}

int Bag::nrOccurrences(TElem elem) const
{
	for (int index = 0; index < elems.size(); ++index)
		if (elems.getElement(index).first == elem)
			return elems.getElement(index).second;
	return 0;
}

int Bag::size() const
{
	return elem_count;
}

BagIterator Bag::iterator()
{
	return BagIterator{ *this };
}

bool Bag::isEmpty() const
{
	return elem_count == 0;
}

