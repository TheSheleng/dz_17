#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Array
{
	T* arr;
	int size;
	int grow;
	int capacity;

	int sRound(int _size, int _grow);

public:
	Array();
	Array(const Array& obj);
	~Array();

	int GetSize();
	void SetSize(int _size, int _grow);
	int GetUpperBound();
	bool IsEmpty();
	void FreeExtra();
	void RemoveAll();
	T GetAt(int i);
	void SetAt(int i, T obj);
	T& operator[] (int i);
	void Add(T obj);
	void Append(const Array& obj);
	Array<T> operator= (const Array& obj);
	const T* const GetData();
	void InsertAt(int i, T obj);
	void RemoveAt(int i);
};

template<typename T>
inline int Array<T>::sRound(int _size, int _grow)
{
	return _size % _grow ? _size + _grow - _size % _grow : _size;
}

template<typename T>
inline Array<T>::Array()
{
	SetSize(5, 5);
}

template<typename T>
inline Array<T>::Array(const Array& obj)
{
	capacity = obj.capacity;
	grow = obj.grow;
	size = obj.size;

	delete[] arr;
	arr = new T[size];
	for (int i = 0; i < capacity; i++)
		arr[i] = obj.arr[i];
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] arr;
}

template<typename T>
inline int Array<T>::GetSize()
{
	return size;
}

template<typename T>
inline void Array<T>::SetSize(int _size, int _grow)
{
	size = sRound(_size, _grow);
	grow = _grow;
	capacity = min(capacity, size);

	T* temp = new T[size];
	for (int i = 0; i < capacity; i++)
		temp[i] = arr[i];

	delete[] arr;
	arr = temp;
}

template<typename T>
inline int Array<T>::GetUpperBound()
{
	return capacity - 1;
}

template<typename T>
inline bool Array<T>::IsEmpty()
{
	return capacity == 0 ? true : false;
}

template<typename T>
inline void Array<T>::FreeExtra()
{
	if (!IsEmpty())
	{
		T* temp = new T[capacity];
		for (int i = 0; i < capacity; i++)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;

		size = capacity;
	}
}

template<typename T>
inline void Array<T>::RemoveAll()
{
	capacity = 0;
}

template<typename T>
inline T Array<T>::GetAt(int i)
{
	return arr[i];
}

template<typename T>
inline void Array<T>::SetAt(int i, T obj)
{
	arr[i] = obj;
}

template<typename T>
inline T& Array<T>::operator[](int i)
{
	if (i >= 0 && i < capacity) return arr[i];
}

template<typename T>
inline void Array<T>::Add(T obj)
{
	if (capacity >= size)
	{
		size += grow;
		T* temp = new T[size];
		for (int i = 0; i < capacity; i++)
			temp[i] = arr[i];
		delete[]arr;
		arr = temp;
	}

	arr[capacity++] = obj;
}

template<typename T>
inline void Array<T>::Append(const Array& obj)
{
	size = sRound(size + obj.size, grow);
	T* temp = new T[size];
	for (int i = 0; i < capacity; i++)
		temp[i] = arr[i];
	for (int i = 0; i < obj.capacity; i++)
		temp[i + capacity] = obj.arr[i];
	delete[] arr;
	arr = temp;
	capacity += obj.capacity;
}

template<typename T>
inline Array<T> Array<T>::operator=(const Array& obj)
{
	if(arr != obj.arr)
	{
		capacity = obj.capacity;
		grow = obj.grow;
		size = obj.size;

		delete[] arr;
		arr = new T[size];
		for (int i = 0; i < capacity; i++)
			arr[i] = obj.arr[i];
	}
	return *this;
}

template<typename T>
inline const T* const Array<T>::GetData()
{
	return arr;
}

template<typename T>
inline void Array<T>::InsertAt(int i, T obj)
{
	if (i >= 0 && i <= capacity)
	{
		if (capacity >= size) size += grow;
		T* temp = new T[size];
		for (int k = 0; k < i; k++)
			temp[k] = arr[k];
		temp[i] = obj;
		for (int k = i ; k < capacity; k++)
			temp[k + 1] = arr[k];
		capacity++;
		delete[]arr;
		arr = temp;
	}
}

template<typename T>
inline void Array<T>::RemoveAt(int i)
{
	if (i >= 0 && i < capacity)
	{
		for (int k = i; k < capacity - 1; k++)
			arr[k] = arr[k + 1];
		capacity--;
	}
}
