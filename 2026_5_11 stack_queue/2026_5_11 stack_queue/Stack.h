#pragma once
#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
#include <Queue>
#include <stack>
using namespace std;

namespace bite
{
	template<class T, class Container = std::deque<T>>
	class Stack
	{
	public:
		Stack()
		{}
		Stack(const Container& con)
			: _con(con)
		{}


		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top() const
		{
			return _con.back();
		}
	private:
		Container _con;
	};
}