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
	template<class T>
	class less 
	{
	public:
		bool operator()(const T& x, const T& y) {
			return x < y;
		}
	};

	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:
		void adjust_up(size_t child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}


		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;

			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[_con.size() - 1], _con[0]);
			_con.pop_back();
			adjust_down(0);
		}

		bool empty() const { return _con.empty(); }
		size_t size() const { return _con.size(); }
		const T& top() const { return _con[0]; }
	private:
		Container _con;
	};
	void test_priority_queue()
	{
		priority_queue<int> pq;   // ´ó¶Ñ
		pq.push(3);
		pq.push(5);
		pq.push(1);
		pq.push(4);
		pq.push(2);

		while (!pq.empty()) {
			cout << pq.top() << " ";   // 5 4 3 2 1
			pq.pop();
		}
		cout << endl;

		// Ð¡¶Ñ
		priority_queue<int, vector<int>, greater<int>> pq2;
		pq2.push(3);
		pq2.push(5);
		pq2.push(1);
		pq2.push(4);
		pq2.push(2);

		while (!pq2.empty()) {
			cout << pq2.top() << " ";   // 1 2 3 4 5
			pq2.pop();
		}
		cout << endl;
	}
	
}