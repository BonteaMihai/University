#pragma once
#include <iostream>
#include <string>

template <class T>
class SegmentTree
{
private:
	T *elems;
	size_t segment_len;
	bool(*r)(const T &p1, const T &p2);

	void BuildTree(std::istream &stream, int Node, int Left, int Right);

	void UpdateTree(int Node, int Left, int Right, int pos, T val);

	const T& QueryTree(int Node, int Left, int Right, int qA, int qB) const;

public:
	//constructor which receives a relation used for comparing
	SegmentTree(bool(*_r)(const T &p1, const T &p2));

	//destructor
	~SegmentTree();

	//wrapper for building the tree from a given stream
	void Read(std::istream &stream);

	//wrapper for UpdateTree function
	void Update(int pos, T val);

	//wrapper for QueryTree function
	const T& Query(int qA, int qB) const;

};