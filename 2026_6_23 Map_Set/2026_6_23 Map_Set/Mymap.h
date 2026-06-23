#pragma once


namespace bit
{
	template<class K,class V>
	class map
	{
		struct MapKeyofT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::Iterator iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}


		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyofT> _t;
	};

	void test_map()
	{
		map<string, int> m;
		m.insert({ "test",1 });
		m.insert({ "°ÍºÕ",1 });
		m.insert({ "",1 });
		m.insert({ "ÔÂ",3 });

		map<string, int>::iterator it = m.begin();
		while (it != m.end())
		{
			//it->first += 'x';
			it->second += 1;

			//cout << it.operator->()->first << ":" << it->second << endl;
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}