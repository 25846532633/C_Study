#pragma once
#include <iostream>
#include <algorithm>

template<class T>
class MyVector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;


	MyVector()
		:_start(nullptr),
		_finish(nullptr),
		_end_of_storage(nullptr)
	{}

	//v(5),V(5,3)
	MyVector(size_t n, const T& val = T())
		:_start(new T[n]),
		_finish(_start + n),
		_end_of_storage(_start + n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = val;
		}
	}

	template<class InputIterator>
	MyVector(InputIterator first, InputIterator last)
	{
		int n = last - first;
		_start = new T[n];
		_finish = _start + n;
		_end_of_storage = _start + n;
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = first[i];
		}
	}

	MyVector(const MyVector<T>& v)
	{
		int n = v.size();
		_start = new T[n];
		_finish = _start + n;
		_end_of_storage = _start + n;

		for (int i = 0; i < n; i++)
		{
			_start[i] = v._start[i];
		}
	}

	MyVector<T>& operator=(MyVector<T> v)
	{
		swap(v);
		return *this;
	}

	~MyVector()
	{
		delete[] _start;
		_start = _finish = _end_of_storage = nullptr;
	}

	// ===== 容量 =====
	size_t size()     const { return _finish - _start; }
	size_t capacity() const { return _end_of_storage - _start; }
	bool empty()      const { return _start == _finish; }
	
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			T* tmp = new T[n];
			size_t sz = size();
			for (size_t i = 0; i < sz; i++)
			{
				tmp[i] = _start[i];
			}

			delete[] _start;
			_start = tmp;
			_finish = _start + sz;
			_end_of_storage = _start + n;
		}
	}

	void resize(size_t n, const T& val = T())
	{
		if (n < size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > capacity())
				reserve(n);

			for (size_t i = size(); i < n; i++)
			{
				_start[i] = val;
			}
			_finish = _start + n;
		}
	}

	// ===== 元素访问 =====
	T& operator[](size_t i) { return _start[i]; }
	const T& operator[](size_t i) const { return _start[i]; }
	T& front() { return *_start; }
	const T& front() const { return *_start; }
	T& back() { return *(_finish - 1); }
	const T& back()  const { return *(_finish - 1); }

	// ===== 迭代器 =====
	iterator begin() { return _start; }
	const_iterator begin() const { return _start; }
	iterator end() { return _finish; }
	const_iterator end()   const { return _finish; }
	
private:
	T* _start;
	T* _finish;
	T* _end_of_storage;
};