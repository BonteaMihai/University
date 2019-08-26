#include "DynArray.h"

#include <stdexcept>

#define MIN_CAPACITY 300
#define GROWTH_FACTOR 2

template <class T>
Array<T>::Array()
{
	m_capacity = MIN_CAPACITY;
	m_size = 0;
	m_data = new T[m_capacity];
	if (!m_data)
		throw std::bad_alloc();
}

template <class T>
Array<T>::~Array()
{
	delete[] m_data;
}

template <class T>
size_t Array<T>::size() const
{
	return m_size;
}

template <class T>
T Array<T>::getElement(size_t index) const
{
	if (index < 0 || index >= m_size)
		throw std::exception();
	return m_data[index];
}

template <class T>
T Array<T>::setElement(size_t index, T value)
{
	if (index < 0 || index >= m_size)
		throw std::exception();
	T old_value = m_data[index];
	m_data[index] = value;
	return old_value;
}

template <class T>
void Array<T>::addToEnd(T value)
{
	if (m_size >= m_capacity)
		resize();
	m_data[m_size++] = value;
}

template <class T>
void Array<T>::addToPosition(size_t index, T value)
{
	if (index < 0 || index > m_size)
		throw std::exception();

	if (m_size >= m_capacity)
		resize();
	for (size_t i = m_size; i > index; --i)
		m_data[i] = m_data[i - 1];
	m_data[index] = value;
	m_size++;
}

template <class T>
T Array<T>::deleteFromPosition(size_t index)
{
	if (index < 0 || index >= m_size)
		throw std::exception();

	T value = m_data[index];

	for (size_t i = index; i < m_size; ++i)
		m_data[i] = m_data[i + 1];
	m_size--;
	return value;
}

template <class T>
void Array<T>::deleteAll()
{
	m_size = 0;
}

template <class T>
bool Array<T>::isEmpty() const
{
	return (m_size == 0);
}

template <class T>
void Array<T>::deleteElement(T value)
{
	for (size_t i = 0; i < m_size; ++i)
		if (m_data[i] == value)
		{
			deleteFromPosition(i);
			break;
		}
}

template <class T>
bool Array<T>::doesElementAppear(T value) const
{
	for (size_t i = 0; i < m_size; ++i)
		if (m_data[i] == value)
			return true;
	return false;
}

template <class T>
T Array<T>::removeFromEnd()
{
	if (m_size == 0)
		throw std::exception();

	T value = m_data[m_size - 1];
	m_size--;
	return value;
}

template <class T>
void Array<T>::resize()
{
	size_t capacity = m_capacity * GROWTH_FACTOR;

	T *new_array = new T[capacity];

	if (!new_array)
		throw std::bad_alloc();

	for (int index = 0; index < m_size; ++index)
		new_array[index] = m_data[index];

	delete[] m_data;

	m_data = new_array;
	m_capacity = capacity;
}

template class Array<int>;
template class Array<float>;
template class Array<char>;
template class Array<std::string>;
template class Array < std::pair<int, int> >;