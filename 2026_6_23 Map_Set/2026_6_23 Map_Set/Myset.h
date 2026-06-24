#pragma once


namespace bit
{
	template<class K>
	class set
	{
		//仿函数 - 解引用data
		struct SekKeyofT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, const K, SekKeyofT>::Iterator iterator;
		typedef typename RBTree<K, const K, SekKeyofT>::ConstIterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		const_iterator begin()const
		{
			return _t.Begin();
		}

		const_iterator end() const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}

		iterator find(const K& key)
		{
			_t.Find(key);
		}

	private:
		RBTree<K, const K, SekKeyofT> _t;
	};

	void test_set()
	{
		set<int> s;
		s.insert(4);
		s.insert(2);
		s.insert(5);
		s.insert(15);
		s.insert(7);
		s.insert(1);
		s.insert(5);
		s.insert(7);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			//*it += 5;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : s)
		{
			cout << e << endl;
		}
	}
}