#pragma once

template<typename T>
class SLL;

template<typename T>
class SLLNode;

template<typename T>
class SLLIterator
{
public:
	void first();
	void next();
	bool valid() const;

	SLLNode<T>* getCurrent() const;
private:
	friend class SLL<T>;

	SLLIterator(const SLL<T>& container);

	const SLL<T>& container;

	SLLNode<T>* current;
};