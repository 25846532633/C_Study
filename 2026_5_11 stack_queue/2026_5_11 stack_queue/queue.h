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
	template<class T, class Conatainer = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

        size_t size() const
        {
            return _con.size();
        }

        bool empty() const
        {
            return _con.empty();
        }

        T& front()
        {
            return _con.front();
        }

        const T& front() const
        {
            return _con.front();
        }

        T& back()
        {
            return _con.back();
        }

        const T& back() const
        {
            return _con.back();
        }
	private:
		Conatainer _con;
	};
}