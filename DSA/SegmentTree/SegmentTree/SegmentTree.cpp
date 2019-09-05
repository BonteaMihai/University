#include "SegmentTree.h"

template <class T>
SegmentTree<T>::SegmentTree(bool(*_r)(const T &p1, const T &p2)) : r{ _r }, elems{ nullptr }
{

}

template <class T>
SegmentTree<T>::~SegmentTree()
{
	delete[] elems;
}

template <class T>
void SegmentTree<T>::Read(std::istream &stream)
{
	stream >> segment_len;
	if (elems != nullptr)
	{
		delete[] elems;
	}
	elems = new T[(segment_len + 1) * 4];
	BuildTree(stream, 1, 1, segment_len);
}

template <class T>
void SegmentTree<T>::BuildTree(std::istream &stream, int Node, int Left, int Right)
{
	if (Left == Right)
	{
		stream >> elems[Node];
	}
	else
	{
		int Mid = (Left + Right) / 2;
		BuildTree(stream, 2 * Node, Left, Mid);
		BuildTree(stream, 2 * Node + 1, Mid + 1, Right);
		elems[Node] = r(elems[2 * Node], elems[2 * Node + 1]) ? elems[2 * Node] : elems[2 * Node + 1];
	}
}

template <class T>
void SegmentTree<T>::UpdateTree(int Node, int Left, int Right, int pos, T val)
{
	if (Left == Right)
	{
		elems[Node] = val;
	}
	else
	{
		int Mid = (Left + Right) / 2;
		if (pos <= Mid)
		{
			UpdateTree(2 * Node, Left, Mid, pos, val);
		}
		else
		{
			UpdateTree(2 * Node + 1, Mid + 1, Right, pos, val);
		}
		elems[Node] = r(elems[2 * Node], elems[2 * Node + 1]) ? elems[2 * Node] : elems[2 * Node + 1];
	}
}

template <class T>
void SegmentTree<T>::Update(int pos, T val)
{
	UpdateTree(1, 1, segment_len, pos, val);
}

template <class T>
const T& SegmentTree<T>::QueryTree(int Node, int Left, int Right, int qA, int qB) const
{
	if (qA <= Left && Right <= qB)
		return elems[Node];
	else
	{
		int Mid = (Left + Right) / 2;
		T result1;
		T result2;
		if (qA <= Mid)
		{
			result1 = QueryTree(2 * Node, Left, Mid, qA, qB);
		}
		if (qB > Mid)
		{
			result2 = QueryTree(2 * Node + 1, Mid + 1, Right, qA, qB);
		}

		if (qA <= Mid && qB > Mid)
		{
			return r(result1, result2) ? result1 : result2;
		}
		else if (qA <= Mid)
		{
			return result1;
		}
		else
		{
			return result2;
		}
	}
}

template <class T>
const T& SegmentTree<T>::Query(int qA, int qB) const
{
	return QueryTree(1, 1, segment_len, qA, qB);
}

template class SegmentTree<int>;
template class SegmentTree<float>;
template class SegmentTree<std::string>;