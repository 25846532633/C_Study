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
		typedef typename RBTree<K, const K, MapKeyofT>::ConstIterator const_iterator;

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

		iterator find(const K& key)
		{
			_t.Find(key);
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret.first->second;
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

	void test_map2()
	{
		map<string, int> m;
		m.insert({ "test",1 });
		m.insert({ "°ÍºÕ",1 });
		m.insert({ "",1 });
		m.insert({ "ÔÂ",3 });

		map<string, int>::iterator it = m.begin();
		++it;
		cout << it->first << ":" << it->second << endl;
		++it;
		cout << it->first << ":" << it->second << endl;
		--it;
		cout << it->first << ":" << it->second << endl;
	}

	void test_map3()
	{
		string arr[] = { "Æ»¹û", "", "Ñ©Àæ", "", "Ñ©Àæ", "Ñ©Àæ", "",
"Ñ©Àæ", "Æ»¹û", "Ñ©Àæ", "Æ»¹û","Ñ©Àæ","Ïã½¶", "Ñ©Àæ","Ïã½¶" };
		map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}
}