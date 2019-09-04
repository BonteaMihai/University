#include "Heap.h"
#include <iostream>
#include <string>

TripleHeap::TripleHeap(Relation r) : r{ r }
{

}

TripleHeap::~TripleHeap()
{

}

void TripleHeap::bubble_up(size_t position)
{
	size_t pos = position;
	Element elem = elems.getElement(position);
	size_t parent = (position - 1) / 2;

	while (pos > 0 && r(elem.second, elems.getElement(parent).second))
	{
		//move parent down
		elems.setElement(pos, elems.getElement(parent));
		pos = parent;
		parent = (pos - 1) / 2;
	}
	elems.setElement(pos, elem);
}

void TripleHeap::add(Element elem)
{
	elems.addToEnd(elem);
	bubble_up(elems.size() - 1);
}

Element TripleHeap::get_root() const
{
	return elems.getElement(0);
}

Element TripleHeap::remove()
{
	if (elems.isEmpty())
		throw std::logic_error("empty heap");
	Element deleted_elem = elems.getElement(0);

	Element aux = elems.removeFromEnd();
	if (elems.size() != 0)
	{
		elems.setElement(0, aux);

		bubble_down(0);
	}

	return deleted_elem;
}


void TripleHeap::bubble_down(size_t position)
{
	size_t pos = position;
	Element elem = elems.getElement(position);

	while (pos < elems.size())
	{
		size_t max_child_pos = -1;

		//it has a left child, assume it's the maximum
		if ((pos * 2 + 1) < elems.size())
			max_child_pos = (pos * 2 + 1);

		//it has a right child, test if it's greater
		if ((pos * 2 + 2) < elems.size() && r(elems.getElement(2 * pos + 2).second, elems.getElement(max_child_pos).second))
			max_child_pos = (pos * 2 + 2);

		if (max_child_pos != -1 && r(elems.getElement(max_child_pos).second, elem.second))
		{
			Element aux = elems.getElement(pos);
			elems.setElement(pos, elems.getElement(max_child_pos));
			pos = max_child_pos;

			elems.setElement(pos, aux);
		}
		else
			break;
	}
}

size_t TripleHeap::size() const
{
	return elems.size();
}

bool TripleHeap::isEmpty() const
{
	return elems.isEmpty();
}